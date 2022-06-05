from config_ws_connect import ws_public
from func_calculations import get_trade_details
from func_price_calls import get_latest_klines
from config_ws_connect import subs_public
from func_stats import calculate_metrics

# Get latest z_score
def get_latest_z_score():

    # Get latest asset orderbook prices and add dummy price for latest
    orderbook_1 = ws_public.fetch(subs_public[0])
    mid_price_1, _, _ = get_trade_details(orderbook_1)
    orderbook_2 = ws_public.fetch(subs_public[1])
    mid_price_2, _, _ = get_trade_details(orderbook_2)

    # Get latest klines and replace most recent with current price from orderbooks
    series_1, series_2 = get_latest_klines()

    # Get z_score and confirm if hot
    if len(series_1) > 0 and len(series_2) > 0:
        # Replace last kline price with latest orderbook mid price
        series_1 = series_1[:-1]
        series_2 = series_2[:-1]
        series_1.append(mid_price_1)
        series_2.append(mid_price_2)

        # Get latest z_score
        coint_flag, zscore_list = calculate_metrics(series_1, series_2)
        zscore = zscore_list[-1]
        if zscore > 0:
            signal_sign_positive = True
        else:
            signal_sign_positive = False

        # Return results
        return (zscore, signal_sign_positive)

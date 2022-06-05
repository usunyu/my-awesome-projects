from config_bonus_api import stop_loss_fail_safe
from config_bonus_api import ticker_1
from config_bonus_api import rounding_ticker_1
from config_bonus_api import rounding_ticker_2
from config_bonus_api import quantity_rounding_ticker_1
from config_bonus_api import quantity_rounding_ticker_2
import math


# Puts all close prices in an ordered list
def extract_close_prices(prices):
    close_prices = []
    for price_values in prices:
        if math.isnan(price_values["close"]):
            return []
        close_prices.append(price_values["close"])
    return close_prices


# Get trade details and latest price
def get_trade_details(orderbook, direction="Long", capital=0):

    # Set calculation and output variables
    price_rounding = 20
    quantity_rounding = 20
    mid_price = 0
    quantity = 0
    stop_loss = 0
    bid_items_list = []
    ask_items_list = []

    # Get prices, stop loss and quantity
    if orderbook:

        # Set price rounding
        price_rounding = rounding_ticker_1 if orderbook[0]["symbol"] == ticker_1 else rounding_ticker_2
        quantity_rounding = quantity_rounding_ticker_1 if orderbook[0]["symbol"] == ticker_1 else quantity_rounding_ticker_2

        # Organise prices
        for level in orderbook:
            if level["side"] == "Buy":
                bid_items_list.append(float(level["price"]))
            else:
                ask_items_list.append(float(level["price"]))

    # Calculate price, size, stop loss and average liquidity
    if len(ask_items_list) > 0 and len(ask_items_list) > 0:

        # Sort lists
        ask_items_list.sort()
        bid_items_list.sort()
        bid_items_list.reverse()

        # Get nearest ask, nearest bid an orderbook spread
        nearest_ask = ask_items_list[0]
        nearest_bid = bid_items_list[0]
        # mid_price = round((nearest_ask + nearest_bid) / 2, price_rounding)

        # Calculate hard stop loss
        if direction == "Long":
            mid_price = nearest_bid # Placing at Bid has high probability of not being cancelled, but may not fill
            stop_loss = round(mid_price * (1 - stop_loss_fail_safe), price_rounding)
        else:
            mid_price = nearest_ask # Placing at Ask has high probability of not being cancelled, but may not fill
            stop_loss = round(mid_price * (1 + stop_loss_fail_safe), price_rounding)

        # Calculate quantity
        quantity = round(capital / mid_price, quantity_rounding)

    # Output results
    return (mid_price, stop_loss, quantity)

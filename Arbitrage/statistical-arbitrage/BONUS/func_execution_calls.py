from config_bonus_api import session_private
from config_bonus_api import limit_order_basis
from config_ws_connect import ws_public
from func_calculations import get_trade_details

# Set leverage
def set_leverage(ticker):
    try:
        isolation = session_private.cross_isolated_margin_switch(
            symbol=ticker,
            is_isolated=True,
            buy_leverage=1,
            sell_leverage=1
        )
    except Exception as e:
        pass


# Place limit order to long or short or close long or close short
def place_order(ticker, price, quantity, direction, stop_loss, trade_type="Open"):

    # Set variables
    side = "Buy"
    reduce_only = False

    # Structure trade for Opening Long or Short position
    if trade_type == "Open":
        stop_loss = round(stop_loss, 3)
        if direction != "Long":
            side = "Sell"

    # Structure trade for Closing Long or Short position
    if trade_type == "Close":
        stop_loss = False
        reduce_only = True
        if direction == "Long":
            side = "Sell"

    # Place limit or market order
    if limit_order_basis:
        order = session_private.place_active_order(
            symbol=ticker,
            side=side,
            order_type="Limit",
            qty=quantity,
            price=price,
            time_in_force="PostOnly",
            reduce_only=reduce_only,
            close_on_trigger=False,
            stop_loss=stop_loss
        )
    else:
        order = session_private.place_active_order(
            symbol=ticker,
            side=side,
            order_type="Market",
            qty=quantity,
            time_in_force="GoodTillCancel",
            reduce_only=reduce_only,
            close_on_trigger=False,
            stop_loss=stop_loss
        )

    # Return order
    return order


# Initialise execution
def initialise_order_execution(ticker, direction, capital):
    orderbook = ws_public.fetch(f"orderBookL2_25.{ticker}")
    mid_price, stop_loss, quantity = get_trade_details(orderbook, direction, capital)
    order = place_order(ticker, mid_price, quantity, direction, stop_loss)
    if "result" in order.keys():
        if "order_id" in order["result"]:
            return order["result"]["order_id"]
    return 0

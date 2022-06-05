from config_bonus_api import session_private


# Get position information
def place_market_close_order(ticker, side, size):

    session_private.place_active_order(
        symbol=ticker,
        side=side,
        order_type="Market",
        qty=size,
        time_in_force="GoodTillCancel",
        reduce_only=True,
        close_on_trigger=False
    )


# Get P&L Info
def get_closed_pnl_info(ticker):
    pnl = session_private.closed_profit_and_loss(symbol=ticker)
    closed_pnl = 0
    if "ret_msg" in pnl.keys():
        if pnl["ret_msg"] == "OK":
            for item in pnl["result"]["data"]:
                closed_pnl += item["closed_pnl"]
    return closed_pnl


# Get position information
def get_position_info(ticker):
    position = session_private.my_position(symbol=ticker)
    side = 0
    size = ""
    pnl_un = 0
    pos_value = 0
    if "ret_msg" in position.keys():
        if position["ret_msg"] == "OK":
            if len(position["result"]) == 2:
                if position["result"][0]["size"] > 0:
                    size = position["result"][0]["size"]
                    side = "Buy"
                    pnl_un = position["result"][0]["unrealised_pnl"]
                    pos_value = position["result"][0]["position_value"]
                else:
                    size = position["result"][1]["size"]
                    side = "Sell"
                    pnl_un = position["result"][1]["unrealised_pnl"]
                    pos_value = position["result"][1]["position_value"]

    # Return output
    return side, size, pnl_un, pos_value

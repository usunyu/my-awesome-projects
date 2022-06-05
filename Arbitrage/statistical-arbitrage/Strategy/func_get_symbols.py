from config_strategy_api import session

# Get symbols that are tradeable
def get_tradeable_symbols():

    # Get available symbols
    sym_list = []
    symbols = session.query_symbol()
    if "ret_msg" in symbols.keys():
        if symbols["ret_msg"] == "OK":
            symbols = symbols["result"]
            for symbol in symbols:
                if symbol["quote_currency"] == "USDT" and float(symbol["maker_fee"]) < 0 and symbol["status"] == "Trading":
                    sym_list.append(symbol)

    # Return ouput
    return sym_list

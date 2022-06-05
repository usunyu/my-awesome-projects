"""
    API Documentation
    https://bybit-exchange.github.io/docs/linear/#t-introduction
"""

# API Imports
from pybit import HTTP
from pybit import WebSocket

# CONFIG
mode = "test"
timeframe = 60
kline_limit = 200
z_score_window = 21

# LIVE API
api_key_mainnet = ""
api_secret_mainnet = ""

# TEST API
api_key_testnet = "m1SGFz4iwLbmIi9VZX"
api_secret_testnet = "JkoEAojdvRMuUQNVa2Bhn2GhIVtOePRPseO6"

# SELECTED API
api_key = api_key_testnet if mode == "test" else api_key_mainnet
api_secret = api_secret_testnet if mode == "test" else api_secret_mainnet

# SELECTED URL
api_url = "https://api-testnet.bybit.com" if mode == "test" else "https://api.bybit.com"

# SESSION Activation
session = HTTP(api_url)

# # Web Socket Connection
# subs = [
#     "candle.1.BTCUSDT"
# ]
# ws = WebSocket(
#     "wss://stream-testnet.bybit.com/realtime_public",
#     subscriptions=subs
# )
#
# while True:
#     data = ws.fetch(subs[0])
#     if data:
#         print(data)

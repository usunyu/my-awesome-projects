from config_bonus_api import api_key
from config_bonus_api import api_secret
from config_bonus_api import ws_public_url
from config_bonus_api import ws_private_url
from config_bonus_api import ticker_1
from config_bonus_api import ticker_2
from pybit import WebSocket


# Public ws subscriptions
subs_public = [
    f"orderBookL2_25.{ticker_1}",
    f"orderBookL2_25.{ticker_2}"
]


# Public ws connection
ws_public = WebSocket(
    ws_public_url,
    subscriptions=subs_public
)

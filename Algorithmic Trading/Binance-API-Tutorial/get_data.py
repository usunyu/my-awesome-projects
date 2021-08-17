import csv
import config

from binance import Client, ThreadedWebsocketManager, ThreadedDepthCacheManager
client = Client(config.API_KEY, config.API_SECRET)

# get all symbol prices
# prices = client.get_all_tickers()

# for price in prices:
#     print(price)

csvfile = open("2019-2021.csv", "w", newline="")
csvwriter = csv.writer(csvfile, delimiter=",")

# candles = client.get_klines(symbol="BTCUSDT", interval=Client.KLINE_INTERVAL_15MINUTE)
candles = client.get_historical_klines("ETHBTC", Client.KLINE_INTERVAL_30MINUTE, "1 Dec, 2019", "1 Jan, 2021")

for candle in candles:
    # print(candle)
    csvwriter.writerow(candle)

print(len(candles))

csvfile.close()
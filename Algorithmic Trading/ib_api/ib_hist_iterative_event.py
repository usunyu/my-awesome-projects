# -*- coding: utf-8 -*-
"""
IB API - Getting Historical Data iteratively

@author: Mayank Rasu (http://rasuquant.com/wp/)
"""

# Import libraries
from ibapi.client import EClient
from ibapi.wrapper import EWrapper
from ibapi.contract import Contract
import pandas as pd
import threading
import time

class TradeApp(EWrapper, EClient): 
    def __init__(self): 
        EClient.__init__(self, self) 
        self.data = {}
        
    def historicalData(self, reqId, bar):
        print(f'Time: {bar.date}, Open: {bar.open}, Close: {bar.close}')
        if reqId not in self.data:
            self.data[reqId] = [{"Date":bar.date,"Open":bar.open,"High":bar.high,"Low":bar.low,"Close":bar.close,"Volume":bar.volume}]
        else:
            self.data[reqId].append({"Date":bar.date,"Open":bar.open,"High":bar.high,"Low":bar.low,"Close":bar.close,"Volume":bar.volume})


def usTechStk(symbol,sec_type="STK",currency="USD",exchange="ISLAND"):
    contract = Contract()
    contract.symbol = symbol
    contract.secType = sec_type
    contract.currency = currency
    contract.exchange = exchange
    return contract 

def histData(req_num,contract,duration,candle_size):
    """extracts historical data"""
    app.reqHistoricalData(reqId=req_num, 
                          contract=contract,
                          endDateTime='',
                          durationStr=duration,
                          barSizeSetting=candle_size,
                          whatToShow='ADJUSTED_LAST',
                          useRTH=1,
                          formatDate=1,
                          keepUpToDate=0,
                          chartOptions=[])	 # EClient function to request contract details
    
def websocket_con():
    app.run()
    event.wait()
    if event.is_set():
        app.close()

event = threading.Event()
app = TradeApp()
app.connect(host='127.0.0.1', port=7497, clientId=23) #port 4002 for ib gateway paper trading/7497 for TWS paper trading
con_thread = threading.Thread(target=websocket_con)
con_thread.start()

###################storing trade app object in dataframe#######################
def dataDataframe(TradeApp_obj,symbols):
    "returns extracted historical data in dataframe format"
    df_data = {}
    for symbol in symbols:
        df_data[symbol] = pd.DataFrame(TradeApp_obj.data[symbols.index(symbol)])
        df_data[symbol].set_index("Date",inplace=True)
    TradeApp_obj.data = {}
    return df_data

#extract and store historical data in dataframe repetitively
tickers = ["FB","AMZN","INTC"]
starttime = time.time()
timeout = time.time() + 60*2
while time.time() <= timeout:
    for ticker in tickers:
        histData(tickers.index(ticker),usTechStk(ticker),'3600 S', '30 secs')
        time.sleep(4)
    historicalData = dataDataframe(app,tickers)
    time.sleep(30 - ((time.time() - starttime) % 30.0))

event.set()
# -*- coding: utf-8 -*-
"""
IBAPI - Getting historical data (multiple fx pairs)

@author: Mayank Rasu (http://rasuquant.com/wp/)
"""


from ibapi.client import EClient
from ibapi.wrapper import EWrapper
from ibapi.contract import Contract
import threading
import time


class TradingApp(EWrapper, EClient):
    def __init__(self):
        EClient.__init__(self,self)
        
    def historicalData(self, reqId, bar):
        print("HistoricalData. ReqId:", reqId, "BarData.", bar)
        

def websocket_con():
    app.run()
    
app = TradingApp()      
app.connect("127.0.0.1", 7497, clientId=1)

# starting a separate daemon thread to execute the websocket connection
con_thread = threading.Thread(target=websocket_con, daemon=True)
con_thread.start()
time.sleep(1) # some latency added to ensure that the connection is established

#creating object of the Contract class - will be used as a parameter for other function calls
def fxPair(pair,sec_type="CASH",exchange="IDEALPRO"):
    contract = Contract()
    contract.symbol = pair.split("/")[0]
    contract.secType = sec_type
    contract.currency = pair.split("/")[1]
    contract.exchange = exchange
    return contract 

def histData(req_num,contract,duration,candle_size):
    app.reqHistoricalData(reqId=req_num, 
                          contract=contract,
                          endDateTime='',
                          durationStr=duration,
                          barSizeSetting=candle_size,
                          whatToShow='MIDPOINT',
                          useRTH=1,
                          formatDate=1,
                          keepUpToDate=0,
                          chartOptions=[])	 # EClient function to request contract details


tickers = ["EUR/USD","USD/CAD","AUD/NZD","CHF/USD"]
for ticker in tickers:
    histData(tickers.index(ticker),fxPair(ticker),'1 M', '5 mins')
    time.sleep(5)  # some latency added to ensure that the contract details request has been processed


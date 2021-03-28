# -*- coding: utf-8 -*-
"""
IBAPI - placing simple orders

@author: Mayank Rasu (http://rasuquant.com/wp/)
"""


from ibapi.client import EClient
from ibapi.wrapper import EWrapper
from ibapi.contract import Contract
from ibapi.order import Order
import threading
import time


class TradingApp(EWrapper, EClient):
    def __init__(self):
        EClient.__init__(self,self)
        
    def error(self, reqId, errorCode, errorString):
        print("Error {} {} {}".format(reqId,errorCode,errorString))
        
    def nextValidId(self, orderId):
        super().nextValidId(orderId)
        self.nextValidOrderId = orderId
        print("NextValidId:", orderId)

def websocket_con():
    app.run()
    
app = TradingApp()      
app.connect("127.0.0.1", 7497, clientId=1)

# starting a separate daemon thread to execute the websocket connection
con_thread = threading.Thread(target=websocket_con, daemon=True)
con_thread.start()
time.sleep(1) # some latency added to ensure that the connection is established

#creating object of the Contract class - will be used as a parameter for other function calls
contract = Contract()
contract.symbol = "MSFT"
contract.secType = "STK"
contract.currency = "USD"
contract.exchange = "SMART"

#creating object of the Contract class - will be used as a parameter for other function calls
order = Order()
order.action = "BUY"
order.orderType = "LMT"
order.totalQuantity = 1
order.lmtPrice = 180

app.placeOrder(app.nextValidOrderId,contract,order) # EClient function to request contract details
time.sleep(5) # some latency added to ensure that the contract details request has been processed


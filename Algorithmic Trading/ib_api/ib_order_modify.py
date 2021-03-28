# -*- coding: utf-8 -*-
"""
IBAPI - Modifying Orders

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
def usTechStk(symbol,sec_type="STK",currency="USD",exchange="ISLAND"):
    contract = Contract()
    contract.symbol = symbol
    contract.secType = sec_type
    contract.currency = currency
    contract.exchange = exchange
    return contract 

#creating object of the limit order class - will be used as a parameter for other function calls
def limitOrder(direction,quantity,lmt_price):
    order = Order()
    order.action = direction
    order.orderType = "LMT"
    order.totalQuantity = quantity
    order.lmtPrice = lmt_price
    return order


order_id = app.nextValidOrderId
app.placeOrder(order_id,usTechStk("FB"),limitOrder("BUY",1,200)) # EClient function to request contract details
time.sleep(5)
app.cancelOrder(order_id) #This will cancel the order placed in the previous line if still pending

app.reqIds(-1) # Function to trigger nextValidId function
time.sleep(3) #Need to provide some lag for the nextValidId function to be triggered
order_id = app.nextValidOrderId
app.placeOrder(order_id,usTechStk("FB"),limitOrder("BUY",1,190))

time.sleep(5) ## some latency added to ensure that the request has been processed

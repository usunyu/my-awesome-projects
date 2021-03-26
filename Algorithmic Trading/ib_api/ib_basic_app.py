# -*- coding: utf-8 -*-
"""
IBAPI - EClient and EWrapper classes intro

@author: Mayank Rasu (http://rasuquant.com/wp/)
"""

from ibapi.client import EClient
from ibapi.wrapper import EWrapper

class TradingApp(EWrapper, EClient):
    def __init__(self):
        EClient.__init__(self,self)
        
    def error(self, reqId, errorCode, errorString):
        print("Error {} {} {}".format(reqId,errorCode,errorString))

app = TradingApp()      
app.connect("127.0.0.1", 7497, clientId=1)
app.run()
    
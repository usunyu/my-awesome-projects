import warnings
warnings.simplefilter(action="ignore", category=FutureWarning)

from datetime import datetime, timezone
from web3 import Web3
import pandas as pd
import json
import time

# Contract address and ABI details
address_contract = "0x18B2A687610328590Bc8F2e5fEdDe3b582A49cdA"
with open("abi.json", "r") as myFile:
    data = myFile.read()
abi = json.loads(data)

# Provider
rpc_mainnet = "https://bsc-dataseed1.binance.org:443"
w3 = Web3(Web3.HTTPProvider(rpc_mainnet))

# Wallet details - mainnet
account_address_mainnet = "0xb3E075C8e907Ec60Cb2531F9b2F8fF0aE62CAf46"
pk_mainnet = "58075496548b3b3e0de37b21e1597df48312f537d58c930eb292d09eb3b6df44"

# Contract
contract = w3.eth.contract(address=address_contract, abi=abi)

# Current Epoch/Round
current_epoch = contract.functions.currentEpoch().call()

# Initialise variables
lookback = 3000
starting_epoch = current_epoch - lookback
columns = ["epoch", "start_timestamp", "lock_timestamp", "close_timestamp", "lock_price", "close_price", "total_amount",
           "bull_amount", "bear_amount", "bull_ratio", "bear_ratio", "oracle_called"]
df = pd.DataFrame(columns=columns)
counts = 0
for e in range(0, lookback):

    time.sleep(1)
    starting_epoch += 1
    counts += 1
    print(starting_epoch, counts)

    # Get round object
    current_rounds_list = contract.functions.rounds(starting_epoch).call()

    # Name items
    epoch = current_rounds_list[0]
    start_timestamp = current_rounds_list[1]
    lock_timestamp = current_rounds_list[2]
    close_timestamp = current_rounds_list[3]
    lock_price = current_rounds_list[4]
    close_price = current_rounds_list[5]
    lock_oracle_id = current_rounds_list[6]
    close_oracle_id = current_rounds_list[7]
    total_amount = current_rounds_list[8]
    bull_amount = current_rounds_list[9]
    bear_amount = current_rounds_list[10]
    oracle_called = current_rounds_list[13]

    # Calculate Ratio
    total_amount_normal = round(float(Web3.fromWei(total_amount, "ether")), 5)
    bull_amount_normal = round(float(Web3.fromWei(bull_amount, "ether")), 5)
    bear_amount_normal = round(float(Web3.fromWei(bear_amount, "ether")), 5)

    # Ratios
    if bull_amount_normal != 0 and bear_amount_normal != 0:
        bull_ratio = round(bull_amount_normal / bear_amount_normal, 2) + 1
        bear_ratio = round(bear_amount_normal / bull_amount_normal, 2) + 1
    else:
        bull_ratio = 0
        bear_ratio = 0

    row_dict = {
        "epoch": epoch,
        "start_timestamp": start_timestamp,
        "lock_timestamp": lock_timestamp,
        "close_timestamp": close_timestamp,
        "lock_price": lock_price,
        "close_price": close_price,
        "total_amount": total_amount_normal,
        "bull_amount": bull_amount_normal,
        "bear_amount": bear_amount_normal,
        "bull_ratio": bull_ratio,
        "bear_ratio": bear_ratio,
        "oracle_called": oracle_called,
    }

    try:
        df = df.append([row_dict])
        df.to_csv("predictions.csv")
    except:
        print("Did not save")

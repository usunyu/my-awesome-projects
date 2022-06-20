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

# Send a Transaction
def send_tx(side):

    # Variables
    chain_id = 56
    gas = 300000
    gas_price = Web3.toWei("5.5", "gwei")
    send_bnb = 0.01
    amount = Web3.toWei(send_bnb, "ether")

    # Nonce
    nonce = w3.eth.getTransactionCount(account_address_mainnet)

    # Build Transaction - BULL
    if side == "bull":
        tx_build = contract.functions.betBull(current_epoch).buildTransaction({
            "chainId": chain_id,
            "value": amount,
            "gas": gas,
            "gasPrice": gas_price,
            "nonce": nonce
        })

    if side == "bear":
        tx_build = contract.functions.betBear(current_epoch).buildTransaction({
            "chainId": chain_id,
            "value": amount,
            "gas": gas,
            "gasPrice": gas_price,
            "nonce": nonce
        })

    # Sign transaction
    tx_signed = w3.eth.account.signTransaction(tx_build, private_key=pk_mainnet)

    # Send transaction
    sent_tx = w3.eth.sendRawTransaction(tx_signed.rawTransaction)
    print(sent_tx)


def look_to_trade():

    # Current Rounds information
    current_rounds_list = contract.functions.rounds(current_epoch).call()
    lock_timestamp = current_rounds_list[2]
    total_amount = current_rounds_list[8]
    bull_amount = current_rounds_list[9]
    bear_amount = current_rounds_list[10]

    # Get current timestamp
    dt = int(datetime.now(timezone.utc).timestamp())
    time_remaining = lock_timestamp - dt

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

    # Ratios
    print(bull_ratio, bear_ratio)

    # Place trade
    if time_remaining <= 10:
        if bull_ratio > bear_ratio:
            send_tx("bull")
        else:
            send_tx("bear")
        print("done")


def claim_winnings(epoch):

    # Variables
    chain_id = 56
    gas = 300000
    gas_price = Web3.toWei("5.5", "gwei")

    # Nonce
    nonce = w3.eth.getTransactionCount(account_address_mainnet)

    # Caim Winnings
    tx_build = contract.functions.claim([epoch]).buildTransaction({
        "chainId": chain_id,
        "gas": gas,
        "gasPrice": gas_price,
        "nonce": nonce
    })
    print(tx_build)

    # Sign transaction
    tx_signed = w3.eth.account.signTransaction(tx_build, private_key=pk_mainnet)
    print(tx_signed)

    # Send transaction
    sent_tx = w3.eth.sendRawTransaction(tx_signed.rawTransaction)
    print(sent_tx)

claim_winnings(66562)
# look_to_trade()

import json
from web3 import Web3

# Load Web3
w3 = Web3(Web3.HTTPProvider("https://mainnet.infura.io/v3/1f5ae6ccd8324bbdbb9b70972964f527"))

# Load ABI
with open("UniswapABI.json", "r") as json_obj:
    quoter_ABI = json.load(json_obj)

def get_price(factory, amt_in, trade_direction):
    address = factory
    poolContract = w3.contract.Contract(factory)

""" RUN MAIN """
if __name__ == "__main__":

    # Set Limit
    limit = 1
    amount_in = 1

    # Load Surface Rate Arbs
    with open("uniswap_surface_rates.json", "r") as json_obj:
        surface_rates = json.load(json_obj)[0:1]

    # Loop through items
    for surface_arb in surface_rates:
        pair_1_contract_address = surface_arb["poolContract1"]
        pair_2_contract_address = surface_arb["poolContract2"]
        pair_3_contract_address = surface_arb["poolContract3"]
        trade_1_direction = surface_arb["poolDirectionTrade1"]
        trade_2_direction = surface_arb["poolDirectionTrade2"]
        trade_3_direction = surface_arb["poolDirectionTrade3"]

        # Trade 1
        acquired_coin_t1 = get_price(pair_1_contract_address, amount_in, trade_1_direction)




#!/bin/bash
#  DO NOT FORGET TO REPLACE --testnet if you are using --dev

# Starting v1.6 geth the --solc option is NO MORE SUPPORTED :(
    
#  MAKE SURE SOLIDITY Path is Correct
#  On LINUX/MAC you may use $ which solc to find path to the compiler
# geth --rpc --rpcaddr "localhost" --rpcport "8545" --rpcapi "web3,eth,net,personal" --rpccorsdomain "*" --datadir "./data" --solc "c:/Solidity/solc" --testnet 


geth --testnet  --rpc --rpcaddr "localhost" --rpcport "8545" --rpcapi "web3,eth,net,personal" --rpccorsdomain "*" --datadir "./data"  
const { expect, assert } = require("chai");
const { ethers } = require("hardhat");
const { impersonateFundErc20 } = require("../utils/utilities");

const {
  abi,
} = require("../artifacts/contracts/interfaces/IERC20.sol/IERC20.json");

const provider = waffle.provider;

describe("FlashSwap Contract", () => {
  let FLASHSWAP, BORROW_AMOUNT, FUND_AMOUNT, initialFundingHuman, txArbitrage;

  const DECIMALS = 6;

  const USDC_WHALE = "0xcffad3200574698b78f32232aa9d63eabd290703";
  const USDC = "0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48";
  const LINK = "0x514910771AF9Ca656af840dff83E8264EcF986CA";

  const BASE_TOKEN_ADDRESS = USDC;

  const tokenBase = new ethers.Contract(BASE_TOKEN_ADDRESS, abi, provider);

  beforeEach(async () => {
    // Get owner as signer
    [owner] = await ethers.getSigners();

    // Ensure that the WHALE has a balance
    const whale_balance = await provider.getBalance(USDC_WHALE);
    expect(whale_balance).not.equal("0");

    // Deploy smart contract
    const FlashSwap = await ethers.getContractFactory("UniswapCrossFlash");
    FLASHSWAP = await FlashSwap.deploy();
    await FLASHSWAP.deployed();

    // Configure our Borrowing
    const borrowAmountHuman = "1";
    BORROW_AMOUNT = ethers.utils.parseUnits(borrowAmountHuman, DECIMALS);

    // Configure Funding - FOR TESTING ONLY
    initialFundingHuman = "100";
    FUND_AMOUNT = ethers.utils.parseUnits(initialFundingHuman, DECIMALS);

    // Fund our Contract - FOR TESTING ONLY
    await impersonateFundErc20(
      tokenBase,
      USDC_WHALE,
      FLASHSWAP.address,
      initialFundingHuman,
      DECIMALS
    );
  });

  describe("Arbitrage Execution", () => {
    it("ensures the contract is funded", async () => {
      const flashSwapBalance = await FLASHSWAP.getBalanceOfToken(
        BASE_TOKEN_ADDRESS
      );

      const flashSwapBalanceHuman = ethers.utils.formatUnits(
        flashSwapBalance,
        DECIMALS
      );

      expect(Number(flashSwapBalanceHuman)).equal(Number(initialFundingHuman));
    });

    it("executes the arbitrage", async () => {
      txArbitrage = await FLASHSWAP.startArbitrage(
        BASE_TOKEN_ADDRESS,
        BORROW_AMOUNT
      );

      assert(txArbitrage);

      // Print balances
      const contractBalanceUSDC = await FLASHSWAP.getBalanceOfToken(USDC);
      const formattedBalUSDC = Number(
        ethers.utils.formatUnits(contractBalanceUSDC, DECIMALS)
      );
      console.log("Balance of USDC: " + formattedBalUSDC);

      const contractBalanceLINK = await FLASHSWAP.getBalanceOfToken(LINK);
      const formattedBalLINK = Number(
        ethers.utils.formatUnits(contractBalanceLINK, DECIMALS)
      );
      console.log("Balance of LINK: " + formattedBalLINK);
    });

    it("provides GAS output", async () => {
      const txReceipt = await provider.getTransactionReceipt(txArbitrage.hash);
      const effGasPrice = txReceipt.effectiveGasPrice;
      const txGasUsed = txReceipt.gasUsed;
      const gasUsedETH = effGasPrice * txGasUsed;
      console.log(
        "Total Gas USD: " +
          ethers.utils.formatEther(gasUsedETH.toString()) * 2900 // exchange rate today
      );
      expect(gasUsedETH).not.equal(0);
    });
  });
});

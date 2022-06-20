// https://docs.uniswap.org/protocol/reference/deployments
// https://docs.uniswap.org/sdk/guides/creating-a-trade

const { ethers } = require("ethers");

const {
  abi: QuoterABI,
} = require("@uniswap/v3-periphery/artifacts/contracts/lens/Quoter.sol/Quoter.json");

const provider = new ethers.providers.JsonRpcProvider(
  "https://eth-mainnet.alchemyapi.io/v2/cQ2Bb9ZudvJZUA0TjgzVYUOHfgrkYpa8"
);

async function getPrice(addressFrom, addressTo, amountInHuman) {
  const quoterAddress = "0xb27308f9F90D607463bb33eA1BeBb41C27CE5AB6";

  const quoterContract = new ethers.Contract(
    quoterAddress,
    QuoterABI,
    provider
  );

  const amountIn = ethers.utils.parseUnits(amountInHuman, 6);

  const quoteAmountOut = await quoterContract.callStatic.quoteExactInputSingle(
    addressFrom,
    addressTo,
    3000,
    amountIn.toString(),
    0
  );

  // Output the amount
  const amount = ethers.utils.formatUnits(quoteAmountOut.toString(), 18);
  return amount;
}

const main = async () => {
  const addressFrom = "0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48"; // USDC
  const addressTo = "0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2"; // WETH
  const amountInHuman = "2900";

  const amountOut = await getPrice(addressFrom, addressTo, amountInHuman);
  console.log(amountOut);
};

main();

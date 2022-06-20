const { ethers } = require("ethers");

const provider = new ethers.providers.JsonRpcProvider(
  "https://eth-mainnet.alchemyapi.io/v2/cQ2Bb9ZudvJZUA0TjgzVYUOHfgrkYpa8"
);

const addressFactory = "0x1F98431c8aD98523631AE4a59f267346ea31F984";

const abi = [
  "function getPool(address tokenA, address tokenB, uint24 fee) external view returns (address pool)",
];

const contractFactory = new ethers.Contract(addressFactory, abi, provider);

const addressWETH = "0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2";
const addressANKR = "0x8290333ceF9e6D528dD5618Fb97a76f268f3EDD4";

const getPool = async () => {
  const addressPool = await contractFactory.getPool(
    addressWETH,
    addressANKR,
    3000
  );
  console.log(addressPool);
};

getPool();

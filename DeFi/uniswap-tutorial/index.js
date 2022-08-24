const { ChainId, Fetcher, WETH, Route, Trade, TokenAmount, TradeType, Percent } = require('@uniswap/sdk');
const { ethers } = require('ethers');

const chainId = ChainId.MAINNET;
// DAI
const tokenAddress = '0x6B175474E89094C44Da98b954EedeAC495271d0F';
// TODO, remove
const PRIVATE_KEY = '';

const init = async () => {
    const dai = await Fetcher.fetchTokenData(chainId, tokenAddress);
    const weth = WETH[chainId];
    const pair = await Fetcher.fetchPairData(dai, weth);
    const route = new Route([pair], weth);
    console.log('WETH/DAI:', route.midPrice.toSignificant(6));
    console.log('DAI/WETH:', route.midPrice.invert().toSignificant(6));
    const tradeAmount = new TokenAmount(weth, '100000000000000000');
    console.log('ExactAmount:', tradeAmount.toExact());
    const trade = new Trade(route, tradeAmount, TradeType.EXACT_INPUT);
    console.log('ExecutionPrice:', trade.executionPrice.toSignificant(6));
    console.log('NextMidPrice:', trade.nextMidPrice.toSignificant(6));

    const slippageTolerance = new Percent('50', '10000'); // 50 bips, 1 bip = 0.001
    // we buy DAI with WETH, amountOutMin is the min amount of DAI
    const amountOutMin = trade.minimumAmountOut(slippageTolerance).raw;
    const path = [weth.address, dai.address];
    const to = '';
    const deadline = Math.floor(Date.now() / 1000) + 60 * 20;
    const value = trade.inputAmount.raw;

    const provider = ethers.getDefaultProvider('mainnet', {
        infura: 'https://mainnet.infura.io/v3/279dea9633924461af69934dbf2d34a1',
    });

    const signer = new ethers.Wallet(PRIVATE_KEY);
    const account = signer.connect(provider);
    // console.log("Account:", account);
    const uniswap = new ethers.Contract(
        '0x7a250d5630B4cF539739dF2C5dAcb4c659F2488D',
        ['function swapExactETHForTokens(uint amountOutMin, address[] calldata path, address to, uint deadline) external payable returns (uint[] memory amounts)'],
        account
    );
    const tx = await uniswap.swapExactETHForTokens(
        amountOutMin,
        path,
        to,
        deadline,
        { value, gasPrice: 20e9 }
    );
    console.log('Transaction hash:', tx.hash);

    const receipt = await tx.wait();
    console.log('Transaction was mined in block:', receipt.blockNumber);

}

init();
#
# Python Script with Base Class
# for Event-Based Backtesting
#
# Python for Algorithmic Trading
# (c) Dr. Yves J. Hilpisch
# The Python Quants GmbH
#
import numpy as np
import pandas as pd
from pylab import mpl, plt
plt.style.use('seaborn')
mpl.rcParams['font.family'] = 'serif'


class BacktestBase(object):
    ''' Base class for event-based backtesting of trading strategies.
    Attributes
    ==========
    symbol: str
        TR RIC (financial instrument) to be used
    start: str
        start date for data selection
    end: str
        end date for data selection
    amount: float
        amount to be invested either once or per trade
    ftc: float
        fixed transaction costs per trade (buy or sell)
    ptc: float
        proportional transaction costs per trade (buy or sell)
    Methods
    =======
    get_data:
    retrieves and prepares the base data set
    plot_data:
        plots the closing price for the symbol
    get_date_price:
        returns the date and price for the given bar
    print_balance:
        prints out the current (cash) balance
    print_net_wealth:
        prints out the current net wealth
    place_buy_order:
        places a buy order
    place_sell_order:
        places a sell order
    close_out:
        closes out a long or short position
    '''

    def __init__(self, symbol, start, end, amount,
                 ftc=0.0, ptc=0.0, verbose=True):
        self.symbol = symbol
        self.start = start
        self.end = end
        # Stores the initial amount in a private attribute.
        self.initial_amount = amount
        # Sets the starting cash balance value.
        self.amount = amount
        # Defines fixed transaction costs per trade.
        self.ftc = ftc
        # Defines proportional transaction costs per trade.
        self.ptc = ptc
        # Units of the instrument (for example, number of shares) in the portfolio initially.
        self.units = 0
        # Sets the initial position to market neutral.
        self.position = 0
        # Sets the initial number of trades to zero.
        self.trades = 0
        # Sets self.verbose to True to get full output.
        self.verbose = verbose
        self.get_data()

    def get_data(self):
        ''' Retrieves and prepares the data.
        '''
        raw = pd.read_csv('http://hilpisch.com/pyalgo_eikon_eod_data.csv',
                          index_col=0, parse_dates=True).dropna()
        raw = pd.DataFrame(raw[self.symbol])
        raw = raw.loc[self.start:self.end]
        raw.rename(columns={self.symbol: 'price'}, inplace=True)
        raw['return'] = np.log(raw / raw.shift(1))
        self.data = raw.dropna()

    def plot_data(self, cols=None):
        ''' Plots the closing prices for symbol.
        '''
        if cols is None:
            cols = ['price']
        self.data['price'].plot(figsize=(14, 8), title=self.symbol)

    def get_date_price(self, bar):
        ''' Return date and price for bar.
        '''
        date = str(self.data.index[bar])[:10]
        price = self.data.price.iloc[bar]
        return date, price

    def print_balance(self, bar):
        ''' Print out current cash balance info.
        '''
        date, price = self.get_date_price(bar)
        print(f'{date} | current balance {self.amount:.2f}')

    def print_net_wealth(self, bar):
        ''' Print out current cash balance info.
        '''
        date, price = self.get_date_price(bar)
        net_wealth = self.units * price + self.amount
        print(f'{date} | current net wealth {net_wealth:.2f}')

    def place_buy_order(self, bar, units=None, amount=None):
        ''' Place a buy order.
        '''
        # The date and price information for the given bar is retrieved.
        date, price = self.get_date_price(bar)
        # If no value for units is given…
        if units is None:
            # …the number of units is calculated given the value for amount. (Note that one
            # needs to be given.) The calculation does not include transaction costs.
            units = int(amount / price)
        # The current cash balance is reduced by the cash outlays for the units of the
        # instrument to be bought plus the proportional and fixed transaction costs. Note
        # that it is not checked whether there is enough liquidity available or not.
        self.amount -= (units * price) * (1 + self.ptc) + self.ftc
        # The value of self.units is increased by the number of units bought.
        self.units += units
        # This increases the counter for the number of trades by one.
        self.trades += 1
        # If self.verbose is True…
        if self.verbose:
            # …print out information about trade execution…
            print(f'{date} | selling {units} units at {price:.2f}')
            # …the current cash balance…
            self.print_balance(bar)
            # …and the current net wealth.
            self.print_net_wealth(bar)

    def place_sell_order(self, bar, units=None, amount=None):
        ''' Place a sell order.
        '''
        date, price = self.get_date_price(bar)
        if units is None:
            units = int(amount / price)
        # The current cash balance is increased by the proceeds of the sale minus
        # transactions costs.
        self.amount += (units * price) * (1 - self.ptc) - self.ftc
        # The value of self.units is decreased by the number of units sold.
        self.units -= units
        self.trades += 1
        if self.verbose:
            print(f'{date} | selling {units} units at {price:.2f}')
            self.print_balance(bar)
            self.print_net_wealth(bar)

    def close_out(self, bar):
        ''' Closing out a long or short position.
        '''
        date, price = self.get_date_price(bar)
        # No transaction costs are subtracted at the end.
        self.amount += self.units * price
        self.units = 0
        self.trades += 1
        if self.verbose:
            print(f'{date} | inventory {self.units} units at {price:.2f}')
            print('=' * 55)
        # The final balance consists of the current cash balance plus the value of the
        # trading position.
        print('Final balance [$] {:.2f}'.format(self.amount))
        perf = ((self.amount - self.initial_amount) /
                self.initial_amount * 100)
        # This calculates the net performance in percent.
        print('Net Performance [%] {:.2f}'.format(perf))
        print('Trades Executed [#] {:.2f}'.format(self.trades))
        print('=' * 55)


if __name__ == '__main__':
    bb = BacktestBase('AAPL.O', '2010-1-1', '2019-12-31', 10000)
    print(bb.data.info())
    print(bb.data.tail())
    bb.plot_data()

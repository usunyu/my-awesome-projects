from statsmodels.tsa.stattools import coint
from config_bonus_api import z_score_window
import statsmodels.api as sm
import pandas as pd


# Calculate Z-Score
def calculate_zscore(spread):
    df = pd.DataFrame(spread)
    mean = df.rolling(center=False, window=z_score_window).mean()
    std = df.rolling(center=False, window=z_score_window).std()
    x = df.rolling(center=False, window=1).mean()
    df["ZSCORE"] = (x - mean) / std
    return df["ZSCORE"].astype(float).values


# Calculate spread
def calculate_spread(series_1, series_2, hedge_ratio):
    spread = pd.Series(series_1) - (pd.Series(series_2) * hedge_ratio)
    return spread


# Calculate cointegration
def calculate_metrics(series_1, series_2):
  coint_flag = 0
  coint_res = coint(series_1, series_2)
  coint_t = coint_res[0]
  p_value = coint_res[1]
  critical_value = coint_res[2][1]
  model = sm.OLS(series_1, series_2).fit()
  hedge_ratio = model.params[0]
  spread = calculate_spread(series_1, series_2, hedge_ratio)
  zscore_list = calculate_zscore(spread)
  if p_value < 0.05 and coint_t < critical_value:
    coint_flag = 1
  return (coint_flag, zscore_list.tolist())

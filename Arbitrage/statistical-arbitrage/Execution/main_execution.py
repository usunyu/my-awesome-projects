# Remove Pandas Future Warnings
import warnings
warnings.simplefilter(action='ignore', category=FutureWarning)

# General Imports
from config_execution_api import signal_positive_ticker
from config_execution_api import signal_negative_ticker
from func_position_calls import open_position_confirmation
from func_position_calls import active_position_confirmation
from func_trade_management import manage_new_trades
from func_execution_calls import set_leverage
from func_close_positions import close_all_positions
from func_get_zscore import get_latest_zscore
from config_ws_connect import ws_public
from config_ws_connect import subs_public
from func_save_status import save_status
import time

""" RUN STATBOT """
if __name__ == "__main__":

    # Initial printout
    print("StatBot initiated...")

    # Initialise variables
    status_dict = {"message": "starting..."}
    order_long = {}
    order_short = {}
    signal_sign_positive = False
    signal_side = ""
    kill_switch = 0

    # Save status
    save_status(status_dict)

    # Set leverage in case forgotten to do so on the platform
    print("Setting leverage...")
    set_leverage(signal_positive_ticker)
    set_leverage(signal_negative_ticker)

    # Commence bot
    print("Seeking trades...")
    while True:

        # Keep alive
        pinged = ws_public.fetch(subs_public[0])

        # Pause - protect API
        time.sleep(3)

        # Check if open trades already exist
        is_p_ticker_open = open_position_confirmation(signal_positive_ticker)
        is_n_ticker_open = open_position_confirmation(signal_negative_ticker)
        is_p_ticker_active = active_position_confirmation(signal_positive_ticker)
        is_n_ticker_active = active_position_confirmation(signal_negative_ticker)
        checks_all = [is_p_ticker_open, is_n_ticker_open, is_p_ticker_active, is_n_ticker_active]
        is_manage_new_trades = not any(checks_all)

        # Save status
        status_dict["message"] = "Initial checks made..."
        status_dict["checks"] = checks_all
        save_status(status_dict)

        # Check for signal and place new trades
        if is_manage_new_trades and kill_switch == 0:
            status_dict["message"] = "Managing new trades..."
            save_status(status_dict)
            kill_switch, signal_side = manage_new_trades(kill_switch)

        # Managing open kill switch if positions change or should reach 2
        # Check for signal to be false
        if kill_switch == 1:

            # Get and save the latest z-score
            zscore, signal_sign_positive = get_latest_zscore()

            # Close positions
            if signal_side == "positive" and zscore < 0:
                kill_switch = 2
            if signal_side == "negative" and zscore >= 0:
                kill_switch = 2

            # Put back to zero if trades are closed
            if is_manage_new_trades and kill_switch != 2:
                kill_switch = 0

        # Close all active orders and positions
        if kill_switch == 2:
            print("Closing all positions...")
            status_dict["message"] = "Closing existing trades..."
            save_status(status_dict)
            kill_switch = close_all_positions(kill_switch)

            # Sleep for 5 seconds
            time.sleep(5)

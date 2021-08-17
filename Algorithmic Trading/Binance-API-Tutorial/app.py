from flask import Flask, render_template
import config
from binance.client import Client

app = Flask(__name__)

client = Client(config.API_KEY, config.API_SECRET, tld='us')


@app.route("/")
def index():
    title = "CoinView"

    info = client.get_account()

    balances = info['balances']

    return render_template("index.html", title=title, my_balances=balances)


@app.route("/buy")
def buy():
    return "<p>Buy Page</p>"


@app.route("/sell")
def sell():
    return "<p>Sell Page</p>"


@app.route("/settings")
def settings():
    return "<p>Settings Page</p>"

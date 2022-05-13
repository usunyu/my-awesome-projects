# Setting Basic Variables
car = "bmw"
car_owner = "Fred Flinstone"
car_owner_age = 50
owner_annual_mileage = 1001.5
total_miles_covered = car_owner_age * owner_annual_mileage
print(owner_annual_mileage)
print(type(owner_annual_mileage))

# Setting Advanced Variables
cars_list = ["bmw", "audi", "mercedes", "porche"] # List in Python, Array in Javascript
cars_dict = {"car": "bmw"} # Dictionary in Python, Object in Javascript

car1_dict = {
    "car": "bwm",
    "age": 12,
    "usd_value": 32000
}

car2_dict = {
    "car": "audi",
    "age": 2,
    "usd_value": 100000
}

car3_dict = {
    "car": "mercedes",
    "age": 25,
    "usd_value": 23500
}

cars_obj_list = [car1_dict, car2_dict, car3_dict]

# Access List Information
print(cars_obj_list[1]["usd_value"])

# If statement
if cars_list[0] == "audi":
  print("yes, identified!")
elif cars_list[1] == "mercedes":
  print("Yup, found the merc!")
else:
  print("Nope, try again!")

# If statement breaking up into many
if cars_list[0] == "bmw":
  print("hello bmw")

if cars_list[0] == "audi":
  print("hello audi")

# Turnary if statement
will_purchase = "yes" if cars_list[2] == "porche" else "no"
print(will_purchase)

# Real use case
threshold = 1.5
real_rate = 0.8
if real_rate >= threshold:
  print(real_rate)

# For Loop
cars_obj_list
for item in cars_obj_list:

  # Check car age
  if item["age"] > 5:
    print(item)

# While loop
import time
counts = 0
while True:
  time.sleep(2)
  counts = counts + 1
  print(counts)
  if counts == 5:
    break

# Operations AND and OR
car_age = 30
driver_experience = "Strong"
if car_age <= 30 and driver_experience == "Strong":
  print("Good to go!")
else:
  print("Sorry, no go!")

# Getting data
import requests
import json

# METHOD (AKA FUNCTION)
def get_api_data(url):
  req = requests.get(url)
  if req.status_code == 200:
    return json.loads(req.text)
  else:
    return 0

histprical_prices = get_api_data("https://poloniex.com/public?command=returnChartData&currencyPair=BTC_XMR&start=1546300800&end=1546646400&period=14400")
print(histprical_prices)
order_book = get_api_data("https://poloniex.com/public?command=returnOrderBook&currencyPair=BTC_ETH&depth=10")
print(order_book["bids"])

# Classes in Python
class Car:

  def __init__(self, car_name, car_color):
    self.name = car_name
    self.color = car_color

  def provide_information(self):
    return ("Hello, this car was bought in the year 2002 and is the color " + self.name)

new_car = Car("audi", "blue")
old_car = Car("mercedes", "black")
cool_car = Car("cybertruck", "silver")
description = cool_car.provide_information()
print(description)


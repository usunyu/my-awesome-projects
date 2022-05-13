// Variables
var car = "bmw"
const NewCar = "audi"
let anotherCar = "tesla"
anotherCar = "cybertruck"

// Array (List in Python)
let carArray = ["bmw", "audi", "mercedes", "cybertuck"]

// Object (Dictionary in Python)
let carObject = {
  name: "bmw",
  type: "expensive"
}
carObject["size"] = "large"

// IF Statement
let cars = ["bmw", "audi", "mercedes"];
if (cars[1] == "bmw") {
  console.log("Yes! It is!")
} else {
  console.log("No! It is not!")
}

// For Loop
let cars = ["bmw", "audi", "mercedes"];
let cryptoObj = {coinName: "Bitcoin", price:1000000}
let cryptoObj2 = {coinName: "Ethereum", price:20000000}
let coinArray = [cryptoObj, cryptoObj2]

for (let i=0; i < coinArray.length; i++) {
  console.log(coinArray[i].price)
}

// Function
function coinLoop (coinArray) {
  let returnedArray = []
  for (let i=0; i < coinArray.length; i++) {
    returnedArray.push("My coin is " + coinArray[i])
  }
  return returnedArray
}

let coinsArray = ["Bitcoin", "Ethereum", "Uniswap"];
let myNewArray = coinLoop(coinsArray)
console.log(myNewArray)
coinsArray = ["Pancakeswap", "Chainlink", "Injective"]
myNewArray = coinLoop(coinsArray)
console.log(myNewArray)

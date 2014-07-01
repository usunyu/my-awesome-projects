func greet(name: String, day: String) -> String {
    return "Hello \(name), today is \(day)."
}

greet("Bob", "Tuesday")

func getGasPrices() -> (Double, Double, Double) {
    return (3.59, 3.69, 3.79)
}

getGasPrices()

func sumOf(numbers: Int...) -> Int {
    var sum = 0
    for number in numbers {
        sum += number
    }
    return sum
}
sumOf()
sumOf(42, 597, 12)

func avgOf(numbers: Int...) -> Int {
    var sum = 0
    for number in numbers {
        sum += number
    }
    return sum / numbers.count
}
avgOf(42, 597, 12)

let numbers = [1, 2, 3, 4, 5]
numbers.map({
    (number: Int) -> Int in
    var result = 0
    if(number % 2 == 0) {
        result = 3 * number
    }
    return result
})

numbers.map({ number in 3 * number })

sort([1, 5, 3, 12, 2]) { $0 > $1 }
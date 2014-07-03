func someFunction(parameterName: Int) {
    // function body goes here, and can use parameterName
    // to refer to the argument value for that parameter
}

func someFunction(externalParameterName localParameterName: Int) {
    // function body goes here, and can use localParameterName
    // to refer to the argument value for that parameter
}

func join(s1: String, s2: String, joiner: String) -> String {
    return s1 + joiner + s2
}

join("hello", "world", ", ")
// returns "hello, world"

func join(string s1: String, toString s2: String, withJoiner joiner: String) -> String {
        return s1 + joiner + s2
}

join(string: "hello", toString: "world", withJoiner: ", ")
// returns "hello, world"

func containsCharacter(#string: String, #characterToFind: Character) -> Bool {
    for character in string {
        if character == characterToFind {
            return true
        }
    }
    return false
}

let containsAVee = containsCharacter(string: "aardvark", characterToFind: "v")
// containsAVee equals true, because "aardvark" contains a "v"

func join2(string s1: String, toString s2: String, withJoiner joiner: String = " ") -> String {
        return s1 + joiner + s2
}

join2(string: "hello", toString: "world", withJoiner: "-")
// returns "hello-world"

join2(string: "hello", toString: "world")
// returns "hello world"

func join3(s1: String, s2: String, joiner: String = " ") -> String {
    return s1 + joiner + s2
}

join3("hello", "world", joiner: "-")
// returns "hello-world"

func arithmeticMean(numbers: Double...) -> Double {
    var total: Double = 0
    for number in numbers {
        total += number
    }
    return total / Double(numbers.count)
}
arithmeticMean(1, 2, 3, 4, 5)
// returns 3.0, which is the arithmetic mean of these five numbers
arithmeticMean(3, 8, 19)
// returns 10.0, which is the arithmetic mean of these three numbers

func alignRight(var string: String, count: Int, pad: Character) -> String {
    let amountToPad = count - countElements(string)
    for _ in 1...amountToPad {
        string = pad + string
    }
    return string
}
let originalString = "hello"
let paddedString = alignRight(originalString, 10, "-")
// paddedString is equal to "-----hello"
// originalString is still equal to "hello"

func swapTwoInts(inout a: Int, inout b: Int) {
    let temporaryA = a
    a = b
    b = temporaryA
}

var someInt = 3
var anotherInt = 107
swapTwoInts(&someInt, &anotherInt)
println("someInt is now \(someInt), and anotherInt is now \(anotherInt)")
// prints "someInt is now 107, and anotherInt is now 3

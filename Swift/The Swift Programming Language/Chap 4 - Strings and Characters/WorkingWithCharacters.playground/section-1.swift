for character in "Dog!🐶" {
    println(character)
}
// D
// o
// g
// !
// 🐶

let yenSign: Character = "¥"

//let unusualMenagerie = "Koala 🐨, Snail 🐌, Penguin 🐧, Dromedary 🐪"
//println("unusualMenagerie has \(countElements(unusualMenagerie)) characters")
// prints "unusualMenagerie has 40 characters"

let string1 = "hello"
let string2 = " there"
let character1: Character = "!"
let character2: Character = "?"

let stringPlusCharacter = string1 + character1        // equals "hello!"
let stringPlusString = string1 + string2              // equals "hello there"
let characterPlusString = character1 + string1        // equals "!hello"
let characterPlusCharacter = character1 + character2  // equals "!?"

var instruction = "look over"
instruction += string2
// instruction now equals "look over there"

var welcome = "good morning"
welcome += character1
// welcome now equals "good morning!"
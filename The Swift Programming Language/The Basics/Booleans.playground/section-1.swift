let orangesAreOrange = true
let turnipsAreDelicious = false

if turnipsAreDelicious {
    println("Mmm, tasty turnips!")
} else {
    println("Eww, turnips are horrible.")
}
// prints "Eww, turnips are horrible.

let i = 1
if i {
    // this example will not compile, and will report an error
}

let i = 1
if i == 1 {
    // this example will compile successfully
}
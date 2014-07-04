class SomeClass {
    // class definition goes here
}
struct SomeStructure {
    // structure definition goes here
}

struct Resolution {
    var width = 0
    var height = 0
}
class VideoMode {
    var resolution = Resolution()
    var interlaced = false
    var frameRate = 0.0
    var name: String?
}

let someResolution = Resolution()
let someVideoMode = VideoMode()

println("The width of someResolution is \(someResolution.width)")
// prints "The width of someResolution is 0"

println("The width of someVideoMode is \(someVideoMode.resolution.width)")
// prints "The width of someVideoMode is 0"

someVideoMode.resolution.width = 1280
println("The width of someVideoMode is now \(someVideoMode.resolution.width)")
// prints "The width of someVideoMode is now 1280"

let vga = Resolution(width: 640, height: 480)

let hd = Resolution(width: 1920, height: 1080)
var cinema = hd

cinema.width = 2048

println("cinema is now \(cinema.width) pixels wide")
// prints "cinema is now 2048 pixels wide"

println("hd is still \(hd.width) pixels wide")
// prints "hd is still 1920 pixels wide

enum CompassPoint {
    case North, South, East, West
}
var currentDirection = CompassPoint.West
let rememberedDirection = currentDirection
currentDirection = .East
if rememberedDirection == .West {
    println("The remembered direction is still .West")
}
// prints "The remembered direction is still .West

let tenEighty = VideoMode()
tenEighty.resolution = hd
tenEighty.interlaced = true
tenEighty.name = "1080i"
tenEighty.frameRate = 25.0

let alsoTenEighty = tenEighty
alsoTenEighty.frameRate = 30.0

println("The frameRate property of tenEighty is now \(tenEighty.frameRate)")
// prints "The frameRate property of tenEighty is now 30.0"

if tenEighty === alsoTenEighty {
    println("tenEighty and alsoTenEighty refer to the same Resolution instance.")
}
// prints "tenEighty and alsoTenEighty refer to the same Resolution instance.


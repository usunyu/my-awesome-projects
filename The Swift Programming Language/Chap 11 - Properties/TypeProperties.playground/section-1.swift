struct SomeStructure {
    static var storedTypeProperty = "Some value."
//    static var computedTypeProperty: Int {
//    // return an Int value here
//    }
}
enum SomeEnumeration {
    static var storedTypeProperty = "Some value."
//    static var computedTypeProperty: Int {
//    // return an Int value here
//    }
}
class SomeClass {
    class var computedTypeProperty: Int {
    // return an Int value here
    return 42
    }
}

println(SomeClass.computedTypeProperty)
// prints "42"

println(SomeStructure.storedTypeProperty)
// prints "Some value."
SomeStructure.storedTypeProperty = "Another value."
println(SomeStructure.storedTypeProperty)
// prints "Another value."

struct AudioChannel {
    static let thresholdLevel = 10
    static var maxInputLevelForAllChannels = 0
    var currentLevel: Int = 0 {
    didSet {
        if currentLevel > AudioChannel.thresholdLevel {
            // cap the new audio level to the threshold level
            currentLevel = AudioChannel.thresholdLevel
        }
        if currentLevel > AudioChannel.maxInputLevelForAllChannels {
            // store this as the new overall maximum input level
            AudioChannel.maxInputLevelForAllChannels = currentLevel
        }
    }
    }
}

var leftChannel = AudioChannel()
var rightChannel = AudioChannel()

leftChannel.currentLevel = 7
println(leftChannel.currentLevel)
// prints "7"
println(AudioChannel.maxInputLevelForAllChannels)
// prints "7"

rightChannel.currentLevel = 11
println(rightChannel.currentLevel)
// prints "10"
println(AudioChannel.maxInputLevelForAllChannels)
// prints "10"
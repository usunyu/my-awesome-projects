protocol ExampleProtocol {
    var simpleDescription: String { get }
    mutating func adjust()
}

class SimpleClass: ExampleProtocol {
    var simpleDescription: String = "A very simple class."
    var anotherProperty: Int = 69105
    func adjust() {
        simpleDescription += "  Now 100% adjusted."
    }
}
var a = SimpleClass()
a.adjust()
let aDescription = a.simpleDescription

struct SimpleStructure: ExampleProtocol {
    var simpleDescription: String = "A simple structure"
    mutating func adjust() {
        simpleDescription += " (adjusted)"
    }
}
var b = SimpleStructure()
b.adjust()
let bDescription = b.simpleDescription

enum SimpleEnum: ExampleProtocol {
    case Base, Adjusted
    
    var simpleDescription: String {
    get {
        return self.getDescription()
    }
    }
    
    func getDescription() -> String{
        switch self{
        case .Base:
            return "A simple description of enum"
        case .Adjusted:
            return "Adjusted description of enum"
        default:
            return "default description"
        }
    }
    
    mutating func adjust(){
        self = SimpleEnum.Adjusted
    }
}

extension Int: ExampleProtocol {
    var simpleDescription: String {
    return "The number \(self)"
    }
    mutating func adjust() {
        self += 42
    }
}
7.simpleDescription

extension Double {
    func absoluteValue() -> Double {
        if self < 0 {
            return -self
        }
        else {
            return self
        }
    }
}
var t: Double = -0.3
t.absoluteValue()
(-0.3).absoluteValue()

let protocolValue: ExampleProtocol = a
protocolValue.simpleDescription
// protocolValue.anotherProperty  // Uncomment to see the error”

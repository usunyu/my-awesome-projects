//let tipAndTotal = (4.00, 25.19)

let tipAndTotal:(Double, Double) = (4.00, 25.19)

tipAndTotal.0
tipAndTotal.1

let (theTipAmt, theTotal) = tipAndTotal
theTipAmt
theTotal

//let tipAndTotalNamed = (tipAmt:4.00, total:25.19)
//tipAndTotalNamed.tipAmt
//tipAndTotalNamed.total

let tipAndTotalNamed:(tipAmt:Double, total:Double) = (4.00, 25.19)

let total = 21.19
let taxPct = 0.06
let subtotal = total / (taxPct + 1)
func calcTipWithTipPct(tipPct:Double) -> (tipAmt:Double, total:Double) {
    let tipAmt = subtotal * tipPct
    let finalTotal = total + tipAmt
    return (tipAmt, finalTotal)
}
calcTipWithTipPct(0.20)

import Foundation

class TipCalculatorModel {
    
    var total: Double
    var taxPct: Double
    var subtotal: Double {
    get {
        return total / (taxPct + 1)
    }
    }
    
    init(total:Double, taxPct:Double) {
        self.total = total
        self.taxPct = taxPct
    }
    
    func calcTipWithTipPct(tipPct:Double) -> (tipAmt:Double, total:Double) {
        let tipAmt = subtotal * tipPct
        let finalTotal = total + tipAmt
        return (tipAmt, finalTotal)
    }
    
    func returnPossibleTips() -> Dictionary<Int, (tipAmt:Double, total:Double)> {
        
        let possibleTipsInferred = [0.15, 0.18, 0.20]
        let possibleTipsExplicit:Double[] = [0.15, 0.18, 0.20]
        
        var retval = Dictionary<Int, (tipAmt:Double, total:Double)>()
        for possibleTip in possibleTipsInferred {
            let intPct = Int(possibleTip*100)
            retval[intPct] = calcTipWithTipPct(possibleTip)
        }
        return retval
    }
}

//let tipCalc = TipCalculatorModel(total: 21.19, taxPct: 0.06)
//tipCalc.returnPossibleTips()

// 1
import UIKit
// 2
class TestDataSource : NSObject, UITableViewDataSource {
    
    // 3
    let tipCalc = TipCalculatorModel(total: 33.25, taxPct: 0.06)
    var possibleTips = Dictionary<Int, (tipAmt:Double, total:Double)>()
    var sortedKeys:Int[] = []
    
    // 4
    init() {
        possibleTips = tipCalc.returnPossibleTips()
        sortedKeys = sort(Array(possibleTips.keys))
        super.init()
    }
    
    func tableView(tableView: UITableView!, numberOfRowsInSection section: Int) -> Int {
        return sortedKeys.count
    }
    // 1
    func tableView(tableView: UITableView!, cellForRowAtIndexPath indexPath: NSIndexPath!) -> UITableViewCell! {
        // 2
        let cell = UITableViewCell(style: UITableViewCellStyle.Value2, reuseIdentifier: nil)
        
        // 3
        let tipPct = sortedKeys[indexPath.row]
        // 4
        let tipAmt = possibleTips[tipPct]!.tipAmt
        let total = possibleTips[tipPct]!.total
        
        // 5
        cell.textLabel.text = "\(tipPct)%:"
        cell.detailTextLabel.text = String(format:"Tip: $%0.2f, Total: $%0.2f", tipAmt, total)
        return cell
    }
}

let testDataSource = TestDataSource()
let tableView = UITableView(frame:CGRect(x: 0, y: 0, width: 320, height: 320), style:.Plain)
tableView.dataSource = testDataSource
tableView.reloadData()

//protocol Speaker {
//    func Speak()
//}
//
//class Vicki: Speaker {
//    func Speak() {
//        println("Hello, I am Vicki!")
//    }
//}
//
//class Ray: Speaker {
//    func Speak() {
//        println("Yo, I am Ray!")
//    }
//}
//

@objc protocol Speaker {
    func Speak()
    @optional func TellJoke()
}

class Animal {
}
class Dog : Animal, Speaker {
    func Speak() {
        println("Woof!")
    }
}

class Vicki: Speaker {
    func Speak() {
        println("Hello, I am Vicki!")
    }
    func TellJoke() {
        println("Q: What did Sushi A say to Sushi B?")
    }
}

class Ray: Speaker {
    func Speak() {
        println("Yo, I am Ray!")
    }
    func TellJoke() {
        println("Q: Whats the object-oriented way to become wealthy?")
    }
    func WriteTutorial() {
        println("I'm on it!")
    }
}

var speaker:Speaker
speaker = Ray()
speaker.Speak()
// speaker.WriteTutorial() // error!
(speaker as Ray).WriteTutorial()
speaker = Vicki()
speaker.Speak()

speaker.TellJoke?()
speaker = Dog()
speaker.TellJoke?()

class DateSimulator {
    
    let a:Speaker
    let b:Speaker
    var delegate:DateSimulatorDelegate?
    
    init(a:Speaker, b:Speaker) {
        self.a = a
        self.b = b
    }
    
    func simulate() {
        delegate?.dateSimulatorDidStart(self, a:a, b: b)
        println("Off to dinner...")
        a.Speak()
        b.Speak()
        println("Walking back home...")
        a.TellJoke?()
        b.TellJoke?()
        delegate?.dateSimulatorDidEnd(self, a:a, b: b)
    }
}

protocol DateSimulatorDelegate {
    func dateSimulatorDidStart(sim:DateSimulator, a:Speaker, b:Speaker)
    func dateSimulatorDidEnd(sim:DateSimulator, a: Speaker, b:Speaker)
}

class LoggingDateSimulator:DateSimulatorDelegate {
    func dateSimulatorDidStart(sim:DateSimulator, a:Speaker, b:Speaker) {
        println("Date started!")
    }
    func dateSimulatorDidEnd(sim:DateSimulator, a: Speaker, b: Speaker)  {
        println("Date ended!")
    }
}

var delegate:DateSimulatorDelegate?

let sim = DateSimulator(a:Vicki(), b:Ray())
sim.delegate = LoggingDateSimulator()
sim.simulate()


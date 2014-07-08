//
//  ViewController.swift
//  TipCalculator
//
//  Created by Sun on 7/7/14.
//  Copyright (c) 2014 Sun. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource {
    @IBOutlet var totalTextField : UITextField
    @IBOutlet var taxPctSlider : UISlider
    @IBOutlet var taxPctLabel : UILabel
    @IBOutlet var resultsTextView : UITextView
    @IBOutlet var tableView: UITableView
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        refreshUI()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func calculateTapped(sender : AnyObject) {
        tipCalc.total = Double(totalTextField.text.bridgeToObjectiveC().doubleValue)
        possibleTips = tipCalc.returnPossibleTips()
        sortedKeys = sort(Array(possibleTips.keys))
        tableView.reloadData()
    }
    @IBAction func taxPercentageChanged(sender : AnyObject) {
        tipCalc.taxPct = Double(taxPctSlider.value) / 100.0
        refreshUI()
    }
    @IBAction func viewTapped(sender : AnyObject) {
        totalTextField.resignFirstResponder()
    }
    
    let tipCalc = TipCalculatorModel(total: 33.25, taxPct: 0.06)
    var possibleTips = Dictionary<Int, (tipAmt:Double, total:Double)>()
    var sortedKeys:Int[] = []
    
    func refreshUI() {
        // 1
        totalTextField.text = String(tipCalc.total)
        // 2
        taxPctSlider.value = Float(tipCalc.taxPct) * 100.0
        // 3
        taxPctLabel.text = "Tax Percentage (\(Int(taxPctSlider.value))%)"
        // 4
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



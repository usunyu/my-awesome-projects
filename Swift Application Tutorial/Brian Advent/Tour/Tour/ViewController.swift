//
//  ViewController.swift
//  Tour
//
//  Created by Sun on 7/7/14.
//  Copyright (c) 2014 Sun. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate {
    
    @IBOutlet var tableView: UITableView = UITableView()
    var dataSource:NSMutableArray = NSMutableArray()
    var headView:UIView = UIView()
                            
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        tableView.delegate = self
        tableView.dataSource = self
        
        headView.frame = CGRectMake(0, 0, 320, 200)
        headView.backgroundColor = UIColor.blackColor()
        
        tableView.tableHeaderView = headView
        
        var nameTextField:UITextField = UITextField(frame: CGRectMake(0, 0, 150, 45))
        nameTextField.center = headView.center
        nameTextField.backgroundColor = UIColor.whiteColor()
        nameTextField.textAlignment = NSTextAlignment.Center
        nameTextField.placeholder = "Enter your name"
        nameTextField.delegate = self
        
        headView.addSubview(nameTextField)
    }
    
    func tableView(tableView: UITableView!, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }
    
    func tableView(tableView: UITableView!, cellForRowAtIndexPath indexPath: NSIndexPath!) -> UITableViewCell! {
        let kCellIdentifier:String = "cellIdentifier"
        var cell:UITableViewCell = tableView.dequeueReusableCellWithIdentifier(kCellIdentifier) as UITableViewCell
        
        if(cell == nil) {
            cell = UITableViewCell(style: UITableViewCellStyle.Default, reuseIdentifier: kCellIdentifier)
        }
        
        cell.text = "Hello \(dataSource.objectAtIndex(indexPath.row) as String)"
        
        return cell
    }
    
    func tableView(tableView: UITableView!, didSelectRowAtIndexPath indexPath:NSIndexPath!) {
        var alert:UIAlertController = UIAlertController(title: "Message", message: "Thanks for clicking", preferredStyle: UIAlertControllerStyle.Alert)
        alert.addAction(UIAlertAction(title: "Close AlertView", style: UIAlertActionStyle.Default, handler: nil))
        
        alert.addAction(UIAlertAction(title: "Change header color", style: UIAlertActionStyle.Default, handler: {alertAction in UIView.animateWithDuration(2.5, animations: {self.headView.backgroundColor = UIColor.blueColor()}, completion: {_ in println("Animation complete")})
            }))
        
        self.presentViewController(alert, animated: true, completion: nil)
    }
    
    func textFieldShouldReturn(textField:UITextField!) -> Bool {
        textField.resignFirstResponder()
        dataSource.addObject(textField.text as String)
        tableView.reloadData()
        textField.text = ""
        return true
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}


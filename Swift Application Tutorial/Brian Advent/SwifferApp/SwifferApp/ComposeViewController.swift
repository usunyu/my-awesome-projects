//
//  ComposeViewController.swift
//  SwifferApp
//
//  Created by Sun on 7/10/14.
//  Copyright (c) 2014 Sun. All rights reserved.
//

import UIKit

class ComposeViewController: UIViewController, UITextViewDelegate {
    
    @IBOutlet strong var sweetTextView: UITextView = UITextView()
    @IBOutlet strong var charRemainingLabel: UILabel = UILabel()
    
    init(coder aDecoder: NSCoder!) {
        super.init(coder: aDecoder)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        sweetTextView.layer.borderColor = UIColor.blackColor().CGColor
        sweetTextView.layer.borderWidth = 0.5
        sweetTextView.layer.cornerRadius = 5
        sweetTextView.becomeFirstResponder()
        
        sweetTextView.delegate = self
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func seedSweet(sender: AnyObject) {
        var sweet:PFObject = PFObject(className: "Sweets")
        sweet["content"] = sweetTextView.text
        sweet["sweeter"] = PFUser.currentUser()
        
        sweet.saveInBackground()
        
        self.navigationController.popToRootViewControllerAnimated(true)
    }
    
    func textView(_ textView: UITextView!,
        shouldChangeTextInRange range: NSRange,
        replacementText text: String!) -> Bool {
            var newLength:Int = (textView.text as NSString).length + (text as NSString).length - range.length
            var remainingChar:Int = 140 - newLength
            
            charRemainingLabel.text = "\(remainingChar)"
            
            return (newLength > 140) ? false : true
    }

    /*
    // #pragma mark - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue!, sender: AnyObject!) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}

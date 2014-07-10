//
//  ComposeViewController.swift
//  SwifferApp
//
//  Created by Sun on 7/10/14.
//  Copyright (c) 2014 Sun. All rights reserved.
//

import UIKit

class ComposeViewController: UIViewController {
    
    @IBOutlet strong var sweetTextView: UITextView = UITextView()
    @IBOutlet strong var charRemainingLabel: UILabel = UILabel()
    
    init(coder aDecoder: NSCoder!) {
        super.init(coder: aDecoder)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func seedSweet(sender: AnyObject) {
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

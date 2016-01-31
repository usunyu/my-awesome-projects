//
//  DetailViewController.swift
//  ToDoApp
//
//  Created by Sun on 7/8/14.
//  Copyright (c) 2014 Sun. All rights reserved.
//

import UIKit

class DetailViewController: UIViewController {
    
    @IBOutlet var titleTextField: UITextField = UITextField()
    @IBOutlet var notesTextView: UITextView = UITextView()
    
    var toDoData:NSDictionary = NSDictionary()

    init(coder aDecoder: NSCoder!) {
        super.init(coder: aDecoder)
    }
    
    init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: NSBundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
        // Custom initialization
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        titleTextField.userInteractionEnabled = false
        notesTextView.userInteractionEnabled = false
        
//        titleTextField.text = toDoData.objectForKey("itemTitle") as String
//        notesTextView.text = toDoData.objectForKey("itemNode") as String
    }
    
    @IBAction func deleteItem(sender: AnyObject) {
        var userDefault:NSUserDefaults = NSUserDefaults.standardUserDefaults()
        
        var itemListArray:NSMutableArray = userDefault.objectForKey("itemList") as NSMutableArray
        
        var mutableItemList:NSMutableArray = NSMutableArray()
        
        for dict:AnyObject in itemListArray {
            mutableItemList.addObject(dict as NSDictionary)
        }
        
        mutableItemList.removeObject(toDoData)
        
        userDefault.removeObjectForKey("itemList")
        userDefault.setObject(mutableItemList, forKey: "itemList")
        userDefault.synchronize()
        
        self.navigationController.popToRootViewControllerAnimated(true)
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    /*
    // #pragma mark - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue?, sender: AnyObject?) {
        // Get the new view controller using [segue destinationViewController].
        // Pass the selected object to the new view controller.
    }
    */

}

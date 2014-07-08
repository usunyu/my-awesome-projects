//
//  DemoView.swift
//  InterfaceBuilderAction
//
//  Created by Sun on 7/8/14.
//  Copyright (c) 2014 Sun. All rights reserved.
//

import UIKit

@IBDesignable
class DemoView: UIView {
    
    override func layoutSubviews() {
        super.layoutSubviews()
        
        var label:UILabel = UILabel(frame: CGRectMake(20, 45, 40, 20))
        label.text = "Hello"
        label.textColor = UIColor.greenColor()
        
        self.addSubview(label)
        
        var blur:UIBlurEffect = UIBlurEffect(style: UIBlurEffectStyle.Light)
        var effectView:UIVisualEffectView = UIVisualEffectView(effect: blur)
        
        effectView.frame = CGRectMake(0, 55, 100, 100)
        
        self.addSubview(effectView)
    }
}

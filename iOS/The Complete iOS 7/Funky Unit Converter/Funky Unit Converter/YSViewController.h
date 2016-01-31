//
//  YSViewController.h
//  Funky Unit Converter
//
//  Created by Yu Sun on 8/6/14.
//  Copyright (c) 2014 sunny. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YSViewController : UIViewController

@property (strong, nonatomic) IBOutlet UILabel *numberLabel;
@property (strong, nonatomic) IBOutlet UITextField *numberTextField;
- (IBAction)convertUnits:(UIButton *)sender;

@end

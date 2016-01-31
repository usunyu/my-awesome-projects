//
//  YSViewController.h
//  Age of Laika
//
//  Created by Yu Sun on 8/6/14.
//  Copyright (c) 2014 sunny. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YSViewController : UIViewController

@property (strong, nonatomic) IBOutlet UILabel *label;
@property (strong, nonatomic) IBOutlet UITextField *text;
- (IBAction)button:(UIButton *)sender;

@end

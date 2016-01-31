//
//  YSViewController.h
//  FirstApplication
//
//  Created by Yu Sun on 8/5/14.
//  Copyright (c) 2014 sunny. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YSViewController : UIViewController

@property (strong, nonatomic) IBOutlet UILabel *titleLabel;
@property (strong, nonatomic) IBOutlet UITextField *textField;

- (IBAction)buttonPressed:(UIButton *)sender;

@end

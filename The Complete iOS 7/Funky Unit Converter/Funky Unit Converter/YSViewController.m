//
//  YSViewController.m
//  Funky Unit Converter
//
//  Created by Yu Sun on 8/6/14.
//  Copyright (c) 2014 sunny. All rights reserved.
//

#import "YSViewController.h"

@interface YSViewController ()

@end

@implementation YSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    NSLog(@"Hello World");
    int x;
    x = 5;
    NSLog(@"The value of x is: %i", x);
    float heightOfEverstBestCamp = 16900.3;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    NSLog(@"didReceiveMemoryWarning");
}

- (IBAction)convertUnits:(UIButton *)sender {
    float number = [self.numberTextField.text floatValue];
    float num = number / 91440;
    self.numberLabel.text = [NSString stringWithFormat:@"%f",num];
}
@end

//
//  YSViewController.m
//  Age of Laika
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
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)button:(UIButton *)sender {
    // The formula is: 10.5 dog years per human year for the first 2 years, then 4 dog years per human year for each year after.
    float year = [self.text.text floatValue];
    float dogYear = 0;
    if (year <= 2) {
        dogYear = year * 10.5;
    }
    else {
        dogYear = 21 + (year - 2) * 4;
    }
    self.label.text = [NSString stringWithFormat:@"%f", dogYear];
}
@end

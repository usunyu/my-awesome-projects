//
//  YSViewController.m
//  Methods
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
    
    [self method1:3];
    [self method2:2 other:6];
    NSLog(@"%i", [self factorial:4]);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) method1: (int) num
{
    for (int i = num; i >= 1; i--) {
        NSLog(@"%i", i);
    }
}

- (void) method2: (int) n1 other: (int) n2
{
    int min = n1 > n2 ? n2 : n1;
    int max = n1 > n2 ? n1 : n2;
    for (int i = min; i <= max; i++) {
        NSLog(@"%i", i);
    }
}

- (int) factorial: (int) num
{
    int ret = 1;
    while (num >= 1) {
        ret *= num;
        num--;
    }
    return ret;
}

@end

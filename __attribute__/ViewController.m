//
//  ViewController.m
//  __attribute__
//
//  Created by 储诚鹏 on 2018/10/12.
//  Copyright © 2018 储诚鹏. All rights reserved.
//

#import "ViewController.h"
#import "__Attribute__.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self testAttributes];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)testAttributes {
    Son *son = [[Son alloc] init];
    [son testRequiresSuper];
    son = nil;
}


@end

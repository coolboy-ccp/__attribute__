//
//  __Attribute__.m
//  __attribute__
//
//  Created by 储诚鹏 on 2018/10/12.
//  Copyright © 2018 储诚鹏. All rights reserved.
//

#import "__Attribute__.h"

disInherit
@interface Eunuch: NSObject
@end

static void printValidAge(int age) enable_if(age > 0 && age < 1000, "快来围观了") {
    NSLog(@"你的年龄是: %d", age);
}

typedef struct boxable {
    double x,y,z,length,width,height;
} TriRect;



@implementation Father
- (void)testRequiresSuper {}
@end

@implementation Son
- (void)testRequiresSuper {
    [super testRequiresSuper];
    NSLock *lock = [[NSLock alloc] init];
//    auto_lock(lock);
    
    onExit {
        
    };
    TriRect rect = { 0,0,0,10,10,10 };
    NSValue *value = @(rect);
    NSLog(@"%@",value);
//    printValidAge(-1); Compile Error
    printValidAge(90);
}

constructor void constructorTest() {
    NSLog(@"constructorTest");
}

destructor void destructorTest() {
    NSLog(@"destructorTest");
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        NSLog(@"init");
    }
    return self;
}

- (void)dealloc
{
    NSLog(@"dealloc");
}
@end

@implementation __Attribute__



@end

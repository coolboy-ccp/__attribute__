//
//  __Attribute__.h
//  __attribute__
//
//  Created by 储诚鹏 on 2018/10/12.
//  Copyright © 2018 储诚鹏. All rights reserved.
//

#import <Foundation/Foundation.h>

//不可继承 final
#define disInherit __attribute__((objc_subclassing_restricted))
//子类继承重写方法时需要调用super
#define requires_super __attribute__((objc_requires_super))

//使用@()将struct或union类型box成NSValue对象
#define boxable __attribute__((objc_boxable))

/*
 在main()函数之前调用
 1.所有class都已经加载完成
 2.main函数还未执行
 3.无需像+load还得挂载在一个class中
 ps:若有多个constructor，且想控制优先级的话，可以在后面加数字__attribute__((constructor(101)))
 数字越小，优先级越高，1~100为系统保留
 */
#define constructor __attribute__((constructor))
//在main()函数之后调用
#define destructor __attribute__((destructor))

//用于c函数的参数的静态检查
#define enable_if(condition, description) __attribute__((enable_if(condition, description)))

//在被修饰的作用域结束时，自动执行一个指定的方法
static void _autoLock(void (^ __strong *lockBlock)(void)) {
    (*lockBlock)();
}

//自解锁
#define AUTO_LOCK(__lock) \
[__lock lock]; \
void (^ __strong autoLock)(void) __attribute__((cleanup(_autoLock), unused)) = ^\
{[__lock unlock];};

//on exit
#define onExit __strong void(^block)(void) __attribute__((cleanup(_autoLock), unused)) = ^

//将类或协议的名字在编译时指定成另一个
#define confusion(to) __attribute__((objc_runtime_name(to)))



NS_ASSUME_NONNULL_BEGIN

confusion("confusionFather")
@interface Father: NSObject
- (void)testRequiresSuper requires_super;
@end

@interface Son: Father
@end

@interface __Attribute__ : NSObject

@end

NS_ASSUME_NONNULL_END

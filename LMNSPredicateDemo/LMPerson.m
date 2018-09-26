//
//  LMPerson.m
//  LMNSPredicateDemo
//
//  Created by 李敏 on 2018/9/26.
//  Copyright © 2018年 李敏. All rights reserved.
//

#import "LMPerson.h"

@implementation LMPerson

-(instancetype)initWithName:(NSString *)name age:(NSUInteger)age sex:(NSString *)sex{
    if (self = [super init]) {
        self.name = name;
        self.age = age;
        self.sex = sex;
    }
    return self;
}

+(instancetype)personWithName:(NSString *)name age:(NSUInteger)age sex:(NSString *)sex{
    return [[LMPerson alloc]initWithName:name age:age sex:sex ];
}
@end

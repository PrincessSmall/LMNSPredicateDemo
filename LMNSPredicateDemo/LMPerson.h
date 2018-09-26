//
//  LMPerson.h
//  LMNSPredicateDemo
//
//  Created by 李敏 on 2018/9/26.
//  Copyright © 2018年 李敏. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LMPerson : NSObject

/**姓名*/
@property (nonatomic , strong)NSString * name;
/**年纪*/
@property (nonatomic , assign)NSUInteger age;
/**性别*/
@property (nonatomic , strong)NSString * sex;

-(instancetype)initWithName:(NSString *)name age:(NSUInteger)age sex:(NSString *)sex;
+(instancetype)personWithName:(NSString *)name age:(NSUInteger)age sex:(NSString *)sex;
@end

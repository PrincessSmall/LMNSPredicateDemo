# LMNSPredicateDemo
#### 一、 谓词的使用（借鉴自http://www.cocoachina.com/ios/20160111/14926.html）
#####  1. 谓词定义
谓词主要是用于定义逻辑条件，实现删选，好比是一个筛选器；
##### 2. 谓词的语法
1->只要我们使用谓词（NSPredicate）都需要为谓词定义谓词表达式,而这个表达式必须是一个返回BOOL的值。

谓词表达式由表达式、运算符和值构成。

2->运算符

* 1.比较运算符，比较运算符类型
     1>: =/== 等于，没有赋值和相等的区别，在谓词里都表示判断是否相等
     2>：> , < 大于和小于，判断左边大于/小于右边
     3>: >=/=> 大雨等于
     4>: <=/=< 小于等于
     5>: !=/<> 不等于
     5>: BETWEEN{下限,上限} 大于等于下限，小于等于上限 
     
```
    LMPerson * person1 = [[LMPerson alloc]initWithName:@"lily" age:18 sex:@"feamel"];
    NSPredicate * pre1 = [NSPredicate predicateWithFormat:@"age > 18"];//定义predicate方法：+ (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat, ...;
    NSPredicate * pre2 = [NSPredicate predicateWithFormat:@"age BETWEEN {17,20}"];
    NSLog(@"person1是否满足条件pre1 %d",[pre1 evaluateWithObject:person1]);//打印结果：person1是否满足条件pre1 0
    NSLog(@"person1是否满足条件pre2 %d",[pre2 evaluateWithObject:person1]);//打印结果：person1是否满足条件pre2 1
```
* 2.逻辑运算符，逻辑运算符类型
   * 1>: &&/AND 逻辑与
   * 2>: OR/||  逻辑或
   * 3>: NOT/NO 逻辑非
   
```
NSPredicate * pre3 = [NSPredicate predicateWithFormat:@"NOT age == 18"];
NSLog(@"person1是否满足条件pre3 %d",[pre3 evaluateWithObject:person1]);//打印结果：person1是否满足条件pre3 0
NSArray * arr = @[@1,@2,@3,@5,@6,@7];
NSPredicate * pre4 = [NSPredicate predicateWithFormat:@"SELF > 4 && SELF < 7"];//SELF是保留字，这里指数组本身
NSArray * tepArr = [arr filteredArrayUsingPredicate:pre4];//filteredArrayUsingPredicate:方法返回筛选符合条件的数组，即返回判断为yes的数组成员，此方法会通过遍历数组中的每个数，返回YES的存入新数组返回；
    /**打印结果：
     (
     5,
     6
     )
     */
    NSLog(@"%@",tepArr);
```
* 3.字符串比较运算符，字符串比较运算符类型
   * 1>:BEGINSWITH,检查字符串是否以指定字符串开头，例如（“SELF CONTAINSWITH ‘ad’”）判断字符串是否以ad开头
   * 2>:ENDSWIH，检查字符串是否以指定字符串结尾
   * 3>:CONTAINS，检查字符串是否包含指定字符串
   * 4>:LIKE，检查某个字符串是否满足制定字符串模版，例如（"name LIKE '*ac*'"）代表字符串中包含ac即返回YES；（"name LIKE '?ac*'"）代表字符串中第二，三个字符是a，c即返回YES；其中？代表一个字符，*代表任意多个字符或者两个字符
   * 5>:MATCHES，检查某个字符串是否匹配指定的正则表达式。虽然正则表达式的执行效率是最低的，但其功能是最强大的，也是我们最常用的
   
  **注意**：字符串比较都是区分大小写和重音符号的。如：café和cafe是不一样的，Cafe和cafe也是不一样的。如果希望字符串比较运算不区分大小写和重音符号，请在这些运算符后使用[c]，[d]选项。其中[c]是不区分大小写，[d]是不区分重音符号，其写在字符串比较运算符之后，比如：name LIKE[cd] 'cafe'，那么不论name是cafe、Cafe还是café上面的表达式都会返回YES。
  
* 4.集合运算符集合运算符类型
 * 1>:ANY,SOME:集合中任意一元素满足条件，就返回YES
 * 2>:ALL：集合中所有元素满足条件时，返回YES
 * 3>:NONE：集合中没有元素满足条件时，返回YES
 * 4>:IN:等价于SQL语句中的IN运算符，只有当左边表达式或值出现在右边的集合中才会返回YES
 * array[index]：返回array数组中index索引处的元素
 * array[FIRST]：返回array数组中第一个元素
 * array[LAST]：返回array数组中最后一个元素
 * array[SIZE]：返回array数组中元素的个数
 
**例子**：

```
NSPredicate * pre5 = [NSPredicate predicateWithFormat:@"ANY SELF == 7"];
NSLog(@"arr是否满足条件pre5 %d",[pre5 evaluateWithObject:arr]);//打印结果：arr是否满足条件pre5 1
NSArray * filterArr = @[@"ab",@"abc"];
NSArray * array = @[@"a",@"ab",@"abc",@"abcd",@"abcde"];
NSPredicate * predicate = [NSPredicate predicateWithFormat:@"SELF IN %@",filterArr];
NSArray * tepAr = [array filteredArrayUsingPredicate:predicate];
NSLog(@"%@",tepAr);
```
* 5.谓词中使用占位符，当想要在谓词表达式中使用变量时,
	* %k:用于动态设置属性名
	* %@:用于动态传入属性值
	* $VALUE：
	
**例子**： 
	
```
NSPredicate * predicate1 = [NSPredicate predicateWithFormat:@"%K CONTAINS %@",@"name",@"y" ];
NSArray * resultArr = [textArr filteredArrayUsingPredicate:predicate1];
NSLog(@"-------xr%@",resultArr);
```


# 第三题 排版校对 

- 2020/03/04

## 题目概述

&#160; &#160; &#160; &#160; 帮助一个人来完成排版校对，确定校对前和校对后的最小操作数。

&#160; &#160; &#160; &#160; 其中操作指定为“修改字符”、“删除字符”、“添加字符”中的一种操作。

### 输入

```input
2
abcdef
123456
bcdg
234567
```

### 输出

```output
5
```

### 示例说明

&#160; &#160; &#160; &#160; `2`表示需要进行校对的有两行文字(行内不包含空格)，紧接着是两行校对前的文字；再接着是其对应的校对后的文字。可以看到，将“abcdef”修改为“bcdg”、将“123456”修改为“234567”。

&#160; &#160; &#160; &#160; 输出表示整个过程最少需要5步操作才能完成：

- 第一步：删除字符'a'；
- 第二步：修改字符'e'为'g'；
- 第三步：删除字符'f'；
- 第四步：删除字符'1'；
- 第五步：添加字符'7'。

## 题解

&#160; &#160; &#160; &#160; 典型的“编辑距离”计算问题，使用“动态规划”进行求解。

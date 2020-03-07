# 第二题 礼物分发 

- 2020/03/04

## 题目概述

&#160; &#160; &#160; &#160; 将n个礼物分发给k个小朋友，请问有多少种分法？请输出可能的分法总数，并输出分法细节(见示例)。

### 输入

```input
3 2
```

### 输出

```output
4
***|
**|*
*|**
|***
```

### 示例说明

&#160; &#160; &#160; &#160; 当把3个礼物分给2个小朋友时，有如下情况：

- 第一个小朋友分得3个礼物，第二个小朋友未分得礼物
- 第一个小朋友分得2个礼物，第二个小朋友分得1个礼物
- 第一个小朋友分得1个礼物，第二个小朋友分得2个礼物
- 第一个小朋友未分得礼物，第二个小朋友分得3个礼物

## 题解

&#160; &#160; &#160; &#160; 我采用的是回溯(递归)的方式来求解的。

&#160; &#160; &#160; &#160; 可以把这个礼物分发过程看做一棵树，那么树的第一层子节点(自顶向下)的可能取值包括3，2，1，0；而以3为根节点的子树，其子节点值为0，同理，对应2，1，0的子节点值分别为1，2，3。这里要说明的是，树的深度即为k(这里的深度不包括根节点)，而每种可能的分法就是从根结点到叶子结点走过的路径(这里，我们把“可视化输出”抽象为一个数组，比如“***|”就可以表示为`[3, 0]`)。因此，我们所求的就是一个`vector<vector<int>>`。

&#160; &#160; &#160; &#160; 其中，每个元素为一个可行路径(即一种分法)，这个answer的大小就是可行路径(可能分法)的个数。

&#160; &#160; &#160; &#160; 因此，采用回溯，记录每次向叶子结点前进的状态，并适时回溯以便于新的解的计算。
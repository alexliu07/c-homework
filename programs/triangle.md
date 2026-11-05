# 三角形 (triangle.c)

- **竞赛**：2026-2-if-for-array-计分作业
- **分区**：计分练习
- **题目 ID**：110
- **时间限制**：100 ms ｜ **内存限制**：256000 KiB
- **原题链接**：http://njuoj.skylare.me:9036/contest/20/problem/110

## 题目描述

> 出题助教：梁志浩
>
> 验题助教：李薛成

Farmer John 的农场里常常会有调皮的奶牛打破栅栏，因此他需要很多木条来修补这些损坏的栅栏。现在有 $3$ 条木棍，他想知道这些木棍能否构成三角形，如果可以，构成的三角形是什么样子的，请你来帮帮他。

1. 如果三条线段不能组成一个三角形，输出 `not triangle`；
2. 如果是等边三角形，输出 `equilateral triangle`；
3. 如果是直角三角形，输出 `right triangle`，<br>
   如果不符合上面三种情况，你需要按照如下的格式输出三角形的形状：
4. 判断是否是锐角/钝角三角形，对应输出 `acute`/`obtuse`，接着判断是否是等腰三角形，如果是，对应输出 `isosceles`，最后输出一个 `triangle`。请注意，中间没有换行，详见样例。

## 输入格式

输入 $3$ 个整数 $a$、$b$ 和 $c$ 。保证 $1\leq a\leq b\leq c\leq 10000$ 。

## 输出格式

输出一行判定字符串。

## 样例

### 样例 1

**输入**

``` text
3 3 3
```

**输出**

``` text
equilateral triangle
```

### 样例 2

**输入**

``` text
3 4 5
```

**输出**

``` text
right triangle
```

### 样例 3

**输入**

``` text
7 7 10
```

**输出**

``` text
obtuse isosceles triangle
```

### 样例 4

**输入**

``` text
1 14 514
```

**输出**

``` text
not triangle
```

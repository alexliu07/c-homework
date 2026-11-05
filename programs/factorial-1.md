#  阶乘的和 Ⅰ (factorial-1.c)

- **竞赛**：2026-2-if-for-array-计分作业
- **分区**：计分练习
- **题目 ID**：112
- **时间限制**：500 ms ｜ **内存限制**：256000 KiB
- **原题链接**：http://njuoj.skylare.me:9036/contest/20/problem/112

## 题目描述

> 出题助教：肖江
> 
> 验题助教：浦亮 李薛成

给定正整数 $n$，计算 $(\sum\limits_{i=1}^ni!)\ \text{mod}\ 10007$ 的值，其中 $i!$ 为 $i$ 的阶乘，$\text{mod} $ 表示取模。

例如，当 $n = 13$ 时，阶乘的和为 $ 6749977113$，由于 $ 6749977113\ \text{mod}\ 10007=5438$。所以你需要输出 $ 5438$。

## 输入格式

一个正整数 $n$，$ 1\leqslant n\leqslant 25$。

## 输出格式

一个整数，为 $ \left(\sum\limits_{i=1}^ni!\right)\ \text{mod}\ 10007$ 的值

## 样例

### 样例 1

**输入**

``` text
3
```

**输出**

``` text
9
```

### 样例 2

**输入**

``` text
13
```

**输出**

``` text
5438
```

## 提示

提示：

1. $\left(\sum\limits_{i=1}^na_i\right)\ \text{mod}\ m = \sum\limits_{i=1}^n(a_i\ \text{mod}\ m)\ \text{mod}\ m$
2. $\left(\prod\limits_{i=1}^na_i\right)\ \text{mod}\ m=\prod\limits_{i=1}^n(a_i\ \text{mod}\ m)\ \text{mod}\ m$

如果你直接求完所有数的和再取模，肯定会超出任何整数数据类型的范围，导致只有$ 50$分。

理解上述两个公式并在程序中表达吧。

---

如果你有时间，不妨看看附加题 [阶乘的和 Ⅱ (factorial-2.c)](https://hz-4.matpool.com:28163/contest/6/problem/30)

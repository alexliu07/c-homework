# 矩阵乘法 (matrix-mult.c)

- **竞赛**：2026-4-loops-计分作业
- **分区**：计分练习
- **题目 ID**：140
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **原题链接**：http://njuoj.skylare.me:9036/contest/24/problem/140

## 题目描述

> 出题助教：毛子钰
> 
> 验题助教：蔡之恒 李薛成

给定一个 $m\times n$ 的整数矩阵 $\boldsymbol{A}$ 和一个 $n\times p$ 的整数矩阵 $\boldsymbol{B}$ 计算 $\boldsymbol{C}=\boldsymbol{AB}$。其中 $C_{ij}=\sum\limits_{k=1}^nA_{ik}B_{kj}$

（题目注解👇里有说明）

## 输入格式

输入为多行，第一行是三个用空格隔开的正整数 $m,\ n,\ p$

接下来 $m$ 行，每行 $n$ 个用空格隔开的整数，表示矩阵 $\boldsymbol{A}$ 的 $m$ 行

接下来 $n$ 行，每行 $p$ 个用空格隔开的整数，表示矩阵 $\boldsymbol{B}$ 的 $n$ 行

其中 $ 1\leqslant m,\ n,\ p\leqslant 100$

数据保证计算结果不爆 int

## 输出格式

输出 $m$ 行，每行 $p$ 个用空格隔开的正整数，表示乘积矩阵 $\boldsymbol{C}$ 的 $m$ 行

## 样例

### 样例 1

**输入**

``` text
1 2 3
1 2
1 2 3
4 5 6
```

**输出**

``` text
9 12 15
```

### 样例 2

**输入**

``` text
3 4 5
1 2 3 4
5 6 7 8
9 10 11 12
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
```

**输出**

``` text
110 120 130 140 150
246 272 298 324 350
382 424 466 508 550
```

## 提示

**如果你学过矩阵相关知识，可以不用看**

设 $ m\times n$ 的矩阵 $\boldsymbol{A} = \begin {pmatrix} a_{11}&a_{12}& \cdots &a_{1n} \\\ a_{21}&a_{22}& \cdots &a_{2n} \\\ \vdots & \vdots & \ddots & \vdots \\\ a_{m1} & a_{m2} & \cdots & a_{mn} \end{pmatrix} $，和 $ n\times p$ 的矩阵 $ \boldsymbol{B} = \begin {pmatrix} b_{11}&b_{12}& \cdots &b_{1p} \\\ b_{21}&b_{22}& \cdots &b_{2p} \\\ \vdots & \vdots & \ddots & \vdots \\\ b_{n1} & b_{n2} & \cdots & b_{np} \end{pmatrix}$，

则 $\boldsymbol{C}=\boldsymbol{AB}$ 是一个 $ m\times p$ 的矩阵，且 $\boldsymbol{C}= \begin {pmatrix} c_{11}&c_{12}& \cdots &c_{1p} \\\ c_{21}&c_{22}& \cdots &c_{2p} \\\ \vdots & \vdots & \ddots & \vdots \\\ c_{m1} & c_{m2} & \cdots & c_{mn} \end{pmatrix}$，其中 $c_{ij}=\sum\limits_{k=1}^na_{ik}b_{kj}$。

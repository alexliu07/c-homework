# 归一化指数 (softmax.c)

- **竞赛**：2026-4-loops-不计分练习
- **分区**：附加题
- **题目 ID**：155
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **原题链接**：http://njuoj.skylare.me:9036/contest/25/problem/155

## 题目描述

> 出题助教：毛子钰

设向量 $\boldsymbol{x}\in\mathbb{R}^n$，${\rm softmax}$ 函数定义为：若 $\boldsymbol{y}={\rm softmax}(\boldsymbol{x})$，则 $\boldsymbol{y}\in\mathbb{R}^n$ 且 $y_i=\dfrac{{\rm e}^{x_i}}{\sum\limits_{j=1}^n{\rm e}^{x_j}}$

带温度的 ${\rm softmax}$ 函数定义为：若 $\boldsymbol{y}={\rm softmax}(\boldsymbol{x},\ \tau)$，则 $\boldsymbol{y}\in\mathbb{R}^n$ 且 $y_i=\dfrac{{\rm e}^{x_i/\tau}}{\sum\limits_{j=1}^n{\rm e}^{x_j/\tau}}$，其中 $\tau>0$ 为温度变量。可证：温度越高，$\boldsymbol{y}$ 越 “平滑”。

给定向量 $\boldsymbol{x}$ 和一系列温度的值。计算各个温度下的 $\boldsymbol{y}$ 以及 $\boldsymbol{y}$ 的方差

* 期望的定义：$\mathbb{E}[\boldsymbol{y}]=\dfrac{1}{n}\sum\limits_{i=1}^ny_i$
* 方差的定义：${\rm Var}[\boldsymbol{y}]=\dfrac{1}{n}\sum\limits_{i=1}^n(y_i-\mathbb{E}[\boldsymbol{y}])^2$（这里不使用无偏估计版本）

## 输入格式

输入包含多行，第一行有两个空格隔开的正整数 $n,\ k\ (1\leqslant n\leqslant 100,\ 1\leqslant k\leqslant 20)$，其中 $n$ 表示向量 $\boldsymbol{x}$ 的长度，$k$ 表示温度的个数。

第二行有 $n$ 个空格隔开的浮点数 $x_1,\ x_2,\ \cdots,\ x_n$，表示 $\boldsymbol{x}$ 的 $n$ 个分量（$\forall 1\leqslant i\leqslant n,\ -10<x_i<10$)

第三行有 $k$ 个空格隔开的浮点数 $\tau_1,\ \tau_2,\ \cdots,\ \tau_k$，表示 $k$ 个温度 $(\forall 1\leqslant i\leqslant k,\ 0<\tau_i<10)$

## 输出格式

输出 $k$ 行，每行有 $n+1$ 个空格隔开的浮点数。

第 $i$ 行的前 $n$ 个数中，第 $j$ 个数表示 $\boldsymbol{y}={\rm softmax}(\boldsymbol{x},\ \tau_i)$ 的第 $j$ 个分量

第 $i$ 行的最后一个数为 $\boldsymbol{y}={\rm softmax}(\boldsymbol{x},\ \tau_i)$ 的方差（所有输出均保留三位小数）

## 样例

**输入**

``` text
2 2
1.14 5.14
1 1.4
```

**输出**

``` text
0.018 0.982 0.232
0.054 0.946 0.199
```

## 提示

根据输出，你能找到 $\rm softmax$ 的输出随温度的增加而变平滑的原因吗？（如何定义平滑？）

翻车事故：

一开始 $1\leqslant n\leqslant 1000000$，后来发现由于$n$ 太大，导致 $\rm softmax$ 中的分母太大，然后 $\boldsymbol{y}$ 的所有分量都接近于 $0$，也就是说，在保留三位小数的情况下，输出的东西全是 $0.000$，就是只需要打印 $k$ 行，每行 $n+1$ 个 $0.000$ 就可以通过本题（当然现在把 $n$ 改小了，偷不了鸡了🤣 👉）

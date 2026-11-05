# 赛尔耗 (seer.c)

- **竞赛**：2026-4-loops-不计分练习
- **分区**：附加题
- **题目 ID**：156
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **原题链接**：http://njuoj.skylare.me:9036/contest/25/problem/156

## 题目描述

> 出题助教：毛子钰

阿伟和彬彬在玩风靡全球的电动 ——《赛尔耗》。

赛尔耗之前上架了 $m$ 只精灵，第 $i$ 只精灵的种族值和售价分别为 $x_i,\ y_i$，他们找到了你，想让你帮他们通过这 $m$ 只精灵的种族值和售价，来预测即将上架的精灵的售价。细心的你发现，精灵的售价 $y$ 往往和种族值 $x$ 呈线性相关，于是你选用 $h(x)=\theta_0+\theta_1x$ 来预测种族值为 $x$ 的精灵的售价。

你需要做的是 **通过$\\{(x_1,\ y_1),\ \cdots,\ (x_m,y_m)\\}$ 来确定参数 $\boldsymbol\theta=[\theta_0,\ \theta_1]$，使得代价函数 $J(\boldsymbol\theta)$ 的值最小**，其中 $J(\boldsymbol\theta)=\dfrac{1}{2m}\sum\limits_{i=1}^m\big(h(x_i)-y_i\big)^2$

**你必须使用如下方法来计算 $\boldsymbol\theta$ 的值**：

1. 首先选择 $\boldsymbol\theta$ 的初始值、循环次数 $T$ 和学习率 $\alpha$，在本题中，你必须令 $\boldsymbol\theta$ 初始值为 $[1.000,\ 1.000]$，$T=2000,\ \alpha=0.01$
2. 循环 $T$ 次，在每一次循环中更新 $\boldsymbol\theta$ 的值：$\theta_j:=\theta_j-\alpha\cdot J'_{\theta_j}$，其中：
   $J'_{\theta_0}=\dfrac{1}{m}\sum\limits_{i=1}^m\big(h(x_i)-y_i\big),\ J'_{\theta_1}=\dfrac{1}{m}\sum\limits_{i=1}^m\Big(\big(h(x_i)-y_i)\big)x_i\Big)$
3. 循环结束后，你就得到了参数 $\boldsymbol\theta$，对于每只待上架精灵的种族值 $x$，你都能使用 $h(x)=\theta_0+\theta_1x$ 来预测它的售价 $y$。

为了减少你的工作量，阿伟和彬彬对种族值做了特征缩放，使得所有精灵的种族值为 $-1\sim 1$ 范围内的浮点数。

## 输入格式

输入多行，第一行为一个正整数 $m$，为已上架的精灵数量。

接下来 $m$ 行，每行两个浮点数，为已上架精灵的种族值 $x$ 及售价 $y$。

（$ 1\leqslant m\leqslant 100,\ -1.000\leqslant x\leqslant 1.000,\ 0.001\leqslant y\leqslant 10.000$）

## 输出格式

输出一行，为你训练的模型，输出格式为：y = $\theta_0$ + $\theta_1$x

注意等号两边和加号两边都有空格，$\theta_0,\ \theta_1$ 保留三位小数。

## 样例

**输入**

``` text
2
0.000 1.000
1.000 2.000
```

**输出**

``` text
y = 1.000 + 1.000x
```

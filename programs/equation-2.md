# 三元一次方程 (equation-2.c)

- **竞赛**：2026-4-loops-不计分练习
- **分区**：附加题
- **题目 ID**：149
- **时间限制**：100 ms ｜ **内存限制**：256000 KiB
- **原题链接**：http://njuoj.skylare.me:9036/contest/25/problem/149

## 题目描述

> 出题助教：潘星宇
>
> 验题助教：余明晖 罗荣鑫

使用 **克莱姆法则**（Cramer's Rule）可以解三元一次方程组,下面是如何用克莱姆法则解三元一次方程组的步骤。

### 假设有以下三元一次方程组：

$$
\begin{cases}
a_1x + b_1y + c_1z = d_1 \\\\
a_2x + b_2y + c_2z = d_2 \\\\
a_3x + b_3y + c_3z = d_3
\end{cases}
$$

### 步骤 1：写出系数矩阵和常数向量

对应的系数矩阵 $\mathbf{A}$ 是：

$$
\mathbf{A} =
\begin{pmatrix}
a_1 & b_1 & c_1 \\\\
a_2 & b_2 & c_2 \\\\
a_3 & b_3 & c_3
\end{pmatrix}
$$

常数向量是：

$$
\mathbf{B} =
\begin{pmatrix}
d_1 \\\\
d_2 \\\\
d_3
\end{pmatrix}
$$

### 步骤 2：计算系数矩阵的行列式

行列式 $ \Delta $ 为系数矩阵的行列式：

$$
\Delta =
\begin{vmatrix}
a_1 & b_1 & c_1 \\\\
a_2 & b_2 & c_2 \\\\
a_3 & b_3 & c_3
\end{vmatrix}
$$

$$
\Delta = a_1(b_2c_3 - b_3c_2) - b_1(a_2c_3 - a_3c_2) + c_1(a_2b_3 - a_3b_2)
$$

如果 $ \Delta \neq 0 $，方程组有唯一解，可以用克莱姆法则求解。

### 步骤 3：计算各变量的行列式

- $ x $ 的行列式 $ \Delta_x $ 是将系数矩阵的第一列替换为常数向量 $ \mathbf{B} $：

  $$
  \Delta_x =
  \begin{vmatrix}
  d_1 & b_1 & c_1 \\\\
  d_2 & b_2 & c_2 \\\\
  d_3 & b_3 & c_3
  \end{vmatrix}
  $$
- $ y $ 的行列式 $ \Delta_y $ 是将系数矩阵的第二列替换为常数向量 $ \mathbf{B} $：

  $$
  \Delta_y =
  \begin{vmatrix}
  a_1 & d_1 & c_1 \\\\
  a_2 & d_2 & c_2 \\\\
  a_3 & d_3 & c_3
  \end{vmatrix}
  $$
- $ z $ 的行列式 $ \Delta_z $ 是将系数矩阵的第三列替换为常数向量 $ \mathbf{B} $：

  $$
  \Delta_z =
  \begin{vmatrix}
  a_1 & b_1 & d_1 \\\\
  a_2 & b_2 & d_2 \\\\
  a_3 & b_3 & d_3
  \end{vmatrix}
  $$

### 步骤 4：计算各变量的值

根据克莱姆法则，变量的解为：

$$
x = \frac{\Delta_x}{\Delta}, \quad y = \frac{\Delta_y}{\Delta}, \quad z = \frac{\Delta_z}{\Delta}
$$

请使用该法则求解三元一次方程组。

## 输入格式

一个3 x 4的**double**类型矩阵，**确保方程组有且只有唯一解**

## 输出格式

3 个小数，分别表示方程的解 $ x, y, z$ ,保留两位小数输出

## 样例

**输入**

``` text
4.5  2.0  1.5  12.5
2.0  1.0  3.0   8.0
1.5 -1.5  2.0   5.5
```

**输出**

``` text
2.38 0.11 1.04
```

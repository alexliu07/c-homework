# 判断矩阵是否满足条件 (grid-conditions.c)

- **竞赛**：期中考试
- **题目 ID**：175
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **原题链接**：[http://njuoj.skylare.me:9036/contest/29/problem/175](http://njuoj.skylare.me:9036/contest/29/problem/175)

## 题目描述

给你一个 $n \times m$ 的整数矩阵 `grid`。请判断每个格子是否都满足下面两条条件。

- 如果正下方有格子，两格的值必须相等，即 `grid[i][j] == grid[i + 1][j]`。
- 如果正右方有格子，两格的值必须不同，即 `grid[i][j] != grid[i][j + 1]`。

如果所有格子都满足条件，输出 `true`，否则输出 `false`。

## 输入格式

第一行包含一个整数 $n$，表示矩阵的行数。

接下来 $n$ 行，每行的整数用空格分隔。矩阵的列数 $m$ 等于矩阵第一行的整数个数，后续各行也都包含 $m$ 个整数。

## 输出格式

输出一行。如果满足题目要求，输出小写的 `true`，否则输出小写的 `false`。

## 样例

### 样例 1

**输入**

```text
2
1 0 2
1 0 2
```

**输出**

```text
true
```

### 样例 2

**输入**

```text
2
1 1 1
0 0 0
```

**输出**

```text
false
```

### 样例 3

**输入**

```text
3
1
2
3
```

**输出**

```text
false
```

## 提示

**样例图**

**样例 1**

$$
\begin{array}{|c|c|c|}
\hline
1 & 0 & 2 \\ \hline
1 & 0 & 2 \\ \hline
\end{array}
$$

**样例 2**

$$
\begin{array}{|c|c|c|}
\hline
1 & 1 & 1 \\ \hline
0 & 0 & 0 \\ \hline
\end{array}
$$

**样例 3**

$$
\begin{array}{|c|}
\hline
1 \\ \hline
2 \\ \hline
3 \\ \hline
\end{array}
$$

**提示**

- $1 \le n, m \le 10$
- $0 \le \text{grid}[i][j] \le 9$

# 搜索二维矩阵 (search-matrix.c)

- **竞赛**：期中考试
- **题目 ID**：180
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **原题链接**：[http://njuoj.skylare.me:9036/contest/29/problem/180](http://njuoj.skylare.me:9036/contest/29/problem/180)

## 题目描述

给你一个 $m \times n$ 的整数矩阵 `matrix`，同一张矩阵需要查询 $q$ 次。矩阵中的元素按下面两条规则排列。

- 每行的整数从左到右按非递减顺序排列，同一行可以有相同的整数。
- 从第二行开始，每行的第一个整数都严格大于上一行的最后一个整数。

每次查询给出一个整数 `target`。如果它出现在矩阵中，输出 `true`，否则输出 `false`。目标值可以重复，按输入顺序回答各次查询。

如果你直接顺序查找，那么代码提交后一定会出现超时现象。

## 输入格式

第一行包含三个用空格分隔的整数 $m$、$n$ 和 $q$，分别表示矩阵的行数、列数和查询次数。

接下来 $m$ 行，每行包含 $n$ 个用空格分隔的整数，按从左到右的顺序给出这一行的元素。

最后 $q$ 行，每行包含一个整数 `target`，表示本次要在矩阵中查找的值。

## 输出格式

按查询顺序输出 $q$ 行。若本次查询的目标值出现在矩阵中，输出小写的 `true`，否则输出小写的 `false`。

## 样例

### 样例 1

**输入**

```text
3 4 5
1 3 5 7
10 11 16 20
23 30 34 60
3
13
1
60
0
```

**输出**

```text
true
false
true
true
false
```

### 样例 2

**输入**

```text
2 3 5
-8 -8 0
2 7 7
-8
1
7
-9
8
```

**输出**

```text
true
false
true
false
false
```

## 提示

**样例图**

**样例 1**

$$
\begin{array}{|c|c|c|c|}
\hline
\boxed{1} & \boxed{3} & 5 & 7 \\ \hline
10 & 11 & 16 & 20 \\ \hline
23 & 30 & 34 & \boxed{60} \\ \hline
\end{array}
$$

**样例 2**

$$
\begin{array}{|c|c|c|}
\hline
\boxed{-8} & \boxed{-8} & 0 \\ \hline
2 & \boxed{7} & \boxed{7} \\ \hline
\end{array}
$$

**提示**

- $1 \le m, n \le 100$
- $1 \le q \le 10^6$
- $-10^4 \le \text{matrix}[i][j], \text{target} \le 10^4$

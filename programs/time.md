# 永恒之尘 (time.c)

- **竞赛**：2026-1-types-io-计分作业（二）
- **分区**：计分练习
- **题目 ID**：17
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **原题链接**：http://njuoj.skylare.me:9036/contest/4/problem/17

## 题目描述

> 出题助教：浦亮
>
> 验题助教：孙博文 张哲恺

为了节约存储大小，需要把输入的日期改为目标格式输出 ~~都什么年代了还在用传统时间表示法？~~

举例:

- 输入: November 17 1968 Sunday 6 6 6
- 输出: Sun Nov 17 06:06:06 1968

## 输入格式

`month day year weekday hour minute second`

**其中 $0 \leqslant year \leqslant 9999$**

保证是公元后的合法日期

## 输出格式

`Www Mmm dd hh:mm:ss yyyy`

- `Www`: 3-letter abbreviated day of the week
- `Mmm`: 3-letter abbreviated month name
- `dd`: 2-digit day of the month
- `hh`: 2-digit hour
- `mm`: 2-digit minute
- `ss`: 2-digit second
- `yyyy`: 4-digit year

位数不足的，在前面补0.

## 样例

### 样例 1

**输入**

``` text
September 29 22 Friday 12 0 0
```

**输出**

``` text
Fri Sep 29 12:00:00 0022
```

### 样例 2

**输入**

``` text
November 17 1968 Sunday 6 6 6
```

**输出**

``` text
Sun Nov 17 06:06:06 1968
```

## 提示

**小心数据范围**

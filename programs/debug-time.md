# 日期格式化 (debug-time.c)

- **竞赛**：1-types-io
- **题目 ID**：298
- **时间限制**：100 ms ｜ **内存限制**：25600 KiB
- **原题链接**：[https://public.oj.cpl.icu/contest/4/problem/298](https://public.oj.cpl.icu/contest/4/problem/298)

## 题目描述

本题提供 **7 个独立错误版本**。请切换修复任务，只修改各自标出的可编辑区域。版本 01–07 依次为 **20、15、15、15、10、15、10 分**，合计 100 分。每个版本通过它的全部测试即可获得对应分数；可以分次提交，其他版本未修好不影响已通过版本得分。

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

## 提示

**小心数据范围**

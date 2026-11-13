# 传感器 (debug-sensor.c)

- **竞赛**：1-types-io
- **题目 ID**：300
- **时间限制**：100 ms ｜ **内存限制**：25600 KiB
- **原题链接**：[https://public.oj.cpl.icu/contest/4/problem/300](https://public.oj.cpl.icu/contest/4/problem/300)

## 题目描述

本题提供 **6 个独立错误版本**。请切换修复任务，只修改各自标出的可编辑区域。版本 01–06 依次为 **25、20、15、15、15、10 分**，合计 100 分。每个版本通过它的全部测试即可获得对应分数；可以分次提交，其他版本未修好不影响已通过版本得分。

> 出题助教：柳永昊
>
> 验题助教：王颖琪 扈晨曦

你正在设计一个高精度传感器系统，用于接收多个传感器的数据，系统要求将多个传感器测量数据进行格式转换和输出。这些数据的精度要求极高，转换后需要进行标准化处理。

## 输入格式

输入为一行，数据用空格分隔，格式如下：

```
name pre frac factor unit
```

* `name`：传感器名称，不超过 $ 20$ 个字符的英文单词（如 $Pressure$）。
* `pre`：整数，表示传感器的测量值，范围为 $ [0 , 2^{31}-1]$。
* `frac`：双精度小数，表示测量的小数部分。
* `factor`：双精度小数，表示单位换算因子，例如 $ 1000.000000$ 表示从千克转换到克。
* `unit`：原始单位，**仅限一个小写字母**（如 $k$、$m$、$g$）。

## 输出格式

输出格式如下：

```
N: p (frac) | sciEexp conv new_unit
```

* `N`：传感器名称的前两个字母，不足两个字母则输出完整名称。
* `p`：传感器测量值的整数部分，即 `pre`。
* `(frac)`：`frac` 保留 $ 5$ 位小数，用**英文括号**括起。
* `sciEexp`：`pre + frac` 以科学记数法表示，底数保留 $ 5$ 位小数，指数保留 $ 2$ 位。
* `conv`：`(pre + frac) * factor` 的结果，保留 $ 5$ 位小数。
* `new_unit`：`unit` 的大写形式。

## 提示

**本题保证所有输入合法**

科学记数法的输出请阅读C语言参考手册：

校外请使用👉[https://zh.cppreference.com/w/c/io/fprintf](https://zh.cppreference.com/w/c/io/fprintf)

校内可使用👉[https://ref.cpl.icu/c/io/fprintf.html](https://ref.cpl.icu/c/io/fprintf.html)

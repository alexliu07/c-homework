# 圆周率 Ⅱ (pi-2.c)

- **竞赛**：2026-1-types-io-计分作业
- **分区**：计分练习
- **题目 ID**：13
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **类型**：特殊评测
- **原题链接**：http://njuoj.skylare.me:9036/contest/3/problem/13

## 题目描述

> 出题助教：顾益铭
>
> 验题助教：余明晖

调用 C 语言中的数学函数库，分别用以下两种近似方式计算圆周率:

* [Formula @ wiki](https://en.wikipedia.org/wiki/Approximations_of_%CF%80#Miscellaneous_approximations)
  * $\Large\pi=\dfrac{\ln(5280^3(236674 + 30303\sqrt{61})^3 + 744)}{\sqrt{427}}$
* [Machin Formula @ wiki](https://en.wikipedia.org/wiki/Approximations_of_%CF%80#Machin-like_formula)
  * $\Large\dfrac{\pi}{4} = 6 \arctan\dfrac{1}{8} + 2\arctan\dfrac{1}{57} + \arctan\dfrac{1}{239}$

要求:

* 每个结果占一行
* 小数点后均保留 15 位
  * 精度要求为 `double`
* 必须通过调用数学函数计算结果
  * 指定使用 `log()`, `sqrt()`, `atan()` 函数， **不要使用 atan2()**
  * 写在注释里假装调用了是不行哒，嘎嘎嘎

## 输入格式

无

## 输出格式

两行，每行一个小数

注意由于本题输出的是定值，所以无需考虑样例

## 样例

**输入**

``` text
无
```

**输出**

``` text
答案就这个，这也看？
```

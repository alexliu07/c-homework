# 数字转换 Ⅱ (converter-2.c)

- **竞赛**：2026-5-function-计分作业
- **分区**：计分练习
- **题目 ID**：161
- **时间限制**：100 ms ｜ **内存限制**：256000 KiB
- **原题链接**：http://njuoj.skylare.me:9036/contest/26/problem/161

## 题目描述

> 出题助教：柳永昊
>
> 验题助教：李薛成 刘治元

请编写一个程序，输入一个整数（范围为 `int`），输出该整数的英文单词（全小写）表示。

#### 要求

1. 数字的英文表示应为标准的英文格式。
2. 输入 $ 0$ 时，直接输出`zero`（不要考虑 $-0$)。
3. 当数字为负数时，以 `minus` 开头，后接正数的英文单词表示。

## 输入格式

一个 `int` 类型的整数，范围为 `[-2147483648, 2147483647]`。

## 输出格式

输出该整数的英文单词表示，符合标准英文书写格式。

## 样例

### 样例 1

**输入**

``` text
2147483646
```

**输出**

``` text
two billion one hundred and forty-seven million four hundred and eighty-three thousand six hundred and forty-six
```

### 样例 2

**输入**

``` text
-2147483646
```

**输出**

``` text
minus two billion one hundred and forty-seven million four hundred and eighty-three thousand six hundred and forty-six
```

### 样例 3

**输入**

``` text
1001
```

**输出**

``` text
one thousand one
```

## 提示

### 注意

1. `billion`、`million`、`thousand` 的使用：到达对应位数后用对应英文分割每三位，为简化题目，不需要加 `and` 。
2. `and` 的使用：如果一个数超过 $ 100$，且有十位或个位数，则需要在百位数与剩余的部分之间使用 `and`。
3. `-` 的使用：如果一个数超过 $ 20$，且有个位数，则需要在十位和个位之间使用 `-`。

### 数据范围

我们对输入数据点（共 $ 125$ 个）做出以下保证：

* $ 20$ 个数据点：输入范围为 `[0, 1000]` 。
* $ 46$ 个数据点：输入范围为 `[-2147483648, -1]`，涉及所有格式要求。
* $ 59$ 个数据点：输入范围为 `[1000, 2147483647]`，涉及所有格式要求。

### 提示

1. 请结合占据内存位数为 32 位的 `int` 类型考虑什么情况下会出错。
2. 推荐使用函数来将每三位的转化封装起来，即可不用复制粘贴大量代码。
3. 推荐使用 `switch case` 来大大简化条件判断，如果不会的话请翻书自学。指路教材 $P66$ 的 $ 5.3$ 章节。
4. 如果你想用超纲知识来简化更多的代码量，可以提前阅读教材 $P235$ 的 $ 13.7$ 字符串数组章节，在此贴一段代码，自行领会，不多赘述（毕竟超纲了，想看懂的话可以去翻翻书大概看看，这种方法就不需要 `switch` 了）：

```c
static char *ones[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
  "0", "1", "twenty", "thirty", "forty", 
  "fifty", "sixty", "seventy", "eighty", "ninety"};

// 如何打印 123 的英文呢？像这样就行啦！
printf("%s hundred and %s-%s", ones[1], tens[2], ones[3]);
```

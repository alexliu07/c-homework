#include <stdio.h>
#include <stdbool.h>

static bool answers[] = {
  [1]  = (false),
  [2]  = (false),
  [3]  = (true),
  [4]  = (true),
  [5]  = (true),
  [6]  = (false),
  [7]  = (true),
  [8]  = (false),
  [9]  = (false),
  [10] = (false),
  [11] = (false),
  [12] = (false),
  [13] = (false),
  [14] = (false),
  [15] = (false),
  [16] = (false),
  [17] = (false),
  [18] = (true),
  [19] = (false),
  [20] = (true)
  // 按照 [20] 的格式，在前 19 题选择填入 true 或 false
};

int main() {
  int number;
  scanf("%d", &number);

  if (answers[number]) {
    printf("True\n");
  } else {
    printf("False\n");
  }

  return 0;
}
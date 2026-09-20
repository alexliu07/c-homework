#!/usr/bin/env bash
# 新建一次作业的脚手架：./newhw.sh hw03
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
name="${1:-}"

if [[ -z "$name" ]]; then
  echo "用法: ./newhw.sh <作业名>   例如: ./newhw.sh hw03" >&2
  exit 1
fi

dir="$root/homework/$name"
if [[ -e "$dir" ]]; then
  echo "已存在: homework/$name" >&2
  exit 1
fi

mkdir -p "$dir"
sed "s/__HW_NAME__/$name/g" "$root/templates/main.c" > "$dir/main.c"
cat > "$dir/README.md" <<EOF
# $name

## 题目

（把老师给的题目贴在这里）

## 思路

## 完成情况

- [ ] 通过样例输入输出
- [ ] 处理了边界情况

## 运行

\`\`\`bash
make run HW=$name
\`\`\`
EOF

echo "已创建 homework/$name/{main.c,README.md}"
echo "下一步：编辑 $dir/main.c，或直接打开它按 F5 调试。"

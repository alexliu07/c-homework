#!/usr/bin/env bash
# 新建一次作业：./newhw.sh hw02  ->  hw02.c
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
name="${1:-}"

if [[ -z "$name" ]]; then
  echo "用法: ./newhw.sh <作业名>   例如: ./newhw.sh hw02" >&2
  exit 1
fi

name="${name%.c}"
file="$root/$name.c"

if [[ -e "$file" ]]; then
  echo "已存在: $name.c" >&2
  exit 1
fi

sed "s/__HW_NAME__/$name/g" "$root/templates/main.c" > "$file"

echo "已创建 $name.c"
echo "下一步：编辑 $file，然后 Ctrl+Shift+B 编译、F5 调试。"

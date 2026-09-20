# 大学 C 语言作业 - 批量编译（作业 = programs/ 下的一层单文件）
#   make                 编译 programs/ 下所有 .c 到 build/
#   make run HW=equation 编译并运行某次作业（不带 .c 后缀）
#   make list            列出所有产物
#   make clean           删除 build/

CC      ?= gcc
CFLAGS  ?= -std=c11 -Wall -Wextra -Wpedantic -g -O0
LDLIBS  ?= -lm                      # 用了 math.h（sqrt/pow 等）需要 -lm
BUILD   := build
SRCS    := $(wildcard programs/*.c)
TARGETS := $(addprefix $(BUILD)/,$(notdir $(SRCS:.c=)))

.PHONY: all run list help clean

all: $(TARGETS)
	@echo "编译完成：$(words $(TARGETS)) 个文件 -> $(BUILD)/"

$(BUILD)/%: programs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

run:
	@test -n "$(HW)" || { echo "用法: make run HW=equation（不带 .c 后缀）"; exit 1; }
	@$(MAKE) --no-print-directory $(BUILD)/$(HW)
	@echo "== 运行 $(BUILD)/$(HW) =="; exec "$(BUILD)/$(HW)"

list:
	@for t in $(TARGETS); do echo $$t; done

help:
	@sed -n '2,6p' Makefile

clean:
	@rm -rf $(BUILD)
	@echo "已删除 $(BUILD)/"

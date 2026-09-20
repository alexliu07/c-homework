# 大学 C 语言作业 - 一键编译
#   make                 编译 homework/ 下所有作业
#   make run HW=hw01     编译并运行某次作业
#   make list            列出产物
#   make clean           删除 build/

CC      ?= gcc
CFLAGS  ?= -std=c11 -Wall -Wextra -Wpedantic -g -O0
BUILD   := build
HW_DIRS := $(sort $(dir $(wildcard homework/*/*.c)))
HW_DIRS := $(patsubst %/,%,$(HW_DIRS))
TARGETS := $(addprefix $(BUILD)/,$(addsuffix /main,$(HW_DIRS)))

.PHONY: all run list clean help

all: $(TARGETS)
	@echo "编译完成：$(words $(TARGETS)) 个目标 -> $(BUILD)/"

# 每次作业的所有 .c 一起链接成一个可执行文件（要求其中有一个 main 函数）
define HW_RULE
$(BUILD)/$(1)/main: $$(wildcard $(1)/*.c)
	@mkdir -p $$(dir $$@)
	$$(CC) $$(CFLAGS) -o $$@ $$^
endef
$(foreach d,$(HW_DIRS),$(eval $(call HW_RULE,$(d))))

run:
	@test -n "$(HW)" || { echo "用法: make run HW=hw01"; exit 1; }
	@bin="$(BUILD)/homework/$(HW)/main"; \
	 test -f "$$bin" || { echo "未找到 $$bin，先跑一次 make 或检查 homework/$(HW)"; exit 1; }; \
	 echo "== 运行 $$bin =="; exec "$$bin"

list:
	@for t in $(TARGETS); do echo $$t; done

help:
	@sed -n '2,6p' Makefile

clean:
	@rm -rf $(BUILD)
	@echo "已删除 $(BUILD)/"

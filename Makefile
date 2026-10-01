CC ?= clang
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -pedantic -O2
PROGRAMS = hello mario_less mario_more cash credit scrabble readability caesar substitution plurality
BINARIES = $(addprefix bin/,$(PROGRAMS))

.PHONY: all clean test
all: $(BINARIES)

bin:
	mkdir -p bin

bin/%: src/%.c | bin
	$(CC) $(CFLAGS) $< -o $@

test: all
	sh tests/smoke.sh

clean:
	rm -rf bin

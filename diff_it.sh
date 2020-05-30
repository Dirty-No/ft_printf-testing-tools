#!/usr/bin/env bash
mkdir bin diffs
clang -w -fsanitize=address -o bin/test_diff.out src/test_diff.c ../libftprintf.a \
&& ./bin/test_diff.out > diffs/ft_printf.diff \
&& ./bin/test_diff.out > diffs/printf.diff \
&& diff diffs/ft_printf.diff diffs/printf.diff

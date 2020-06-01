#!/usr/bin/env bash
mkdir -p bin outputs
clang -w -fsanitize=address -o bin/test_diff.out src/test_diff.c ../libftprintf.a \
&& ./bin/test_diff.out > outputs/ft_printf.output \
&& ./bin/test_diff.out printf > outputs/printf.output \
&& diff outputs/ft_printf.output outputs/printf.output

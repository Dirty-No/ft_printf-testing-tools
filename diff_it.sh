#!/bin/bash -e

cd .. && make && cd ft_printf-testing-tools
mkdir -p bin outputs
clang -w -g -fsanitize=address -o bin/test_diff.out src/tests.c src/test_diff.c ../libftprintf.a 
./bin/test_diff.out > outputs/ft_printf.output 
./bin/test_diff.out printf > outputs/printf.output 
echo -e "\e[31m" 
diff outputs/ft_printf.output outputs/printf.output 
echo -e "\e[0m"JJ

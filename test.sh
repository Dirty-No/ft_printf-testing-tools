#!/bin/bash -e

cd .. && make && cd ft_printf-testing-tools
mkdir -p bin diffs
clang -w -g -fsanitize=address -o bin/tester.out src/main.c src/tests.c ../libftprintf.a
./bin/tester.out > output
count=$(cat output | grep DIFFER | wc -l)
cat output
rm output
if [ $count != "0" ]
then
    echo -e "\t\e[31m/!\\ THERE HAS BEEN \e[36m$count\e[31m RETURN ERRORS /!\\ \e[0m"
fi

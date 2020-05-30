#!/usr/bin/env bash
mkdir bin diffs
clang -w -fsanitize=address -o bin/tester.out src/test.c ../libftprintf.a \
&& ./bin/tester.out\
&& ./bin/tester.out > output
count=$(cat output | grep DIFFER | wc -l)
cat output && rm output
if [ $count != "0" ]
then
    echo -e "\t\e[31m/!\\ THERE HAS BEEN \e[36m$count\e[31m RETURN ERRORS /!\\ \e[0m"
fi

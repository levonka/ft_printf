#!/bin/bash
# par=$1

if [ $1 = "re" ]; then
	echo "lol"
	mv "main.c" ".main.c"
	mv .printf_main.c printf_main.c
	make hi && ./printf
else
	echo "err"
	mv ".main.c" "main.c"
	mv "printf_main.c" ".printf_main.c"
	make re && ./printf
fi

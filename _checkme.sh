#!/bin/bash
# par=$1

if [ $1 = "re" ]; then
	echo "lol"
	rm -rf ../tests/checker/tmp/*
	cp -r * ../tests/checker/tmp
	cd ../tests/checker/tmp
	rm ../ft_printf/libftprintf.a
	rm -rf "main.c"
	rm -rf "printf_main.c"
	rm -rf *"." 
	rm "Makefile"
	mv "_Makefile" "Makefile"
	make && make clean && cp "libftprintf.a" ../ft_printf/ 
else
	echo "err"
	# mv ".main.c" "main.c"
	# mv "printf_main.c" ".printf_main.c"
	# make re && ./printf
fi

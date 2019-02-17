#include "ft_printf.h"
#include <fcntl.h>


void	read_it(int fd, char **line)
{

	char			buff[BUFF_SIZE + 1];
	int				n;

	while ((n = read(fd, buff, BUFF_SIZE)))
		buff[n] = '\0';
	*line = ft_strnew(BUFF_SIZE);
	*line = ft_strjoin((*line), buff);

}

char *parse_str(char *str)
{
	int i = 0;
	int j = 0;

	char *parse1;

	parse1 = ft_strnew(50);
	while(str[i] != ',' && str[i] != '\0')
	{
		if (str[i] == '"')
			i++;
		if (str[i] == ',')
			return(parse1);
		parse1[j] = str[i];
		i++;
		j++;
	}
	return (parse1);
}

char *parse_arg(char *str)
{
	int i = 0;
	int j = 0;

	char *parse2;

	parse2 = ft_strnew(50);
	i = ft_strlen(str) - ft_strlen(ft_strchr(str, ','));
	i +=2;
	while(str[i] != '\0')
	{
		parse2[j] = str[i];
		i++;
		j++;
	}
	return (parse2);
}


int		main(int argc, char *argv[])
{

	
	// char	*line;
	// int		fd;
	// char	*parse1;
	// char	*parse2;

	// argc < 1 ? printf("ERR\n") : 0;

	// fd = open(argv[1], O_RDONLY);
	// read_it(fd, &line);
	// parse1 = parse_str(line);
	// parse2 = parse_arg(line);
	// ft_printf(parse1, parse2);

	argc = 3;
	argv[1] = "tet";
	char c = 'a';
	c++;
	// char *s = NULL;

	// ft_printf("%f\n", 12345.0089);
	// printf("%f\n", 12345.0089);

	// ft_printf("'%#+-11.12f'\n", 10.590);
	// printf("'%#+-11.12f'\n", 10.590);

	// int f = -123;

	// char devochka[] = "moi address";

	// ft_printf("%x\n", 125);

	// printf("'%-#41.4p'\n", &argc);
	// ft_printf("'%-#41.4p'\n", &argc);

	// printf("'%#50.13X'\n", 15);
	// ft_printf("'%#50.13X'\n", 15);

	// printf("'%-3c'\n", 0);
	// ft_printf("'%-3c'\n", 0);

	// printf("'%#-+010.5hx'\n", -10);
	// ft_printf("'%#-+010.5hx'\n", -10);

	// printf("'%#22.18x'\n", -10);
	// ft_printf("'%#22.18x'\n", -10);


	// printf("'%#-010.5x'\n", 10);
	// ft_printf("'%#-010.5x'\n", 10);

	// printf("'%#-+10.10hx'\n", -257);
	// ft_printf("'%#-+10.10hx'\n", -257);


	// printf("%hhx\n", 256);
	// ft_printf("%hhx\n", 256);

// char arr[2][4] = {"kek", NULL};

// 	arr[0] = *arr;
// 	printf("%s\n", arr[1]);
	// printf("|%.o|\n", 0);
	// ft_printf("|%.o|\n", 0);

	// printf("|%.0o|\n", 1);
	// ft_printf("|%.0o|\n", 1);

	// printf("|%.o %.0o %0.o %0.0o|\t\t|%o %.2o %2.o %2.2o|\t\t\t\t\n\n\n\n",0,0,0,0,0,0,0,0);
	// ft_printf("|%.o %.0o %0.o %0.0o|\t\t|%o %.2o %2.o %2.2o|\t\t\t\t",0,0,0,0,0,0,0,0);

	// printf("|%2.2x|\n", 0);
	// ft_printf("|%2.2x|\n", 0);
	// ft_printf("|%15.01s|\n",s);
	// printf("|%15.01s|\n", s);

	// printf("|%-#10o|\n", 8400);
	// ft_printf("|%-#10o|\n", 8400);

	// printf("|%-.8o|\n", 98400);
	// ft_printf("|%-.8o|\n", 98400);

	// printf("|%#6.2o|\t|%#-12.2o|\t|%#.3o|\t\t|%#09.2o|\t|%#02.2o|\n\n\n\n", 8400,8400,0,8400,8400);
	// ft_printf("|%#6.2o|\t|%#-12.2o|\t|%#.3o|\t\t|%#09.2o|\t|%#02.2o|", 8400,8400,0,8400,8400);
	
	// printf("|%.x %.0x %0.x %0.0x|\t\t|%x %.2x %2.x %2.2x|\t\t\t\t\n\n\n\n",0,0,0,0,0,0,0,0); 
	// ft_printf("|%.x %.0x %0.x %0.0x|\t\t|%x %.2x %2.x %2.2x|\t\t\t\t",0,0,0,0,0,0,0,0); 

	// printf("%- .3x\n", 10);
	// ft_printf("%- .3x\n", 10);


	// printf("|%4.o|\n",0);
	// ft_printf("|%4.o|\n",0);

	// printf("|%09.5p|\n", 0);
	// ft_printf("|%09.5p|\n", 0);

	// printf("|%5hho|\t|%5ho|\t|%20lo|\t|%20llo|\t|%10o|\n\n\n", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX);
	// ft_printf("|%5hho|\t|%5ho|\t|%20lo|\t|%20llo|\t|%10o|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX);

	// printf("%x\n", LONG_MAX);
	// ft_printf("%x\n", LONG_MAX);
	// printf("%x\n", LONG_MAX);
	// ft_printf("%x\n", LONG_MAX);

	// printf("%lX, %lX\n\n", 0, ULONG_MAX);
	// ft_printf("%lX, %lX", 0, ULONG_MAX);

	// printf("%llO, %llO\n\n", 0, USHRT_MAX);         //add fucking support
	// ft_printf("%llO, %llO", 0, USHRT_MAX);

	// printf("%llx, %llx\n\n", 0, USHRT_MAX);
	// ft_printf("%llx, %llx", 0, USHRT_MAX);

	// printf("%llo, %llo\n\n", 0, ULLONG_MAX);
	// ft_printf("%llo, %llo", 0, ULLONG_MAX);



	// printf("%0+ 0-10.10x\n", 1234);
	// ft_printf("%0+ 0-10.10x\n", 1234);

	// int i;
	// int y;
	// int g;
	// int y = printf("%o\n", 0);
	// int g = ft_printf("%o\n", 0);
	// char *str = NULL;
	// y = printf("|%#.p|\n", &str);
	// g = ft_printf("|%#.p|\n", &str);


	// y = printf("%p", &i);
	// printf("\n");
	// g = ft_printf("%p", &i);
	// printf("\n");
	// printf("%d %d\n", y, g);

	// printf("|%#.0hho|", 0);

	// printf("%p\n", &i);
	// printf("%lp\n", &i);

	int a = 0;
	int b = 0;

	// printf("%hhO, %hhO", 0, USHRT_MAX);
	// printf("\n");
	// ft_printf("%hhO, %hhO", 0, USHRT_MAX);

	// printf("|%#.0jo|", 0); printf("|% #.0jo|", 0);  
 
 //   printf("|%#.0zo|", 0); printf("|% #.0zo|", 0);

	// printf("|%#5.4ho|", -25); printf("|% #5.4ho|", -25); printf("|%0#5.4ho|", -25); printf("|% 0#5.4ho|", -25)

	// a =  printf("|%#-5.4p|", -25);
	// printf("\n");
	// b = ft_printf("|%#-5.4p|", -25);

	// a =  printf("|%#12.11hhx|", -2147483649);
	// printf("\n");
	// b = ft_printf("|%#12.11hhx|", -2147483649);

// printf("|%0-#ho|", -42)


	printf("|%#ho|", 42);
	printf("\n");
	ft_printf("|%#ho|", 42);

	// printf("|%#-13.12hhx|", 2147483648);
	// printf("\n\n");
	// ft_printf("|%#-13.12hhx|", 2147483648);




	// printf("|%#-13.12hx|", 2147483648);
	// printf("\n");
	// ft_printf("|%#-13.12hx|", 2147483648);
	// printf("%#5.f, %#5.0f", 15.0, 15.0);
	// printf("\n");
	// ft_printf("%#5.f, %#5.0f", 15.0, 15.0);


	// a = printf("{%-13.1p}", &strlen);
	// printf("\n");
	// b = ft_printf("{%-13.1p}", &strlen);


	// PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);



// printf("|%#5.4ho|", -25); printf("|% #5.4ho|", -25); printf("|%0#5.4ho|", -25); printf("|% 0#5.4ho|", -25);
// ft_printf("|%#5.4ho|", -25); ft_printf("|% #5.4ho|", -25); ft_printf("|%0#5.4ho|", -25); ft_printf("|% 0#5.4ho|", -25);


	// printf("%#.o, %#.0o", 0, 0);
	// printf("\n");
	// ft_printf("%#.o, %#.0o", 0, 0);


	// printf("\n");
	// printf("\n");

	// a = printf("|%zX|", -1);
	// printf("\n");
	// b = ft_printf("|%zX|", -1);

		// PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);


// %012x|\t|%-12x|\t|%012x


  // 95. FAIL ft_printf("@moulitest: %#.o %#.0o", 0, 0);    -> "@moulitest: 0 0"


	// a = printf("'%#.o %#.0o'", 0, 0);
	// printf("\n");
	// b = ft_printf("'%#.o %#.0o'", 0, 0);


	// a = printf("@moulitest: %.o %.0o", 0, 0);
	// printf("\n");
	// b = ft_printf("@moulitest: %.o %.0o", 0, 0);

	// a = printf("'%# -1x'", 10);
	// printf("\n");
	// b = ft_printf("'%# -1x'", 10);







	// a = printf("%#.o, %#.0o", 0, 0);
	// printf("\n");
	// b = ft_printf("%#.o, %#.0o", 0, 0);


	// a = printf("%#.o, %#.0o", 0, 0);
	// printf("\n");
	// b = ft_printf("%#.o, %#.0o", 0, 0);






	// a = printf("@moulitest: %#.o %#.0o", 0, 0);
	// printf("\n");
	// b = ft_printf("@moulitest: %#.o %#.0o", 0, 0);


	// printf("'%#- .0p'", 0);
	// printf("\n");
	// ft_printf("'%#- .0p'", 0);

	// a = printf("%#- .0x", 0);
	// printf("\n");
	// b = ft_printf("%#- .0x", 0);


	// printf("@moulitest: %#.o %#.0o", 0, 0);
	// ft_printf("@moulitest: %#.o %#.0o", 0, 0);

	// printf("%.0p, %.p", 0, 0)

	// a = printf("@moulitest: %#.o %#.0o", 0, 0);
	// printf("\n");
	// b = ft_printf("@moulitest: %#.o %#.0o", 0, 0);


	// printf("{%15p}", &a);

	// ft_printf("{%15p}", &a);

	// ft_printf("%hhO, %hhO", 0, USHRT_MAX);

	// a = printf("|%.o|",0);
	// printf("\n");
	// b = ft_printf("|%.o|",0);

	// a = printf("|%.o|",0);
	// printf("\n");
	// b = ft_printf("|%.o|",0);

	// a = printf("|%0.o|",0);
	// printf("\n");
	// b = ft_printf("|%0.o|",0);

	// a = printf("|%0.0o|",0);
	// printf("\n");
	// b = ft_printf("|%0.0o|",0);

	// a = printf("|%.x|",0);
	// printf("\n");
	// b = ft_printf("|%.x|",0);

	// a = printf("|%.2o|",0);
	// printf("\n");
	// b = ft_printf("|%.2o|",0);

	// a = printf("|%2.o|",0);
	// printf("\n");
	// b = ft_printf("|%2.o|",0);

	// a = printf("|%2.2o|",0);
	// printf("\n");
	// b = ft_printf("|%2.2o|",0);

	printf("\n\nor = %d\n", a);
	printf("ft = %d\n", b);



	// printf("|%.o|\n", 0);
	// ft_printf("|%.o|\n", 0);

	// printf("%#X\n", INT_MAX);
	// printf("%.o, %.0o\n", 0, 0);
	// printf("%.x, %.0x\n", 0, 0);
	// printf("%.X, %.0X\n", 0, 0);
	// printf("%#.x, %#.0x\n", 0, 0);
	// printf("%#.x, %#.0x\n", 0, 0);
	// printf("%o\n", LONG_MAX);
	// printf("% .o|%+o\n", 42, 42);
	// printf("%#.o\n", 42);

	// printf("\n\n___________________\n");

	// ft_printf("%#X\n", INT_MAX);
	// ft_printf("%.o, %.0o\n", 0, 0);
	// ft_printf("%.x, %.0x\n", 0, 0);
	// ft_printf("%.X, %.0X\n", 0, 0);
	// ft_printf("%#.x, %#.0x\n", 0, 0);
	// ft_printf("%#.x, %#.0x\n", 0, 0);
	// ft_printf("%o\n", LONG_MAX);
	// ft_printf("% .o|%+o\n", 42, 42);
	// ft_printf("%#.o\n", 42);






	// printf("% x|%+x\n", 42, 42);
	// printf("% X|%+X\n", 42, 42);
	// printf("%.0p, %.p\n", 0, 0);
	// printf("%.5p\n", 0);
	// printf("%2.9p\n", 1234);
	// printf("%2.9p\n", 1234567);
	// printf("%.p, %.0p\n", 0, 0);
	// printf("{%05p}\n", 0);
	// printf("{% 03d}\n", 0);

	// printf("\n\n___________________\n");


	// ft_printf("% x|%+x\n", 42, 42);
	// ft_printf("% X|%+X\n", 42, 42);
	// ft_printf("%.0p, %.p\n", 0, 0);
	// ft_printf("%.5p\n", 0);
	// ft_printf("%2.9p\n", 1234);
	// ft_printf("%2.9p\n", 1234567);
	// ft_printf("%.p, %.0p\n", 0, 0);
	// ft_printf("{%05p}\n", 0);
	// ft_printf("{% 03d}\n", 0);



	// printf("% x|%+x\n", 42, 42);
	// printf("% X|%+X\n", 42, 42);
	// printf("%.0p, %.p\n", 0, 0);
	// printf("%.5p\n", 0);
	// printf("%2.9p\n", 1234);
	// printf("%2.9p\n", 1234567);
	// printf("%.p, %.0p\n", 0, 0);
	// printf("{%05p}\n", 0);


	// printf("\n\n___________________\n");


	// ft_printf("% x|%+x\n", 42, 42);
	// ft_printf("% X|%+X\n", 42, 42);
	// ft_printf("%.0p, %.p\n", 0, 0);
	// ft_printf("%.5p\n", 0);
	// ft_printf("%2.9p\n", 1234);
	// ft_printf("%2.9p\n", 1234567);
	// ft_printf("%.p, %.0p\n", 0, 0);
	// ft_printf("{%05p}\n", 0);













	// printf("%o\n",ULONG_MAX);
	// ft_printf("%o\n",ULONG_MAX);


	// printf("%+-#28.15o\n", 439576934);
	// ft_printf("%+-#28.15o\n", 439576934);

	// ft_printf("'%-#30x'\n", -15);
	// ft_printf("'%+#50.13x'\n", -15);

	// ft_printf("0x%012x\n", (unsigned)&c);

	// print_address_hex(&c);


	// ft_printf("flags test\n|%s, %p, |%d, |%i, %o, %u, %x, %X, \
	// |%hd, |%hi, %ho, %hu, %hx, %hX, |%hhd, |%hhi, %hho, %hhu, %hhx, %hhX, \
	// |%ld, |%li, %lo, %lu, %lx, %lX, |%lld, |%lli, %llo, %llu, %llx, %llX, \
	// %f, %lf,  %Lf, %%");
	// ft_printf("'%-015.2s',\n'%15.4s'\n", "helloworld", "levonka");
	// printf("\n\n'%-015.2s',\n'%15.4s'\n", "helloworld", "levonka");
	// ft_printf("'%-012.9s'\n", "helloworld");
	// printf("'%-012.9s'\n", "helloworld");

	// char *arr;
	// double	d = 233879456233879431.54;
	// arr = ft_ftoa(d, 5);


	// printf("\n\"%x\"\n", 42);


	// ft_printf("\n\"%.30f\"\n", d);

	// printf("%012i\n", -42);		//	bug
	// ft_printf("%012i\n", -42);		//	bug
	// printf("%012i\n", 42);		//	bug
	// ft_printf("%012i\n", 42);		//	bug

	// ft_printf("\n\"%+ .20f\"\n", d);		// bug (d = 233.04)
	// ft_printf("\n\"%+-.f\"\n", d);		// bug (d = -233.04)

	// long	longg = -9223372036854775807LL;
	// unsigned int	ui = UINT_MAX;
	// unsigned long long	ul = ULLONG_MAX + 1;
	// short int	si = SHRT_MIN - 1;
	// signed char		sc = 256;
	// unsigned short		uc = USHRT_MAX + 1;
	// ================================== %d and %i
	// ft_printf("'%30.15u'\n", ui);
	// printf("'%30.15u'\n\n", ui);
	// ft_printf("'%.30llu'\n", ul);
	// printf("'%.30llu'\n\n", ul);
	// ft_printf("'%+10hd'\n", si);
	// printf("'%+10hd'\n\n", si);
	// ft_printf("'%+10hu'\n", uc);
	// printf("'%+10hu'\n\n", uc);
	// ft_printf("'%+10.1hhd'\n", sc);
	// printf("'%+10.1hhd'\n\n", sc);
	// ft_printf("'%30ld'\n", longg);
	// printf("'%30ld'\n\n", longg);
	// ft_printf("'%30.25lld'\n", longg);
	// printf("'%30.25lld'\n\n", longg);
	// ft_printf("'%.30lld'\n", longg);
	// printf("'%.30lld'\n", longg);


	// char a[5] = "Hello";
	// printf("%010s", a);
	// ft_printf("%010s", a);


	// ================================== %d and %i
	// ft_printf("'%6d'\n", INT_MAX + 1);
	// printf("'%6d'\n\n", INT_MAX + 1);
	// ft_printf("'%.6d'\n", 123);
	// printf("'%.6d'\n\n", 123);
	// ft_printf("'%3.6d'\n", 123);
	// printf("'%3.6d'\n\n", 123);
	// ft_printf("'%6.3d'\n", 123);
	// printf("'%6.3d'\n\n", 123);
	// ft_printf("'%6.5d'\n", 123);
	// printf("'%6.5d'\n\n", 123);
	// ft_printf("%.2d", 123);
	// printf("'%.2d'\n\n", 123);
	// ft_printf("%4.6d", 123);
	// printf("'%4.6d'\n\n", 123);
	// printf("================================== FLAGS\n");
	// ft_printf("% d", 123);
	// printf("'% d'\n\n", 123);
	// ft_printf("%0d", 123);
	// printf("'%0d'\n\n", 123);
	// ft_printf("%-d", 123);
	// printf("'%-d'\n\n", 123);
	// ft_printf("'%+d'\n", 123);
	// printf("'%+d'\n\n", 123);
	// ft_printf("% +d", 123);
	// printf("'% +d'\n\n", 123);
	// ft_printf("%- d", 123);
	// printf("'%- d'\n\n", 123);
	// ft_printf("%-6d", 123);
	// printf("'%-6d'\n\n", 123);
	// ft_printf("%-.6d", 123);
	// printf("'%-.6d'\n\n", 123);
	// ft_printf("%-.6d", 123);
	// printf("'%-.6d'\n\n", 123);
	// ft_printf("%-3.6d", 123);
	// printf("'%-3.6d'\n\n", 123);
	// ft_printf("%-6.3d", 123);
	// printf("'%-6.3d'\n\n", 123);
	// ft_printf("%-6.5d", 123);
	// printf("'%-6.5d'\n\n", 123);
	// ft_printf("%-d", 123);
	// printf("'%-d'\n\n", 123);


	// ft_printf("'%-010.5d'\n", 123);
	// printf("'%-010.5d'\n", 123);
	// ft_printf("'%-01.1d'\n", 123);
	// printf("'%-01.1d'\n", 123);
	// ft_printf("% 6.4d", 123);
	// printf("'% 6.4d'\n\n", 123);
	// ft_printf("%6.4d", -123);
	// printf("'%6.4d'\n\n", -123);
	// // ПРОВЕРЕННЫЕ			// 18:48 27
	// ft_printf("%4.6d", -123);
	// printf("'%4.6d'\n\n", -123);
	// ft_printf("%.4d", -123);
	// printf("'%.4d'\n\n", -123);
	// ft_printf("% -0d", -123);
	// printf("'% -0d'\n\n", -123);
	// ft_printf("%+-6.4d", -123);
	// printf("'%+-6.4d'\n\n", -123);
	// ft_printf("% +6.4d", -123);
	// printf("'% +6.4d'\n\n", -123);
	// ft_printf("%+ 6.4d", 123);
	// printf("'%+ 6.4d'\n\n", 123);
	// ft_printf("%+6.5d", 123);
	// printf("'%+6.5d'\n\n", 123);
	// ft_printf("%-010.5d", 123);
	// printf("'%-010.5d'\n\n", 123);
	// ft_printf("%-01.1d", 123);
	// printf("'%-01.1d'\n\n", 123);
	// ft_printf("%d", 123);
	// printf("'%d'\n\n", 123);
	// ft_printf("% +d", 123);
	// printf("'% +d'\n\n", 123);
	// ft_printf("%d", 123);
	// printf("'%d'\n\n", 123);
	// // ПРОВЕРЕННЫЕ
	// ft_printf("%+-6.4d", 123);
	// printf("'%+-6.4d'\n\n", 123);
	// ft_printf("%+-6.6d", 123);
	// printf("'%+-6.6d'\n\n", 123);
	// printf("================================== TO DO \n");



	// printf("%05.5s");
	// ft_printf("%05.1lld");
	// ft_printf("how are u doing? %ld\n", LONG_MAX + 1);
	// printf("how are u doing? %ld\n", LONG_MAX + 1);

// ====================================== SEREGA

	// int *ptr;
	// char *str;


	 // int a;
 	//  uintptr_t uip = (uintptr_t) ((void*) &a);
 	 // printf("address of a = 0x%"PRIXPTR, uip);
 	 // ft_printf("%p\n", uip);





	// int (*ptr_to_main)() = main;
	// for (i=0; i<sizeof ptr_to_main; i++)
	// 	printf("%.2x", ((unsigned char *)&ptr_to_main)[i]);
	// putchar('\n');





	// printf("%x\n", ((unsigned char *)&ptr));
	// printf("%p\n", ptr);


//  	 unsigned char* a = ( unsigned char* )&ptr;
// for( size_t i = 0 ; i < sizeof( *ptr ) ; i++ )
//      printf( "%hhu" , a[i] );


 	// print_memory(ptr, sizeof(ptr));

	// ft_printf("%p\n", &ptr);
	// printf("%p\n", &ptr);
	// printf("%p\n", &str);
	// printf("%0x\n", uip);
	// ft_printf("%+o\n", 123);
	// int x;
	// x = 23123;
	// char *str = "hello";
	// // ft_printf("%x\n", (unsigned long *)x);
	// ft_printf("%x\n", str);
	// printf("%p\n", str);



	// // Declare and initialize an int variable

	// int var = 34;

	// // Declare a pointer to int variable

	// int *ptr;

	// // Initialize ptr to point to variable var

	// ptr = &var;

	 

	// // Access var directly and indirectly

	// printf("\nDirect access, variable var value = var = %d", var);

	// // you can use %p for the pointer memory address directly or

	// // %0x or %0X or %p in hexadecimal representative instead of

	// // %d, just to avoid confusion here

	// printf("\nIndirect access, variable var value = *ptr = %d", *ptr);

	// // Display the address of var two ways

	// printf("\n\nThe memory address of variable var = &var = %p", &var);

	// printf("\nThe memory address of variable var = ptr = %p\n", ptr);





	// int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	// printf("%p\n", tab);
	// print_memory(tab, sizeof(tab)); return (0);









	return (0);
}


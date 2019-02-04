#include "ft_printf.h"
#include <fcntl.h>

// #define BUFF_SIZE 1000

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
	printf("\n\"%x\"\n", 42);
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
	ft_printf("%-10x\n", 123);
	printf("%-10x\n", 123);
	
	return (0);
}
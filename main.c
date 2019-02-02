#include "ft_printf.h"

int		main(void)
{
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

	return (0);
}
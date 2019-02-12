#include "ft_printf.h"
#include <math.h>
#include <limits.h>

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
	// double	d = 2338794562338.54;
	// arr = ft_ftoa(d, 5);




	// {
		// # define CNV "O"
		// printf("\n   |"CNV"|:\n");
		// printf("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX);
		// printf("\n");
		// ft_printf("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX);
		// printf("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN);
		// ft_printf("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN);
	// }

	// {			// просто добавить поддержку большого О
	// 	# define CNV "O"
	// 	printf("\n   |"CNV"|:\n");
	// 	// PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
	// 	PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	// }


// printf("|% .10d|\n", 10);
// ft_printf("|% .10d|\n", 10);





	// ================================== %f
	// printf("'%+f'\n", -1.00 / 0.00);
	// ft_printf("'%+f'\n", -1.00 / 0.00);		// bug
	// printf("'%f'\n", 1.00 / 0.00);
	// ft_printf("'%f'\n", 1.00 / 0.00);
	// printf("'%5.10f'\n", 0.00 / 0.00);
	// ft_printf("'%5.10f'\n", 0.00 / 0.00);
	// printf("\n\"%f\"\n", 0.00 * -1);
	// ft_printf("\n\"%f\"\n", 0.00 * -1);
	// printf("\n\"%.30f\"\n", d);
	// ft_printf("\n\"%.30f\"\n", d);
	// printf("\n'%.2f'\n", 12.4951);
	// ft_printf("\n'%.2f'\n", 12.4951);

	// printf("'%f'\n", 0.00 * -1);	//bug
	// ft_printf("'%f'\n", 0.00 * -1); //bug

	// printf("'%.15f'\n", 10.51000000000);
	// ft_printf("'%.15f'\n", 10.51000000000);

	// printf("%.0f\n", 12.500000000000001);
	// ft_printf("%.0f\n\n", 12.5000000000001);
	// printf("%.0f\n", 12.51);
	// ft_printf("%.0f\n\n", 12.51);
	// printf("%.4f\n", 12.50056);
	// ft_printf("%.4f\n\n", 12.50055);

	// float fValue = 0.2;
	// if (fValue == 2.174444) printf("hiiii");

	// printf("%#X\n", 0xf);
	// ft_printf("%#X\n", 0xf);

	// ft_printf("\n\"%+ .20f\"\n", d);		// bug (d = 233.04)
	// ft_printf("\n\"%+-.f\"\n", d);		// bug (d = -233.04)


	// ================================== %u
	// long	longg = -9223372036854775807LL;
	// unsigned int	ui = UINT_MAX;
	// unsigned long long	ul = ULLONG_MAX + 1;
	// short int	si = SHRT_MIN - 1;
	// signed char		sc = 256;
	// unsigned short		uc = USHRT_MAX + 1;

	// ft_printf("'%30.15u'\n", ui);
	// printf("'%30.15u'\n", ui);
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

	int		a = 0;
	int		b = 0;
	// a = ft_printf("|'%4.6d'|\t|'%d'|\t|'%4.6d'|\n", -123, -123, -123);
	// b = printf("|'%4.6d'|\t|'%d'|\t|'%4.6d'|\n", -123, -123, -123);
	// a = ft_printf("|'%+-6.4d'|\t|'%012i'|\t|'%012i'|\n", -123, -42, 42);
	// b = printf("|'%+-6.4d'|\t|'%012i'|\t|'%012i'|\n", -123, -42, 42);
	// a = ft_printf("|'%6d'|\t|'%.6d'|\t|'%3.6d'|\n", INT_MAX + 1, 123, 123);
	// b = printf("|'%6d'|\t|'%.6d'|\t|'%3.6d'|\n", INT_MAX + 1, 123, 123);
	// a = ft_printf("|'%6.3d'|\t|'%6.5d'|\t|'%.2d'|\t|'%4.6d'|\n", 123, 123, 123, 123);
	// b = printf("|'%6.3d'|\t|'%6.5d'|\t|'%.2d'|\t|'%4.6d'|\n", 123, 123, 123, 123);

	// printf("================================== FLAGS\n");
	// a = ft_printf("|'% d'|\t|'%0d'|\t|'%-d'|\n", 123, 123, 123);
	// b = printf("|'% d'|\t|'%0d'|\t|'%-d'|\n", 123, 123, 123);
	// a = ft_printf("|'%+d'|\t|'% +d'|\t|'%- d'|\n", 123, 123, 123);
	// b = printf("|'%+d'|\t|'% +d'|\t|'%- d'|\n", 123, 123, 123);
	// a = ft_printf("|'%-6d'|\t|'%-.6d'|\t|'%-.6d'|\n", 123, 123, 123);
	// b = printf("|'%-6d'|\t|'%-.6d'|\t|'%-.6d'|\n", 123, 123, 123);
	// a = ft_printf("|'%-3.6d'|\t|'%-6.3d'|\t|'%-6.5d'|\n", 123, 123, 123);
	// b = printf("|'%-3.6d'|\t|'%-6.3d'|\t|'%-6.5d'|\n", 123, 123, 123);
	// a = ft_printf("|'%-d'|\t|'%-010.5d'|\t|'%-01.1d'|\n", 123, 123, 123);
	// b = printf("|'%-d'|\t|'%-010.5d'|\t|'%-01.1d'|\n", 123, 123, 123);
	// a = ft_printf("|'% 6.4d'|\t|'%6.4d'|\t|'% -0d'|\n", 123, 123, 123);
	// b = printf("|'% 6.4d'|\t|'%6.4d'|\t|'% -0d'|\n", 123, 123, 123);
	// a = ft_printf("|'% +6.4d'|\t|'%+ 6.4d'|\t|'%+6.5d'|\n", 123, 123, 123);
	// b = printf("|'% +6.4d'|\t|'%+ 6.4d'|\t|'%+6.5d'|\n", 123, 123, 123);
	// a = ft_printf("|'%-010.5d'|\t|'%-01.1d'|\t|'%d'|\n", 123, 123, 123);
	// b = printf("|'%-010.5d'|\t|'%-01.1d'|\t|'%d'|\n", 123, 123, 123);
	// a = ft_printf("|'% +d'|\t|'%+-6.4d'|\t|'%+-6.6d'|\n", 123, 123, 123);
	// b = printf("|'% +d'|\t|'%+-6.4d'|\t|'%+-6.6d'|\n", 123, 123, 123);

	printf("\n\n%d\n", a);
	printf("%d\n", b);
	// printf("================================== TO DO \n");



	// printf("%05.5s");
	// ft_printf("%05.1lld");
	// ft_printf("how are u doing? %ld\n", LONG_MAX + 1);
	// printf("how are u doing? %ld\n", LONG_MAX + 1);

	// a = ft_printf("||\t||\t||\n");

	return (0);
}
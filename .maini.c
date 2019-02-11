#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int t;
	int t1;
	int z;

// tests int bez minusa i bez flaga 0
// {
// 	z = 10;
// 	t = printf("o1 = |%d|\n", z);
// 	t1 = ft_printf("m1 = |%d|\n", z);
// 	printf("o1 = %d\n",t);
// 	printf("m1 = %d\n",t1);

// 	t = printf("o2 = |%.1d|\n", z);
// 	t1 = ft_printf("m2 = |%.1d|\n", z);
// 	printf("o2 = %d\n",t);
// 	printf("m2 = %d\n",t1);

// 	t = printf("o3 = |%.10d|\n", z);
// 	t1 = ft_printf("m3 = |%.10d|\n", z);
// 	printf("o3 = %d\n",t);
// 	printf("m3 = %d\n",t1);

// 	t = printf("o4 = |%1.d|\n", z);
// 	t1 = ft_printf("m4 = |%1.d|\n", z);
// 	printf("o4 = %d\n",t);
// 	printf("m4 = %d\n",t1);

// 	t = printf("o5 = |%10.10d|\n", z);
// 	t1 = ft_printf("m5 = |%10.10d|\n", z);
// 	printf("o5 = %d\n",t);
// 	printf("m5 = %d\n",t1);

// 	t = printf("o6 = |%10d|\n", z);
// 	t1 = ft_printf("m6 = |%10d|\n", z);
// 	printf("o6 = %d\n",t);
// 	printf("m6 = %d\n",t1);

// 	t = printf("o7 = |%1.1d|\n", z);
// 	t1 = ft_printf("m7 = |%1.1d|\n", z);
// 	printf("o7 = %d\n",t);
// 	printf("m7 = %d\n",t1);

// 	t = printf("o8 = |%1.10d|\n", z);
// 	t1 = ft_printf("m8 = |%1.10d|\n", z);
// 	printf("o8 = %d\n",t);
// 	printf("m8 = %d\n",t1);

// 	t = printf("o9 = |%1.10d|\n", z);
// 	t1 = ft_printf("m9 = |%1.10d|\n", z);
// 	printf("o9 = %d\n",t);
// 	printf("m9 = %d\n",t1);
// }

// tests int s minusom i bez flaga 0
// {
// 	z = 10;
// 	t = printf("o1 = |%-d|\n", z);
// 	t1 = ft_printf("m1 = |%-d|\n", z);
// 	printf("o1 = %d\n",t);
// 	printf("m1 = %d\n",t1);

// 	t = printf("o2 = |%-.1d|\n", z);
// 	t1 = ft_printf("m2 = |%-.1d|\n", z);
// 	printf("o2 = %d\n",t);
// 	printf("m2 = %d\n",t1);

// 	t = printf("o3 = |%-.10d|\n", z);
// 	t1 = ft_printf("m3 = |%-.10d|\n", z);
// 	printf("o3 = %d\n",t);
// 	printf("m3 = %d\n",t1);

// 	t = printf("o4 = |%-1.d|\n", z);
// 	t1 = ft_printf("m4 = |%-1.d|\n", z);
// 	printf("o4 = %d\n",t);
// 	printf("m4 = %d\n",t1);

// 	t = printf("o5 = |%-10.10d|\n", z);
// 	t1 = ft_printf("m5 = |%-10.10d|\n", z);
// 	printf("o5 = %d\n",t);
// 	printf("m5 = %d\n",t1);

// 	t = printf("o6 = |%-10d|\n", z);
// 	t1 = ft_printf("m6 = |%-10d|\n", z);
// 	printf("o6 = %d\n",t);
// 	printf("m6 = %d\n",t1);

// 	t = printf("o7 = |%-1.1d|\n", z);
// 	t1 = ft_printf("m7 = |%-1.1d|\n", z);
// 	printf("o7 = %d\n",t);
// 	printf("m7 = %d\n",t1);

// 	t = printf("o8 = |%-1.10d|\n", z);
// 	t1 = ft_printf("m8 = |%-1.10d|\n", z);
// 	printf("o8 = %d\n",t);
// 	printf("m8 = %d\n",t1);

// 	t = printf("o9 = |%-1.10d|\n", z);
// 	t1 = ft_printf("m9 = |%-1.10d|\n", z);
// 	printf("o9 = %d\n",t);
// 	printf("m9 = %d\n",t1);
// }

//tests int s flagom 0 bez -
// {
// 	z = 10;
// 	t = printf("o1 = |%0d|\n", z);
// 	t1 = ft_printf("m1 = |%0d|\n", z);
// 	printf("o1 = %d\n",t);
// 	printf("m1 = %d\n",t1);

// 	t = printf("o2 = |%0.1d|\n", z);
// 	t1 = ft_printf("m2 = |%0.1d|\n", z);
// 	printf("o2 = %d\n",t);
// 	printf("m2 = %d\n",t1);

// 	t = printf("o3 = |%0.10d|\n", z);
// 	t1 = ft_printf("m3 = |%0.10d|\n", z);
// 	printf("o3 = %d\n",t);
// 	printf("m3 = %d\n",t1);

// 	t = printf("o4 = |%01.d|\n", z);
// 	t1 = ft_printf("m4 = |%01.d|\n", z);
// 	printf("o4 = %d\n",t);
// 	printf("m4 = %d\n",t1);

// 	t = printf("o5 = |%010.10d|\n", z);
// 	t1 = ft_printf("m5 = |%010.10d|\n", z);
// 	printf("o5 = %d\n",t);
// 	printf("m5 = %d\n",t1);

// 	t = printf("o6 = |%010d|\n", z);
// 	t1 = ft_printf("m6 = |%010d|\n", z);
// 	printf("o6 = %d\n",t);
// 	printf("m6 = %d\n",t1);

// 	t = printf("o7 = |%01.1d|\n", z);
// 	t1 = ft_printf("m7 = |%01.1d|\n", z);
// 	printf("o7 = %d\n",t);
// 	printf("m7 = %d\n",t1);

// 	t = printf("o8 = |%01.10d|\n", z);
// 	t1 = ft_printf("m8 = |%01.10d|\n", z);
// 	printf("o8 = %d\n",t);
// 	printf("m8 = %d\n",t1);

// 	t = printf("o9 = |%01.10d|\n", z);
// 	t1 = ft_printf("m9 = |%01.10d|\n", z);
// 	printf("o9 = %d\n",t);
// 	printf("m9 = %d\n",t1);
// }

//tests int s flagom - i s flagom 0
// {
// 	z = 10;
// 	t = printf("o1 = |%-0d|\n", z);
// 	t1 = ft_printf("m1 = |%-0d|\n", z);
// 	printf("o1 = %d\n",t);
// 	printf("m1 = %d\n",t1);

// 	t = printf("o2 = |%-0.1d|\n", z);
// 	t1 = ft_printf("m2 = |%-0.1d|\n", z);
// 	printf("o2 = %d\n",t);
// 	printf("m2 = %d\n",t1);

// 	t = printf("o3 = |%-0.10d|\n", z);
// 	t1 = ft_printf("m3 = |%-0.10d|\n", z);
// 	printf("o3 = %d\n",t);
// 	printf("m3 = %d\n",t1);

// 	t = printf("o4 = |%-01.d|\n", z);
// 	t1 = ft_printf("m4 = |%-01.d|\n", z);
// 	printf("o4 = %d\n",t);
// 	printf("m4 = %d\n",t1);

// 	t = printf("o5 = |%-010.10d|\n", z);
// 	t1 = ft_printf("m5 = |%-010.10d|\n", z);
// 	printf("o5 = %d\n",t);
// 	printf("m5 = %d\n",t1);

// 	t = printf("o6 = |%-010d|\n", z);				// BUUUUUG
// 	t1 = ft_printf("m6 = |%-010d|\n", z);				// BUUUUUG
// 	printf("o6 = %d\n",t);				// BUUUUUG
// 	printf("m6 = %d\n",t1);				// BUUUUUG

// 	t = printf("o7 = |%-01.1d|\n", z);
// 	t1 = ft_printf("m7 = |%-01.1d|\n", z);
// 	printf("o7 = %d\n",t);
// 	printf("m7 = %d\n",t1);

// 	t = printf("o8 = |%-01.10d|\n", z);
// 	t1 = ft_printf("m8 = |%-01.10d|\n", z);
// 	printf("o8 = %d\n",t);
// 	printf("m8 = %d\n",t1);

// 	t = printf("o9 = |%-01.10d|\n", z);
// 	t1 = ft_printf("m9 = |%-01.10d|\n", z);
// 	printf("o9 = %d\n",t);
// 	printf("m9 = %d\n",t1);
// }
// test flag spase
	// z = 10;
	// t = printf("o1 = |% d|\n", z);
	// t1 = ft_printf("m1 = |% d|\n", z);
	// printf("o1 = %d\n",t);
	// printf("m1 = %d\n",t1);

	// t = printf("o2 = |% .1d|\n", z);
	// t1 = ft_printf("m2 = |% .1d|\n", z);
	// printf("o2 = %d\n",t);
	// printf("m2 = %d\n",t1);

	// t = printf("o3 = |% .10d|\n", z);
	// t1 = ft_printf("m3 = |% .10d|\n", z);
	// printf("o3 = %d\n",t);
	// printf("m3 = %d\n",t1);

	// t = printf("o4 = |% 1.d|\n", z);
	// t1 = ft_printf("m4 = |% 1.d|\n", z);
	// printf("o4 = %d\n",t);
	// printf("m4 = %d\n",t1);

	// t = printf("o5 = |% 10.10d|\n", z);
	// t1 = ft_printf("m5 = |% 10.10d|\n", z);
	// printf("o5 = %d\n",t);
	// printf("m5 = %d\n",t1);

	// t = printf("o6 = |% 10d|\n", z);
	// t1 = ft_printf("m6 = |% 10d|\n", z);
	// printf("o6 = %d\n",t);
	// printf("m6 = %d\n",t1);

	// t = printf("o7 = |% 1.1d|\n", z);
	// t1 = ft_printf("m7 = |% 1.1d|\n", z);
	// printf("o7 = %d\n",t);
	// printf("m7 = %d\n",t1);

	// t = printf("o8 = |% 1.10d|\n", z);
	// t1 = ft_printf("m8 = |% 1.10d|\n", z);
	// printf("o8 = %d\n",t);
	// printf("m8 = %d\n",t1);

	// t = printf("o9 = |% 1.10d|\n", z);
	// t1 = ft_printf("m9 = |% 1.10d|\n", z);
	// printf("o9 = %d\n",t);
	// printf("m9 = %d\n",t1);

// //	test flag spase i minus
	// z = 10;
	// t = printf("o1 = |%- d|\n", z);
	// t1 = ft_printf("m1 = |%- d|\n", z);
	// printf("o1 = %d\n",t);
	// printf("m1 = %d\n",t1);

	// t = printf("o2 = |%- .1d|\n", z);
	// t1 = ft_printf("m2 = |%- .1d|\n", z);
	// printf("o2 = %d\n",t);
	// printf("m2 = %d\n",t1);

	// t = printf("o3 = |%- .10d|\n", z);
	// t1 = ft_printf("m3 = |% .10d|\n", z);
	// printf("o3 = %d\n",t);
	// printf("m3 = %d\n",t1);

	// t = printf("o4 = |%- 1.d|\n", z);
	// t1 = ft_printf("m4 = |%- 1.d|\n", z);
	// printf("o4 = %d\n",t);
	// printf("m4 = %d\n",t1);

	// t = printf("o5 = |%- 10.10d|\n", z);
	// t1 = ft_printf("m5 = |%- 10.10d|\n", z);
	// printf("o5 = %d\n",t);
	// printf("m5 = %d\n",t1);

	// t = printf("o6 = |%- 10d|\n", z);
	// t1 = ft_printf("m6 = |%- 10d|\n", z);
	// printf("o6 = %d\n",t);
	// printf("m6 = %d\n",t1);

	// t = printf("o7 = |%- 1.1d|\n", z);
	// t1 = ft_printf("m7 = |%- 1.1d|\n", z);
	// printf("o7 = %d\n",t);
	// printf("m7 = %d\n",t1);

	// t = printf("o8 = |%- 1.10d|\n", z);
	// t1 = ft_printf("m8 = |%- 1.10d|\n", z);
	// printf("o8 = %d\n",t);
	// printf("m8 = %d\n",t1);

	// t = printf("o9 = |%- 1.10d|\n", z);
	// t1 = ft_printf("m9 = |%- 1.10d|\n", z);
	// printf("o9 = %d\n",t);
	// printf("m9 = %d\n",t1);
	
// 	//test flag spase i 0
	// z = 10;
	// t = printf("o1 = |%0 d|\n", z);
	// t1 = ft_printf("m1 = |%0 d|\n", z);
	// printf("o1 = %d\n",t);
	// printf("m1 = %d\n",t1);

	// t = printf("o2 = |%0 .1d|\n", z);
	// t1 = ft_printf("m2 = |%0 .1d|\n", z);
	// printf("o2 = %d\n",t);
	// printf("m2 = %d\n",t1);

	// t = printf("o3 = |%0 .10d|\n", z);
	// t1 = ft_printf("m3 = |%0 .10d|\n", z);
	// printf("o3 = %d\n",t);
	// printf("m3 = %d\n",t1);

	// t = printf("o4 = |%0 1.d|\n", z);
	// t1 = ft_printf("m4 = |%0 1.d|\n", z);
	// printf("o4 = %d\n",t);
	// printf("m4 = %d\n",t1);

	// t = printf("o5 = |%0 10.10d|\n", z);
	// t1 = ft_printf("m5 = |%0 10.10d|\n", z);
	// printf("o5 = %d\n",t);
	// printf("m5 = %d\n",t1);

	// t = printf("o6 = |%0 10d|\n", z);
	// t1 = ft_printf("m6 = |%0 10d|\n", z);
	// printf("o6 = %d\n",t);
	// printf("m6 = %d\n",t1);

	// t = printf("o7 = |%0 1.1d|\n", z);
	// t1 = ft_printf("m7 = |%0 1.1d|\n", z);
	// printf("o7 = %d\n",t);
	// printf("m7 = %d\n",t1);

	// t = printf("o8 = |%0 1.10d|\n", z);
	// t1 = ft_printf("m8 = |%0 1.10d|\n", z);
	// printf("o8 = %d\n",t);
	// printf("m8 = %d\n",t1);

	// t = printf("o9 = |%0 1.10d|\n", z);
	// t1 = ft_printf("m9 = |%0 1.10d|\n", z);
	// printf("o9 = %d\n",t);
	// printf("m9 = %d\n",t1);

// // // tests int plus i bez flaga 0
// {
// 	z = 10;
// 	t = printf("o1 = |%+d|\n", z);
// 	t1 = ft_printf("m1 = |%+d|\n", z);
// 	printf("o1 = %d\n",t);
// 	printf("m1 = %d\n",t1);

// 	t = printf("o2 = |%+.1d|\n", z);
// 	t1 = ft_printf("m2 = |%+.1d|\n", z);
// 	printf("o2 = %d\n",t);
// 	printf("m2 = %d\n",t1);

// 	t = printf("o3 = |%+.10d|\n", z);
// 	t1 = ft_printf("m3 = |%+.10d|\n", z);
// 	printf("o3 = %d\n",t);
// 	printf("m3 = %d\n",t1);

// 	t = printf("o4 = |%+1.d|\n", z);
// 	t1 = ft_printf("m4 = |%+1.d|\n", z);
// 	printf("o4 = %d\n",t);
// 	printf("m4 = %d\n",t1);

// 	t = printf("o5 = |%+10.10d|\n", z);
// 	t1 = ft_printf("m5 = |%+10.10d|\n", z);
// 	printf("o5 = %d\n",t);
// 	printf("m5 = %d\n",t1);

// 	t = printf("o6 = |%+10d|\n", z);
// 	t1 = ft_printf("m6 = |%+10d|\n", z);
// 	printf("o6 = %d\n",t);
// 	printf("m6 = %d\n",t1);

// 	t = printf("o7 = |%+1.1d|\n", z);
// 	t1 = ft_printf("m7 = |%+1.1d|\n", z);
// 	printf("o7 = %d\n",t);
// 	printf("m7 = %d\n",t1);

// 	t = printf("o8 = |%+1.10d|\n", z);
// 	t1 = ft_printf("m8 = |%+1.10d|\n", z);
// 	printf("o8 = %d\n",t);
// 	printf("m8 = %d\n",t1);

// 	t = printf("o9 = |%+1.10d|\n", z);
// 	t1 = ft_printf("m9 = |%+1.10d|\n", z);
// 	printf("o9 = %d\n",t);
// 	printf("m9 = %d\n",t1);
// }

// //tests int s flagom + i s flagom 0
{
	z = 10;
	// t = printf("o1 = |%+0d|\n", z);
	// t1 = ft_printf("m1 = |%+0d|\n", z);
	// printf("o1 = %d\n",t);
	// printf("m1 = %d\n",t1);

	// t = printf("o2 = |%+0.1d|\n", z);
	// t1 = ft_printf("m2 = |%+0.1d|\n", z);
	// printf("o2 = %d\n",t);
	// printf("m2 = %d\n",t1);

	// t = printf("o3 = |%+0.10d|\n", z);
	// t1 = ft_printf("m3 = |%+0.10d|\n", z);
	// printf("o3 = %d\n",t);
	// printf("m3 = %d\n",t1);

	// t = printf("o4 = |%+01.d|\n", z);
	// t1 = ft_printf("m4 = |%+01.d|\n", z);
	// printf("o4 = %d\n",t);
	// printf("m4 = %d\n",t1);

	// t = printf("o5 = |%+010.10d|\n", z);
	// t1 = ft_printf("m5 = |%+010.10d|\n", z);
	// printf("o5 = %d\n",t);
	// printf("m5 = %d\n",t1);

	// t = printf("o6 = |%+010d|\n", z);					// BUGGGGG
	// t1 = ft_printf("m6 = |%+010d|\n", z);					// BUGGGGG
	// printf("o6 = %d\n",t);					// BUGGGGG
	// printf("m6 = %d\n",t1);					// BUGGGGG

	// t = printf("o7 = |%+01.1d|\n", z);
	// t1 = ft_printf("m7 = |%+01.1d|\n", z);
	// printf("o7 = %d\n",t);
	// printf("m7 = %d\n",t1);

	// t = printf("o8 = |%+01.10d|\n", z);
	// t1 = ft_printf("m8 = |%+01.10d|\n", z);
	// printf("o8 = %d\n",t);
	// printf("m8 = %d\n",t1);

	// t = printf("o9 = |%+01.10d|\n", z);
	// t1 = ft_printf("m9 = |%+01.10d|\n", z);
	// printf("o9 = %d\n",t);
	// printf("m9 = %d\n",t1);
}
	return(0);
}
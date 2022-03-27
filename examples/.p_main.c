#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int t;
	int t1;
	int z;

	z = 0;


	printf("TEST \n");
	printf("TEST  HP\n");
	t = printf("o1 = |%d|\n", z);
	t1 = ft_printf("m1 = |%d|\n", z);
	printf("o1 = %d\n",t);
	printf("m1 = %d\n",t1);

	t = printf("o2 = |%1d|\n", z);
	t1 = ft_printf("m2 = |%1d|\n", z);
	printf("o2 = %d\n",t);
	printf("m2 = %d\n",t1);

	t = printf("o3 = |%10d|\n", z);
	t1 = ft_printf("m3 = |%10d|\n", z);
	printf("o3 = %d\n",t);
	printf("m3 = %d\n",t1);

	printf("TEST  + T\n");
	t = printf("o4 = |%.d|\n", z);
	t1 = ft_printf("m4 = |%.d|\n", z);
	printf("o4 = %d\n",t);
	printf("m4 = %d\n",t1);

	t = printf("o5 = |%.1d|\n", z);
	t1 = ft_printf("m5 = |%.1d|\n", z);
	printf("o5 = %d\n",t);
	printf("m5 = %d\n",t1);

	t = printf("o5 = |%.5d|\n", z);
	t1 = ft_printf("m5 = |%.5d|\n", z);
	printf("o5 = %d\n",t);
	printf("m5 = %d\n",t1);

	printf("TEST HP + T\n");

	t = printf("o6 = |%1.1d|\n", z);
	t1 = ft_printf("m6 = |%1.1d|\n", z);
	printf("o6 = %d\n",t);
	printf("m6 = %d\n",t1);

	t = printf("o7 = |%5.1d|\n", z);
	t1 = ft_printf("m7 = |%5.1d|\n", z);
	printf("o7 = %d\n",t);
	printf("m7 = %d\n",t1);

	t = printf("o8 = |%1.5d|\n", z);
	t1 = ft_printf("m8 = |%1.5d|\n", z);
	printf("o8 = %d\n",t);
	printf("m8 = %d\n",t1);

	t = printf("o9 = |%3.5d|\n", z);
	t1 = ft_printf("m9 = |%3.5d|\n", z);
	printf("o9 = %d\n",t);
	printf("m9 = %d\n",t1);

	t = printf("o10 = |%5.3d|\n", z);
	t1 = ft_printf("m10 = |%5.3d|\n", z);
	printf("o10 = %d\n",t);
	printf("m10 = %d\n",t1);

	t = printf("o11 = |%5.5d|\n", z);
	t1 = ft_printf("m11 = |%5.5d|\n", z);
	printf("o11 = %d\n",t);
	printf("m11 = %d\n",t1);

	printf("TEST  + T + FLAG +\n");
	t = printf("o12 = |%+.d|\n", z);
	t1 = ft_printf("m12 = |%+.d|\n", z);
	printf("o12 = %d\n",t);
	printf("m12 = %d\n",t1);

	t = printf("o13 = |%+.1d|\n", z);
	t1 = ft_printf("m13 = |%+.1d|\n", z);
	printf("o13 = %d\n",t);
	printf("m13 = %d\n",t1);

	t = printf("o14 = |%+.5d|\n", z);
	t1 = ft_printf("m14 = |%+.5d|\n", z);
	printf("o14 = %d\n",t);
	printf("m14 = %d\n",t1);

	printf("TEST  + HP + FLAG +\n");
	t = printf("o15 = |%+d|\n", z);
	t1 = ft_printf("m15 = |%+d|\n", z);
	printf("o15 = %d\n",t);
	printf("m15 = %d\n",t1);

	t = printf("o16 = |%+1d|\n", z);
	t1 = ft_printf("m16 = |%+1d|\n", z);
	printf("o16 = %d\n",t);
	printf("m16 = %d\n",t1);

	t = printf("o17 = |%+10d|\n", z);
	t1 = ft_printf("m17 = |%+10d|\n", z);
	printf("o17 = %d\n",t);
	printf("m17 = %d\n",t1);

	printf("TEST  + HP + T + FLAG +\n");

	t = printf("o18 = |%+1.1d|\n", z);
	t1 = ft_printf("m18 = |%+1.1d|\n", z);
	printf("o18 = %d\n",t);
	printf("m18 = %d\n",t1);

	t = printf("o19 = |%+5.1d|\n", z);
	t1 = ft_printf("m19 = |%+5.1d|\n", z);
	printf("o19 = %d\n",t);
	printf("m19 = %d\n",t1);

	t = printf("o19 = |%+1.5d|\n", z);
	t1 = ft_printf("m19 = |%+1.5d|\n", z);
	printf("o19 = %d\n",t);
	printf("m19 = %d\n",t1);

	t = printf("o20 = |%+3.5d|\n", z);
	t1 = ft_printf("m20 = |%+3.5d|\n", z);
	printf("o20 = %d\n",t);
	printf("m20 = %d\n",t1);

	t = printf("o21 = |%+5.3d|\n", z);
	t1 = ft_printf("m21 = |%+5.3d|\n", z);
	printf("o10 = %d\n",t);
	printf("m10 = %d\n",t1);

	t = printf("o22 = |%+5.5d|\n", z);
	t1 = ft_printf("m22 = |%+5.5d|\n", z);
	printf("o22 = %d\n",t);
	printf("m22 = %d\n",t1);

	printf("TEST  + HP + FLAG SPASE\n");
	t = printf("o23 = |% d|\n", z);
	t1 = ft_printf("m23 = |% d|\n", z);
	printf("o23 = %d\n",t);
	printf("m23 = %d\n",t1);

	t = printf("o24 = |% 1d|\n", z);
	t1 = ft_printf("m24 = |% 1d|\n", z);
	printf("o24 = %d\n",t);
	printf("m24 = %d\n",t1);

	t = printf("o25 = |% 10d|\n", z);
	t1 = ft_printf("m25 = |% 10d|\n", z);
	printf("o25 = %d\n",t);
	printf("m25 = %d\n",t1);

	printf("TEST  + T + FLAG SPASE\n");
	t = printf("o26 = |% .d|\n", z);
	t1 = ft_printf("m26 = |% .d|\n", z);
	printf("o26 = %d\n",t);
	printf("m26 = %d\n",t1);

	t = printf("o27 = |% .1d|\n", z);
	t1 = ft_printf("m27 = |% .1d|\n", z);
	printf("o27 = %d\n",t);
	printf("m27 = %d\n",t1);

	t = printf("o28 = |% .5d|\n", z);				// bug
	t1 = ft_printf("m28 = |% .5d|\n", z);				// bug
	printf("o28 = %d\n",t);				// bug
	printf("m28 = %d\n",t1);				// bug

	printf("TEST  + HP + T + FLAG SPASE\n");

	t = printf("o29 = |% 1.1d|\n", z);
	t1 = ft_printf("m29 = |% 1.1d|\n", z);
	printf("o29 = %d\n",t);
	printf("m29 = %d\n",t1);

	t = printf("o30 = |% 5.1d|\n", z);
	t1 = ft_printf("m30 = |% 5.1d|\n", z);
	printf("o30 = %d\n",t);
	printf("m30 = %d\n",t1);

	t = printf("o31 = |% 1.5d|\n", z);					// bug
	t1 = ft_printf("m31 = |% 1.5d|\n", z);					// bug
	printf("o31 = %d\n",t);					// bug
	printf("m31 = %d\n",t1);					// bug

	t = printf("o32 = |% 3.5d|\n", z);					// bug
	t1 = ft_printf("m32 = |% 3.5d|\n", z);					// bug
	printf("o32 = %d\n",t);					// bug
	printf("m32 = %d\n",t1);					// bug

	t = printf("o33 = |% 5.3d|\n", z);
	t1 = ft_printf("m33 = |% 5.3d|\n", z);
	printf("o33 = %d\n",t);
	printf("m33 = %d\n",t1);

	t = printf("o34 = |% 5.5d|\n", z);					// bug
	t1 = ft_printf("m34 = |% 5.5d|\n", z);					// bug
	printf("o34 = %d\n",t);					// bug
	printf("m34 = %d\n",t1);					// bug

	return(0);
}
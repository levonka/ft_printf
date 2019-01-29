#include "ft_printf.h"
#include <inttypes.h>

#include <string.h>

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_ascii(const char *addr, int i)
{
    int j;
    int len;

    j = 0;
    if ((i + 1) % 16 == 0)
        len = 16;
    else
        len = (i + 1) % 16;
    while (j < 16 - len)
    {
        ft_putchar(' ');
        ft_putchar(' ');
        if (j % 2)
            ft_putchar(' ');
        j++;
    }
    if ((16 - len) % 2)
        ft_putchar(' ');
    j = 0;
    while (j < len)
    {
        if (*(addr + i / 16 * 16 + j) >= 32 && *(addr + i / 16 * 16 + j) <= 126)
            ft_putchar(*(addr + i / 16 * 16 + j));
        else
            ft_putchar('.');
        j++;
    }
    ft_putchar('\n');
}

void    print_hex(unsigned char value, int index)
{
    if (index < 2)
    {
        print_hex(value / 16, index + 1);
        if (value % 16 >= 10)
            ft_putchar('a' + value % 16 % 10);
        else
            ft_putchar('0' + value % 16);
    }
}

void    print_memory(const void *addr, size_t size)
{
    char    *ptr;
    size_t  i;

    if (addr && size > 0)
    {
        ptr = (char*)addr;
        i = 0;
        while (i < size)
        {
            print_hex(*(ptr + i), 0);
            if (i % 2)
                ft_putchar(' ');
            if ((i + 1) % 16 == 0 || (i + 1) == size)
                print_ascii(addr, i);
            i++;
        }
    }
}


int		main(void)
{
	// ft_printf("flags test\n%s, %p, %d, %i, %o, %u, %x, %X, \
	// %hd, %hi, %ho, %hu, %hx, %hX, %hhd, %hhi, %hho, %hhu, %hhx, %hhX, \
	// %ld, %li, %lo, %lu, %lx, %lX, %lld, %lli, %llo, %llu, %llx, %llX, \
	// %f, %lf,  %Lf, %%");
	// ft_printf("'%-015.2s', '%15.4s'\n", "helloworld", "levonka");
	// printf("'%-015.2s', '%15.4s'\n", "helloworld", "levonka");
	// ft_printf("'%-012.9s'\n", "helloworld");
	// printf("'%-012.9s'\n", "helloworld");


	// ft_printf("%6d", 123);
	// printf("'%6d'\n\n", 123);
	// ft_printf("%.6d", 123);
	// printf("'%.6d'\n\n", 123);
	// ft_printf("%3.6d", 123);
	// printf("'%3.6d'\n\n", 123);
	// ft_printf("%6.3d", 123);
	// printf("'%6.3d'\n\n", 123);
	// ft_printf("%6.5d", 123);
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
	// ft_printf("%+d", 123);
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

	int *ptr;
	char *str;


	 // int a;
 	//  uintptr_t uip = (uintptr_t) ((void*) &a);
 	 // printf("address of a = 0x%"PRIXPTR, uip);
 	 // ft_printf("%p\n", uip);





	// size_t i;
	// int (*ptr_to_main)() = main;
	// for (i=0; i<sizeof ptr_to_main; i++)
	// 	printf("%.2x", ((unsigned char *)&ptr_to_main)[i]);
	// putchar('\n');


	// for (i=0; i<sizeof ptr; i++)
	// 	ft_printf("%x", ((unsigned char *)&ptr)[i]);
	// putchar('\n');


	// printf("%x\n", ((unsigned char *)&ptr));
	// printf("%p\n", ptr);


//  	 unsigned char* a = ( unsigned char* )&ptr;
// for( size_t i = 0 ; i < sizeof( *ptr ) ; i++ )
//      printf( "%hhu" , a[i] );


 	print_memory(ptr, sizeof(ptr));

	// ft_printf("%p\n", &ptr);
	// printf("%p\n", &ptr);
	// printf("%p\n", &str);
	// printf("%0x\n", uip);


	return (0);
}
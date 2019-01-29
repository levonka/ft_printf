#include "ft_printf.h"
#include <inttypes.h>

#include <string.h>

#include <unistd.h>

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

	// ft_printf("%010d\n", 123450);
	// printf("%010d\n", 123450);


	// int *ptr;

	// int a = 3;

	// ptr = &a;

	// size_t i;

	// while(i < sizeof(ptr))
	// {
		
	// }

	// for (i=0; i<sizeof ptr; i++)
	// 	ft_printf("%x", ((unsigned char *)&ptr)[i]);
	// putchar('\n');

	// printf("'%+8.5X'\n", 30);

	ft_printf("%+12.8X\n", 30101);
	printf("%+12.8X\n", 30101);


	// ft_printf("%.8d\n", 30101);
	// printf("%12.8d\n", 30101);

	// ft_printf("'%010d'\n", 123450); //1st
	// printf("'%010d'\n", 123450);
	
	// ft_printf("'%06d'\n", 12345);
	// printf("'%06d'\n", 12345);

	// print_memory(ptr, 1000);
	// ft_printf("%p\n", ptr);
	// printf("%p\n", ptr);


	// ft_printf("'%6d'\n", 123);
	// printf("'%6d'\n\n", 123);
	// ft_printf("'%.6d'\n", 123);
	// printf("'%.6d'\n\n", 123);
	// ft_printf("'%3.6d'\n", 123);
	// printf("'%3.6d'\n\n", 123);
	// ft_printf("'%6.3d'\n", 123);
	// printf("'%6.3d'\n\n", 123);
	// ft_printf("'%6.5d'\n", 123);
	// printf("'%6.5d'\n\n", 123);
	// ft_printf("'%.2d'\n", 123);
	// printf("'%.2d'\n\n", 123);
	// ft_printf("'%4.6d'\n", 123);
	// printf("'%4.6d'\n\n", 123);
	// printf("================================== FLAGS\n");
	// ft_printf("'% d'\n", 123);
	// printf("'% d'\n\n", 123);
	// ft_printf("'%0d'\n", 123);
	// printf("'%0d'\n\n", 123);
	// ft_printf("'%-d'\n", 123);
	// printf("'%-d'\n\n", 123);
	// ft_printf("'%+d'\n", 123);
	// printf("'%+d'\n\n", 123);

	// ft_printf("'%06d'\n", 12345);
	// printf("%06d\n", 12345);

	// ft_printf("'% +d'\n", 123);
	// printf("'% +d'\n\n", 123);
	// ft_printf("'%- d'\n", 123);
	// printf("'%- d'\n\n", 123);
	// ft_printf("'%-6d'\n", 123);
	// printf("'%-6d'\n\n", 123);
	// ft_printf("'%-.6d'\n", 123);
	// printf("'%-.6d'\n\n", 123);
	// ft_printf("'%-.6d'\n", 123);
	// printf("'%-.6d'\n\n", 123);
	// ft_printf("'%-3.6d'\n", 123);
	// printf("'%-3.6d'\n\n", 123);
	// ft_printf("'%-6.3d'\n", 123);			/////BUG
	// printf("'%-6.3d'\n\n", 123);			/////BUG
	// ft_printf("'%-6.5d'\n", 123);
	// printf("'%-6.5d'\n\n", 123);
	// ft_printf("'%-d'\n", 123);
	// printf("'%-d'\n\n", 123);


	// ft_printf("'%-010.5d'\n", 123);			///bug
	// printf("'%-010.5d'\n", 123);			///bug
	// ft_printf("'%-01.1d'\n", 123);
	// printf("'%-01.1d'\n", 123);
	// ft_printf("'% 6.4d'\n", 123);
	// printf("'% 6.4d'\n\n", 123);
	// ft_printf("'%6.4d'\n", -123);
	// printf("'%6.4d'\n\n", -123);
	// // ПРОВЕРЕННЫЕ			// 18:48 27
	// ft_printf("'%4.6d'\n", -123);
	// printf("'%4.6d'\n\n", -123);
	// ft_printf("'%.4d'\n", -123);
	// printf("'%.4d'\n\n", -123);
	// ft_printf("'% -0d'\n", -123);
	// printf("'% -0d'\n\n", -123);
	// ft_printf("'%+-6.4d'\n", -123);
	// printf("'%+-6.4d'\n\n", -123);
	// ft_printf("'% +6.4d'\n", -123);
	// printf("'% +6.4d'\n\n", -123);
	// ft_printf("'%+ 6.4d'\n", 123);
	// printf("'%+ 6.4d'\n\n", 123);
	// ft_printf("'%+6.5d'\n", 123);
	// printf("'%+6.5d'\n\n", 123);
	// ft_printf("'%-01.1d'\n", 123);
	// printf("'%-01.1d'\n\n", 123);
	// ft_printf("'%d'\n", 123);
	// printf("'%d'\n\n", 123);
	// ft_printf("'% +d'\n", 123);
	// printf("'% +d'\n\n", 123);
	// ft_printf("'%d'\n", 123);	
	// printf("'%d'\n\n", 123);
	// // ПРОВЕРЕННЫЕ
	// ft_printf("'%+-6.4d'\n", 123);
	// printf("'%+-6.4d'\n\n", 123);
	// ft_printf("'%+-6.6d'\n", 123);
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


	return (0);
}
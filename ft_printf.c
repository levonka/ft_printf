/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:35:03 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/25 10:52:52 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	ft_printf("'%5.3d'\n", 123);
	printf("%%5.3d\n'%5.3d'\n", 123);
	// ft_printf("'%-010.5d'\n", 123);
	// printf("'%-010.5d'\n", 123);
	// ft_printf("'%-01.1d'\n", 123);
	// printf("'%-01.1d'\n", 123);
	// ft_printf("'%-015.2c', '%15.4c'\n", 'h', 'a');
	// printf("'%-015.2c', '%15.4c'\n", 'd', 'a');
	ft_printf("'%-012.c'\n", 'c');
	printf("'%-012.c'\n", 'c');
	ft_printf("'%+012.s'\n", "helloworld");
	printf("'%+012.s'\n", "helloworld");
	// printf("%05.5s");
	// ft_printf("%05.1lld");
	// ft_printf("how are u doing? %ld\n", LONG_MAX + 1);
	// printf("how are u doing? %ld\n", LONG_MAX + 1);
	return (0);
}

int		ft_solver(va_list args, const char *format, size_t *i)
{
	t_type	*node;

	node = ft_create_ttr();
	// printf(">i = %zu\n", *i);
	ft_flagssearcher(node, format, i);
	ft_widthsearcher(node, format, i);
	ft_precisionsearcher(node, format, i);
	if (ft_typesearcher(node, format, i) == SUCCESS)
	{
			// ft_diag_print(node);
		ft_print_dispatcher(node, args);
		ft_freenode(node);
		return (SUCCESS);
	}
	else
		printf("SOMETHING WRONG\n");
	// printf("<i = %zu\n\n", *i);
	ft_freenode(node);			//	doesn't work if type not defined
	return (FAIL);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	size_t	i;

	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			ft_solver(args, format, &i);
		}
		else
		{
			ft_putchar(format[i]);
			++i;
		}
	}
	va_end(args);
	return (0);
}

t_type	*ft_create_ttr()
{
	t_type	*ptr;

	ptr = (t_type *)malloc(sizeof(t_type));
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

void	ft_freenode(t_type *node)
{
	free(node->flags);
	free(node->type);
	free(node);
}

void	ft_diag_print(t_type *node)
{
	printf("\n[flags:\t%s]\n", node->flags);
	printf("[width:\t%d]\n", node->width);
	printf("[pre-n:\t%d]\n", node->precision);
	printf("[type:\t%s]\n\n", node->type);
}
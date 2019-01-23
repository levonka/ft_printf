/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:35:03 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/23 12:23:20 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	// ft_printf("flags test\n%s, %p, %d, %i, %o, %u, %x, %X, \
	// %hd, %hi, %ho, %hu, %hx, %hX, %hhd, %hhi, %hho, %hhu, %hhx, %hhX, \
	// %ld, %li, %lo, %lu, %lx, %lX, %lld, %lli, %llo, %llu, %llx, %llX, \
	// %f, %lf,  %Lf, %%");
	ft_printf("%0 +-#48945............4565s");
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
		printf("\n[flags:\t%s]\n", node->flags);
		printf("[width:\t%d]\n", node->width);
		printf("[pre-n:\t%d]\n", node->precision);
		printf("[type:\t%s]\n\n", node->type);
		// ft_print_dispatcher(node, args);
		ft_freenode(node);
		return (SUCCESS);
	}
	else
		printf("SOMETHING WRONG\n");
	// printf("<i = %zu\n\n", *i);
	// ft_freenode(node);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 08:31:19 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/23 11:51:47 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_print_dispatcher(t_type *node, va_list args)
// {
// 	void	*var;

// 	var = va_arg(args, void *);
// 	(ft_strcmp(node->type, "s") == 0) ? ft_putstr(var) : 0;
// 	(ft_strcmp(node->type, "c") == 0) ? ft_putchar((char)var) : 0;
// 	(ft_strcmp(node->type, "d") == 0) ? ft_putnbr_long((int)var) : 0;
// 	(ft_strcmp(node->type, "i") == 0) ? ft_putnbr_long((int)var) : 0;
// 	(ft_strcmp(node->type, "ld") == 0) ? ft_putnbr_long((long)var) : 0;
// }

// void	ft_putnbr_long(long long n)
// {
// 	char	p;

// 	printf("%lld\n", n);
// 	if (n == LONG_MIN)
// 	{
// 		write(1, "-", 1);
// 		write(1, "9", 1);
// 		ft_putnbr_long(223372036854775808);
// 	}
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		ft_putnbr_long(-n);
// 	}
// 	else if (n >= 10)
// 	{
// 		ft_putnbr_long(n / 10);
// 		p = (n % 10) + 48;
// 		write(1, &p, 1);
// 	}
// 	else
// 	{
// 		p = n + 48;
// 		write(1, &p, 1);
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:30:59 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/29 17:42:47 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_abs(intmax_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}


int			ft_nlen(intmax_t n, int base)
{
	size_t		len;

	len = 0;
	if (n == 0)
		return(1);
	while (n)
	{
		len++;
		n = n / base;
	}
	return (len);
}


char		*ft_ntoa_base(uintmax_t n, int base)
{
	char	*res;
	int		len;
	static char	*nums = "0123456789ABCDEF";

	res = NULL;
	len = ft_nlen(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (len && n)
	{
		res[len - 1] = nums[ft_abs(n % base)];
		n = n / base;
		len--;
	}
	return (res);
}

void	ft_ntoa_dispatcher(t_type *node, uintmax_t n, int base)
{
	char *str;


	str = ft_ntoa_base(n, base);

	// printf("%s\n", node->flags);
	ft_print_x(node, str, 0);

	// printf("%s\n", str);
}
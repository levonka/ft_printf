/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:32:22 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/24 11:22:34 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagzero(t_type *node, char *str, int *i)
{
	int flag_minus;
	int flag_zero;

	flag_minus = ft_isflag_in_struct(node, '-');
	flag_zero = ft_isflag_in_struct(node, '0');
	while (*i < node->width)
	{
		if (flag_minus == FAIL)
			str[*i] = (flag_zero == SUCCESS ? '0' : ' ');
		else
			str[*i] = ' ';
		*i = *i + 1;
	}
}

void	ft_flagzero_int(t_type *node, char *str, int *i)
{
	int flag_minus;
	int flag_zero;
	int len;

	flag_minus = ft_isflag_in_struct(node, '-');
	flag_zero = ft_isflag_in_struct(node, '0');
	len = (node->precision > node->width) ? node->precision : node->width;
	printf("len = %d\n", len);
	while (*i < node->precision)
	{
		if (flag_minus == FAIL)
			str[*i] = (flag_zero == SUCCESS ? '0' : ' ');
		else
			str[*i] = ' ';
		*i = *i + 1;
	}
}

void	ft_flagminus(t_type *node, char *to, char *from, int *i)
{
	int		len;
	int		flag_minus;
	int		j;

	j = 0;
	len = ft_strlen(from);
	flag_minus = ft_isflag_in_struct(node, '-');
	if (flag_minus == FAIL)
		while (len >= 0)
		{
			to[*i] = from[len];
			*i = *i - 1;
			len = len - 1;
		}
	else
		while(from[j] != '\0')
		{
			to[j] = from[j];
			++j;
		}
}

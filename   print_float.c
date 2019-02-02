/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     print_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:36:54 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/31 18:12:54 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_float(t_type *node, double n, int i)
{
	int		len;
	int		minus;
	char	*str2;
	char	*str;

	str = ft_ftoa(n, (node->precision) == -1 ? 6 : node->precision);
	minus = ft_isnegative(str);
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1) ||
		(node->precision != -1 && node->precision >= (int)ft_strlen(str) + 1))
	{
		len = ((node->width > node->precision) ? node->width : node->precision);
		str2 = ft_strnew(len + 1);
		ft_zerofiller(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		(minus == 0) ? ft_flagminus_num(str2, len) : 0;
		ft_flagplus_num(node, str2, minus, len);
		write(1, str2, ft_strlen(str2));
		free(str2);
		free(str);
		return ;
	}
	len = ft_strlen(str) + 1;
	(ft_isflag_in_struct(node, ' ') == 0 || ft_isflag_in_struct(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num(str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	write(1, str, ft_strlen(str));
	free(str);
}

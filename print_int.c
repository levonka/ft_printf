/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:34:40 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/24 11:22:15 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(t_type *node, char *str, int i)
{
	int		len;
	char	*str2;

	len = ft_strlen(str);
	if ((node->width != -1 && node->width >= len + 1) ||
		(node->precision != -1 && node->precision >= len + 1))
	{
		str2 = (node->width > node->precision) ? ft_strnew(node->width) : ft_strnew(node->precision);
		ft_flagzero_int(node, str2, &i);
		ft_flagminus(node, str2, str, &i);
		ft_putstr(str2);
		free(str2);
		free(str);
		return ;
	}
	ft_putstr(str);
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:34:59 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/25 10:07:02 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_print_char(t_type *node, int c, int i)
{
	int		len;
	char	converse;
	char	*str2;
	char 	*str;

	str = ft_strnew(1);
	node->precision == 0 ? node->precision = 1 : 0; //strange bug with .{0} precision
	converse = c;
	str[0] = converse;
	len = ft_strlen(str);
	while (node->precision <= len && node->precision != -1)
	{
		str[len] = '\0';
		--len;
	}
	if (node->width != -1 && node->width >= len + 1)
	{
		str2 = ft_strnew(node->width);
		ft_flagzero(node, str2, &i);
		ft_flagminus(node, str2, str, &i);
		ft_putstr(str2);
		free(str2);
		return ;
	}
	ft_putstr(str);
	free(str);
}

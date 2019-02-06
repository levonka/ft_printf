/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oxp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:20:48 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/06 11:09:39 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void hashtag_mode(char *str)
{
	int i;

	i = 0;
	printf("%s\n", str);
	while((str[i] == '0' || str[i] == ' ') && str[i] != '\0')
		i++;
	// printf("%d\n", i);
	str[i-2] = '0';
	str[i-1] = 'x';
}

void	ft_print_x(t_type *node, char *str, int i)
{
	int		len;
	int		minus;
	char	*str2;

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
		ft_isflag_in_struct(node, '#') == SUCCESS ? hashtag_mode(str2) : 0;
		ft_putstr(str2);
		free(str2);
		free(str);
		return ;
	}
	len = ft_strlen(str) + 1;
	(ft_isflag_in_struct(node, ' ') == 0 || ft_isflag_in_struct(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num(str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	ft_putstr(str);
	free(str);
}

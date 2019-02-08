/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:34:59 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/08 12:32:14 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fl_zero(t_type *node, char *str, int *i, int c)
{
	int flag_minus;
	int flag_zero;
	int flag_mod;

	flag_minus = ft_isflag_in_struct(node, '-');
	flag_zero = ft_isflag_in_struct(node, '0');
	flag_mod = 0;
	if (c == 0)
		flag_mod += 1;

	while (*i < node->width - flag_mod)
	{
		if (flag_minus == FAIL)
			str[*i] = (flag_zero == SUCCESS ? '0' : ' ');
		else
			str[*i] = ' ';
		*i = *i + 1;
	}
}

static void	fl_minus(t_type *node, char *to, char *from, int *i)
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

int	ft_print_char(t_type *node, int c, int i)
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
		fl_zero(node, str2, &i, c);
		fl_minus(node, str2, str, &i);
		ft_putstr(str2);
		len = ft_strlen(str2);
		free(str2);
		return (len);
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

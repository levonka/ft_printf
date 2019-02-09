/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:36:54 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/09 11:33:46 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_zerofiller2(t_type *node, char *str, int len, int *i)
{
	while (*i < len)
	{
		if ((ft_isflag_in_struct(node, '0') == SUCCESS))
			str[*i] = ((ft_isflag_in_struct(node, '-') && node->width < node->precision) || node->precision == -1) ? ' ' : ' ';
		else
			str[*i] = ' ';
		*i = *i + 1;
	}
}

static int	ft_print_fconst(t_type *node, char *str, int i)
{
	char	*str2;
	int		len;

	if (str[0] == '-')
		turnoff_fl(node->flags, ' ');
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1))
	{
		len = node->width;
		str2 = ft_strnew(len);
		ft_zerofiller2(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		write(1, str2, ft_strlen(str2));
		free(str2);
		free(str);
		return (10);
	}
	len = ft_strlen(str) + 1;
	(ft_isflag_in_struct(node, ' ') == 0 || ft_isflag_in_struct(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	write(1, str, ft_strlen(str));
	free(str);
	return (0);
}

static int	is_const(char *str)
{
	const char base[][5] = { "inf", "-inf", "nan", "" };
	int		i;

	i = 0;
	while (ft_strcmp(base[i], "") != 0)
	{
		if (ft_strcmp(base[i], str) == 0)
			return (SUCCESS);
		i++;
	}
	return (FAIL);
}

void	ft_print_float(t_type *node, double n, int i)
{
	int		len;
	int		minus;
	char	*str2;
	char	*str;

	str = ft_ftoa(n, ((node->precision) == -1) ? 6 : node->precision);
	// printf("'>%s'\n", str);
	if (is_const(str) == SUCCESS)
	{
		ft_print_fconst(node, str, i);
		return ;
	}
	minus = ft_isnegative(str);
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1))
	{
		len = ((node->width > node->precision) ? node->width : node->precision);
		str2 = ft_strnew(len + 1);
		ft_zerofiller(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		(minus == 0) ? ft_flagminus_num(node, str2, len) : 0;
		ft_flagplus_num(node, str2, minus, len);
		write(1, str2, ft_strlen(str2));
		free(str2);
		free(str);
		return ;
	}
	len = ft_strlen(str) + 1;
	(ft_isflag_in_struct(node, ' ') == 0 || ft_isflag_in_struct(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num(node, str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	write(1, str, ft_strlen(str));
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:36:54 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/18 09:50:13 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_zerofiller2(t_type *node, char *str, int len, int *i)
{
	while (*i < len)
	{
		if (ft_isfl_in(node, '0') == 0)
			str[*i] = (ft_isfl_in(node, '-') == 0 && (node->width < node->precision || node->precision == -1)) ? ' ' : ' ';
		else
			str[*i] = ' ';
		*i = *i + 1;
	}
}

static void	ft_zerofiller3(t_type *node, char *str, int len, int i)
{
	int		sp;

	sp = ft_isfl_in(node, ' ') == -1;
	if (ft_isfl_in(node, '0') == 0 && ft_isfl_in(node, '-') == -1)
	{
		while (i < len)
		{
			str[i] = '0';
			i++;
		}
		if (sp == 0)
			str[0] = ' ';
	}
}

static int		ft_isnegative2(char *str)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
		if (str[i++] == '-')
		{
			flag = 1;
			break ;
		}
	i = 0;
	if (flag == 1)
		return (SUCCESS);
	return (FAIL);
}

static int	ft_print_fconst(t_type *node, char *str, int i)
{
	char	*str2;
	int		len;
	int		minus;

	minus = ft_isnegative2(str);
	if (str[0] == '-' || ft_isfl_in(node, '+') == 0)
		turnoff_fl(node->flags, ' ');
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1))
	{
		len = node->width;
		str2 = ft_strnew(len);
		ft_zerofiller2(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		((ft_isfl_in(node, ' ') == 0) || (ft_isfl_in(node, '+') == 0)) &&
			str2[0] != ' ' && (ft_isfl_in(node, ' ') == 0) && ft_strcmp(str, "nan") != 0 ? ft_flagsp_num(str2, len) : 0;
		ft_flagplus_num(node, str2, minus, len);
		if (cmp(node->type, "F") || cmp(node->type, "lF") || cmp(node->type, "LF"))
			str2upcase(str2);
		if (len < (int)ft_strlen(str2) && str2[ft_strlen(str2) - 1] == ' ')
			str2[len] = '\0';
		write(1, str2, ft_strlen(str2));
		free(str2);
		free(str);
		return (len);
	}
	len = ft_strlen(str) + 1;
	ft_flagsp_num(str, len);
	if (cmp(node->type, "F") || cmp(node->type, "lF") || cmp(node->type, "LF"))
		str2upcase(str);
	ft_flagplus_num(node, str, minus, len);
	write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

static void		ft_flagminus_num2(char *str, int len)
{
	int		i;

	i = 0;
	if (ft_isdigit(str[0]))
	{
		len -= (str[ft_strlen(str) - 1] == ' ') ? 1 : 0;
		while (len > 0)
		{
			ft_swap(&str[len], &str[len - 1]);
			--len;
		}
		str[len] = '-';
	}
	else
	{
		while (str[i] == ' ' && str[i] != '0' && str[i] != '\0')
			i++;
		str[i - 1] = '-';
	}
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

int			ft_print_float(t_type *node, double n, int i)
{
	int		len;
	int		minus;
	char	*str2;
	char	*str;

 	str = ft_ftoa(n, (((node->precision) == -1) ? 6 : node->precision), node);
	if (is_const(str) == SUCCESS)
		return (ft_print_fconst(node, str, i));
	minus = ft_isnegative(str);
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1))
	{
		node->zero = (cmp(str, "0") == 1 || cmp(str, "0.") == 1);
		len = ((node->width > (int)ft_strlen(str)) ? node->width : ft_strlen(str));
		str2 = ft_strnew(len + 3);
		ft_zerofiller(node, str2, len, &i);
		ft_zerofiller3(node, str2, len, 0);
		ft_fillin_num(node, str2, str, len);
		(node->precision < node->width && ft_isfl_in(node, '-') == -1) ? turnoff_fl(node->flags, ' ') : 0;
		(ft_isfl_in(node, ' ') == 0) ? ft_flagsp_num(str2, len) : 0;
		if ((minus == 0 && str2[0] == '0' && node->zero == 0) || (ft_isfl_in(node, '+') == 0 && ft_isfl_in(node, '0') == 0))
			str2[0] = '-';
		else if (minus == 0)
			ft_flagminus_num(node, str2, len);
		ft_flagplus_num(node, str2, minus, len);
		len = (node->width > node->precision) ? node->width : node->precision;
		if (len < (int)ft_strlen(str2) && str2[ft_strlen(str2) - 1] == ' ')
			str2[len] = '\0';
		len = ft_strlen(str2);
		write(1, str2, ft_strlen(str2));
		free(str2);
		free(str);
		return (len);
	}
	len = ft_strlen(str) + 1;
	(ft_isfl_in(node, ' ') == 0 || ft_isfl_in(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num2(str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}

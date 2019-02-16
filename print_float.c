/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:36:54 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/16 15:06:10 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_zerofiller2(t_type *node, char *str, int len, int *i)
{
	// printf("%d\n", len);
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
	// printf("%d\n", i);
	// printf("|% 0+20.f|", 102420484096.0);
	if (ft_isfl_in(node, '0') == 0 && ft_isfl_in(node, '-') == -1)
	{
		while (i < len)
		{
			str[i] = '0';
			i++;
		}
	}
}

static int	ft_print_fconst(t_type *node, char *str, int i)
{
	char	*str2;
	int		len;

	if (str[0] == '-' || ft_isfl_in(node, '+') == 0)
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
	// (ft_isfl_in(node, ' ') == 0 || ft_isfl_in(node, '+') == 0) ?
	// ft_flagsp_num(str, len) : 0;
	// printf(">'%s'\n", str);
	write(1, str, ft_strlen(str));
	free(str);
	return (0);
}

void		ft_flagminus_num2(char *str, int len)
{
	int		i;

	i = 0;
	// if (str[0] == '0' && node->precision == -1)
	// {
		// str[0] = '-';
		// printf(">>>>%s\n", str);
	// }
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

// int		ft_print_float(t_type *node, double n, int i)
// {
// 	int		len;
// 	int		minus;
// 	char	*str2;
// 	char	*str;

// 	str = ft_ftoa(n, ((node->precision) == -1) ? 6 : node->precision);
// 	if (is_const(str) == SUCCESS)
// 	{
// 		ft_print_fconst(node, str, i);
// 		len = ft_strlen(str);
// 		free(str);
// 		return (len);
// 	}
// 	minus = ft_isnegative(str);
// 	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1))
// 	{
// 		len = ((node->width > node->precision) ? node->width : node->precision);
// 		str2 = ft_strnew(len + 1);
// 		ft_zerofiller(node, str2, len, &i);
// 		ft_fillin_num(node, str2, str, len);
// 		(minus == 0) ? ft_flagminus_num(node, str2, len) : 0;
// 		ft_flagplus_num(node, str2, minus, len);
// 		write(1, str2, ft_strlen(str2));
// 		len = ft_strlen(str2);
// 		free(str2);
// 		free(str);
// 		return (len);
// 	}
// 	len = ft_strlen(str) + 1;
// 	(ft_isfl_in(node, ' ') == 0 || ft_isfl_in(node, '+') == 0) ?
// 	ft_flagsp_num(str, len) : 0;
// 	(minus == 0) ? ft_flagminus_num2(str, len) : 0;
// 	// printf("str = '%s'\n", str);
// 	ft_flagplus_num(node, str, minus, len);
// 	write(1, str, ft_strlen(str));
// 	len = ft_strlen(str);
// 	free(str);
// 	return (len);
// }


int			ft_print_float(t_type *node, double n, int i)
{
	int		len;
	int		minus;
	char	*str2;
	char	*str;


 	str = ft_ftoa(n, (((node->precision) == -1) ? 6 : node->precision), node);
	// printf(">>>'%s'\n", str);
	if (is_const(str) == SUCCESS)
	{
		ft_print_fconst(node, str, i);
		len = ft_strlen(str);
		// free(str);
		return (len);
	}
	// if (cmp(str, "0") && (node->precision == 0))
	// 	str[0] = '\0';
	minus = ft_isnegative(str);
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1))
		// (node->precision != -1 && node->precision >= (int)ft_strlen(str) + 1))
	{
		node->zero = (cmp(str, "0") == 1);
		len = ((node->width > (int)ft_strlen(str)) ? node->width : ft_strlen(str));
		str2 = ft_strnew(len + 2);
		ft_zerofiller(node, str2, len, &i);
		ft_zerofiller3(node, str2, len, 0);
		ft_fillin_num(node, str2, str, len);
		(node->precision < node->width && ft_isfl_in(node, '-') == -1) ? turnoff_fl(node->flags, ' ') : 0;
		(ft_isfl_in(node, ' ') == 0) ? ft_flagsp_num(str2, len) : 0;
		// printf("<<'%s'\n", str2);
		(minus == 0) ? ft_flagminus_num(node, str2, len) : 0;
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
	// printf("str = '%s'\n", str);
	ft_flagplus_num(node, str, minus, len);
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}

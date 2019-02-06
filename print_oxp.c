/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oxp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:20:48 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/06 13:27:53 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	shift_npos(char *str, int n)
{
	int i;
	int j;

	// printf("\n%s\n\n", str);
	i = 0;
	j = 0;
	while(n > 0)
	{
		while (str[i] != ' ')
			i++;
		j = i;
		while(i >= 0 && str[i - 1] != ' ')
		{
			ft_swap(&str[i - 1], &str[i]);
			i--;
		}
		n--;
		i++;
	}
}

static char	*expand_str(char *str)
{
	char *exp;
	int i;

	i = 0;
	// printf("YO\n");
	exp = ft_strnew(ft_strlen(str) + 2);
	exp[i++] = '0';
	exp[i++] = 'x';
	while (*str)
	{
		exp[i] = *str;
		str++;
		i++;
	}
	exp[i] = '\0';
	return (exp);
}

static char *hashtag_mode(char *str, t_type *node)
{
	int i;
	// char *ox;

	i = 0;
	// printf("%s\n", str);
	while(str[i] == ' ' && str[i] != '\0')
		i++;
	// printf("%d\n", i);
	if (i < 3)
	{
		if (str[0] != '0' && str[1] != '0')
		{
			shift_npos(str, 2);
			str[0] = '0';
			str[1] = 'x';
		}
		else
		{
			if (node->precision < node->width)
			{
				// printf(">>%s\n", str);
				str[0] = '0';
				str[1] = 'x';				
			}

			else
				return (expand_str(str));	
			// str[0] = '0';
			// str[1] = 'x';
		}

	}
	else
	{
		str[i-2] = '0';
		str[i-1] = 'x';
		
	}
	return (str);
}

static void	ft_print_x_ex(t_type *node, char *str, int minus)
{
	int len;

	len = ft_strlen(str) + 1;
	// printf("HIJ\n");
	(ft_isflag_in_struct(node, ' ') == 0 || ft_isflag_in_struct(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num(node, str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	ft_putstr(str);
	free(str);
}

static void	ft_hashtag(t_type *node, char *str, int len)
{
	int		i;

	i = 0;
	if (str[0] == '0' && node->precision == -1)
		str[0] = '-';
	else if (ft_isdigit(str[0]))
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

void	ft_print_x(t_type *node, char *str, int i)
{
	int		len;
	int		minus;
	char	*str2;

	minus = ft_isnegative(str);
	// printf(">%s\n", minus);
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1) ||
		(node->precision != -1 && node->precision >= (int)ft_strlen(str) + 1))
	{
		len = ((node->width > node->precision) ? node->width : node->precision);
		str2 = ft_strnew(len + 3);
		ft_zerofiller(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		(minus == 0) ? ft_flagminus_num(node, str2, len) : 0;
		ft_flagplus_num(node, str2, minus, len);
		ft_isflag_in_struct(node, '#') == SUCCESS ? str2 = hashtag_mode(str2, node) : 0;
		ft_putstr(str2);
		free(str2);
		free(str);
		return ;
	}
	ft_print_x_ex(node, str, minus);
}

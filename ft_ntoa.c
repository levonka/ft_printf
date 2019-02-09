/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:30:59 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/09 15:31:32 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add0x(char *str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (ft_isprint(str[i]))
		i++;
	str[i] = ' ';
	str[++i] = ' ';
	while (len < 2)
	{
		j = i + 1;
		while (--j > 0)
			ft_swap(&str[j], &str[j - 1]);
		len++;
	}
	str[0] = '0';
	str[1] = 'x';
	str[ft_strlen(str)] = '\0';
}

static char		*ntoa_xflags(t_type *node, char *n, int base)
{
	if (!ft_strchr(node->type, 'h'))
	{
		if ((int)n < 0)
			return (ft_ntoa_base((unsigned long int)n, base));
		else
			return (ft_ntoa_base((int)n, base));
	}
	else
	{
		if (cmp(node->type, "hx"))
		{
			if ((int)n < 0)
				return (ft_ntoa_base((unsigned short)n, base));
			else
				return (ft_ntoa_base((unsigned short)n, base));
		}
		else
		{
			if ((int)n < 0)
				return (ft_ntoa_base((unsigned char)n, base));
			else
				return (ft_ntoa_base((unsigned char)n, base));
		}
	}
}

static char		*ntoa_oflags(t_type *node, char *n, int base)
{
	if (!ft_strchr(node->type, 'h'))
	{
		if ((int)n < 0)
			return (ft_ntoa_base((unsigned long int)n, base));
		else
			return (ft_ntoa_base((int)n, base));
	}
	else
	{
		if (cmp(node->type, "ho"))
		{
			if ((int)n < 0)
				return (ft_ntoa_base((unsigned short)n, base));
			else
				return (ft_ntoa_base((unsigned short)n, base));
		}
		else
		{
			if ((int)n < 0)
				return (ft_ntoa_base((unsigned char)n, base));
			else
				return (ft_ntoa_base((unsigned char)n, base));
		}
	}
}

int				ft_ntoa_dispatcher(t_type *node, char *n, int base)
{
	char *str;

	str = NULL;
	turnoff_fl(node->flags, '+');
	node->precision > 0 ? turnoff_fl(node->flags, '0') : 0;
	if (ft_strchr(node->type, 'x') || ft_strchr(node->type, 'X'))
		str = ntoa_xflags(node, n, base);
	else if (cmp(node->type, "p"))
	{
		turnoff_fl(node->flags, ' ');
		turnoff_fl(node->flags, '+');
		turnoff_fl(node->flags, '#');
		str = ft_ntoa_base((unsigned long int)n, base);
		add0x(str);
	}
	else if (cmp(node->type, "b"))
		str = ft_ntoa_base((unsigned long int)n, base);
	else if (ft_strchr(node->type, 'o') || ft_strchr(node->type, 'O'))
		str = ntoa_oflags(node, n, base);
	return (ft_print_x(node, str, 0));
}

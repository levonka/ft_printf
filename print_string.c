/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:13:33 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/08 17:01:33 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagzero(t_type *node, char *str, int *i)
{
	int flag_minus;
	int flag_zero;

	flag_minus = ft_isflag_in_struct(node, '-');
	flag_zero = ft_isflag_in_struct(node, '0');
	while (*i < node->width)
	{
		if (flag_minus == FAIL)
			str[*i] = (flag_zero == SUCCESS ? '0' : ' ');
		else
			str[*i] = ' ';
		*i = *i + 1;
	}
}

void	ft_flagminus(t_type *node, char *to, char *from, int *i)
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
		while (from[j] != '\0')
		{
			to[j] = from[j];
			++j;
		}
}

int		ft_print_string(t_type *node, char *str, int i)
{
	int		len;
	char	*str2;

	str = ft_strdup((str == NULL) ? "(null)" : str);
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
		len = ft_strlen(str2);
		free(str2);
		free(str);
		return (len);
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

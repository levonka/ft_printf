/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 08:31:19 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/23 17:52:36 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_findflag(t_type *node, char c)
{
	int		i;

	i = 0;
	while (node->flags[i] != '\0')
	{
		if (node->flags[i] == c)
			return (SUCCESS);
		++i;
	}
	return (FAIL);
}

void	ft_print_string(t_type *node, char *str, int i)
{
	int		len;
	char	*str2;

	len = ft_strlen(str) - 1;
	while (node->precision <= len && node->precision != -1)
		str[len--] = '\0';
	if (node->width != -1 && node->width >= len + 1)
	{
		str2 = ft_strnew(node->width);
		while (++i < node->width)
			if (ft_findflag(node, '-') == FAIL)
				str2[i] = ft_findflag(node, '0') == SUCCESS ? '0' : ' ';
			else
				str2[i] = ' ';
		if (ft_findflag(node, '-') == FAIL)
			while (len >= 0)
				str2[i--] = str[len--];
		else
			ft_strncpy(str2, str, len + 1);
		ft_putstr(str2);
		free(str2);
		return ;
	}
	ft_putstr(str);
	free(str);
}

void	ft_print_dispatcher(t_type *node, va_list args)
{
	if (ft_strcmp(node->type, "s") == 0)
		ft_print_string(node, ft_strdup(va_arg(args, char *)), -1);
}

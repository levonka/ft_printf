/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:13:33 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/24 08:14:07 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (ft_isflag_in_struct(node, '-') == FAIL)
				str2[i] = ft_isflag_in_struct(node, '0') == SUCCESS ? '0' : ' ';
			else
				str2[i] = ' ';
		if (ft_isflag_in_struct(node, '-') == FAIL)
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

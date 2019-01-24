/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:32:22 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/24 09:32:40 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagzero(t_type *node, char *str, int *i)
{
	while (*i < node->width)
	{
		if (ft_isflag_in_struct(node, '-') == FAIL)
			str[*i] = ft_isflag_in_struct(node, '0') == SUCCESS ? '0' : ' ';
		else
			str[*i] = ' ';
		*i = *i + 1;
	}
}

void	ft_flagminus(t_type *node, char *to, char *from, int *i)
{
	int		len;

	len = ft_strlen(from) - 1;
	if (ft_isflag_in_struct(node, '-') == FAIL)
		while (len >= 0)
		{
			to[*i] = from[len];
			*i = *i - 1;
			len = len - 1;
		}
	else
		ft_strncpy(to, from, len + 1);
}

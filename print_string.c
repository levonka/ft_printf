/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:13:33 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/25 10:53:05 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_type *node, char *str, int i)
{
	int		len;
	char	*str2;

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
		free(str2);
		free(str);
		return ;
	}
	ft_putstr(str);
	free(str);
}

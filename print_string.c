/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:13:33 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/07 17:50:49 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

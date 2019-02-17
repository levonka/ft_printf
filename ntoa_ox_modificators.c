/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntoa_ox_modificators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:28:32 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/17 14:48:02 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ntoa_xflags(t_type *node, char *n, int base)
{
	if (cmp(node->type, "x") || cmp(node->type, "X"))
		return (ft_ntoa_base((unsigned int)n, base));
	else if (cmp(node->type, "lx") || cmp(node->type, "lX"))
		return (ft_ntoa_base((unsigned long int)n, base));
	else if (ft_strchr(node->type, 'z'))
		return (ft_ntoa_base((size_t)n, base));
	else if (ft_strchr(node->type, 'j'))
		return (ft_ntoa_base((uintmax_t)n, base));
	else if (!ft_strchr(node->type, 'h'))
		return (ft_ntoa_base((unsigned long int)n, base));
	else
	{
		if (cmp(node->type, "hx") || cmp(node->type, "hX"))
			return (ft_ntoa_base((unsigned short)n, base));
		else
			return (ft_ntoa_base((unsigned char)n, base));
	}
}

static char		*ntoa_oflags_ext(t_type *node, char *n, int base)
{
	if (cmp(node->type, "ho") || cmp(node->type, "ho$"))
		return (ft_ntoa_base((unsigned short)n, base));
	else if (cmp(node->type, "hO") || cmp(node->type, "hhO") ||
		cmp(node->type, "hO$") || cmp(node->type, "hhO$"))
		return (ft_ntoa_base((unsigned long)n, base));
	else
		return (ft_ntoa_base((unsigned char)n, base));
}

char			*ntoa_oflags(t_type *node, char *n, int base)
{
	if (cmp(node->type, "o") || cmp(node->type, "o$"))
		return (ft_ntoa_base((unsigned int)n, base));
	else if (cmp(node->type, "O"))
		return (ft_ntoa_base((unsigned long)n, base));
	else if (cmp(node->type, "lo") || cmp(node->type, "llo") ||
		cmp(node->type, "lO") || cmp(node->type, "llO"))
		return (ft_ntoa_base((long)n, base));
	else if (ft_strchr(node->type, 'z'))
		return (ft_ntoa_base((size_t)n, base));
	else if (ft_strchr(node->type, 'j'))
		return (ft_ntoa_base((uintmax_t)n, base));
	if (!ft_strchr(node->type, 'h'))
	{
		if ((int)n < 0)
			return (ft_ntoa_base((unsigned long int)n, base));
		else
			return (ft_ntoa_base((int)n, base));
	}
	else
		return (ntoa_oflags_ext(node, n, base));
}

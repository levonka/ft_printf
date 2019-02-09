/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:43:54 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/08 17:19:26 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_swap(char *a, char *b)
{
	char	buff;

	buff = *a;
	*a = *b;
	*b = buff;
}

void	ft_addflag(t_type *node, char flag)
{
	int		i;

	i = 0;
	if (ft_isflag_in_struct(node, flag) == FAIL)
	{
		while (node->type[i] != '\0')
			++i;
		node->type[i] = flag;
	}
}

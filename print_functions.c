/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 08:31:19 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/25 12:33:38 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_dispatcher(t_type *node, va_list args)
{
	if (ft_strcmp(node->type, "s") == 0)
		ft_print_string(node, ft_strdup(va_arg(args, char *)), 0);
	else if (ft_strcmp(node->type, "c") == 0)
		ft_print_char(node, va_arg(args, int), 0);
	else if (ft_strcmp(node->type, "x") == 0)
		ft_print_hex(node, va_arg(args, int), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 08:31:19 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/24 09:10:23 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_dispatcher(t_type *node, va_list args)
{
	if (ft_strcmp(node->type, "s") == 0)
		ft_print_string(node, ft_strdup(va_arg(args, char *)), 0);
}

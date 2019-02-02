/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:49:44 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/30 17:35:39 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.c"
#include <ctype.h>

double	ft_atof(char *s)
{
	double	val, power;
	int		i, sign;

	i = 0;
	val = 0.0;
	power = 1.0;
	while (s[i] >= 0 && s[i] <= 32)
		++i;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;
	while (isdigit(s[i]))
	{
		val = 10.0 * val + (s[i] - '0');
		++i;
	}
	if (s[i] == '.')
		++i;
	while (isdigit(s[i]))
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
		++i;
	}
	return (sign * val / power);
}

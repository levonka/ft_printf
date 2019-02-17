/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:08:20 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/17 17:39:37 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flagsvalidator(char flag)
{
	int			i;
	const char	base[6] = {'#', '0', '-', '+', ' ', '\0'};

	i = 0;
	while (base[i] != '\0')
	{
		if (flag == base[i])
			return (SUCCESS);
		++i;
	}
	return (FAIL);
}

/*
** VALIDATE WIDTH AND PRECISION
*/

int		ft_numvalidator(const char *format, size_t *i)
{
	int		len;

	len = 0;
	while (ft_isdigit(format[*i]) == 1 && format[*i] != '\0')
	{
		++len;
		*i = *i + 1;
	}
	if (len > 0)
		return (len);
	return (FAIL);
}

int		ft_typevalidator(t_type *node, int len, size_t *i)
{
	int			j;
	const char	base[][4] = {"c", "s",
	"d", "i", "u", "hu",
	"hd", "hi",
	"o", "O", "ho", "hho", "hhO", "hO", "lo", "llo", "lO", "llO", "jo", "jO", "zO", "zo",
	"x", "X", "hx", "hX", "hhx", "hhX", "lx", "lX", "llx", "llX", "zX", "zx", "jx", "jX",
	"p", "lp", "b",
	"hhd", "hhi", "hhu",
	"ld", "li", "lu", "lld", "lli", "llu",
	"f", "lf", "Lf", "%", "U", "hU", "hhU", "lU", "llU",
	"D", "hD", "hhD", "lD", "llD", "C", "lc", "F", "lF", "LF", "bs",
	"jd", "ji", "ju", "zd", "zi", "zu", "jD", "zD", "jU", "zU", ""};

	while (len >= 1)
	{
		j = 0;
		while (ft_strcmp(base[j], "") != 0)
		{
			if (ft_strcmp(node->type, base[j]) == 0)
				return (SUCCESS);
			++j;
		}
		node->type[len - 1] = '\0';
		--len;
		*i = *i - 1;
	}
	return (FAIL);
}

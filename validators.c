/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:08:20 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/17 16:06:33 by agottlie         ###   ########.fr       */
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
	const char	base[][4] = {"c", "s", "p",
	"d", "i", "o", "O", "u", "x", "X",
	"hd", "hi", "ho", "hu", "hx", "hX", "hhd", "hhi", "hho", "hhO", "hO", "lO", "llO", "hhu", "hhx",
	"hhX", "ld", "li", "lo", "lu", "lx", "lX", "lld", "lli", "llo", "llu",
	"llx", "llX", "f", "lf", "Lf", "F", "lF", "LF", "%", "b", "U", "hU", "hhU", "lU", "llU",
	"D", "hD", "hhD", "lD", "llD", "C", "lc", "lp", "bs",
	"jd", "ji", "ju", "zd", "zi", "zu", "jD", "zD", "jU", "zU", "zO", "zo", "zX", "zx", "jo", "jO", "jx", "jX", ""};

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

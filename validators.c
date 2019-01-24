/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:53:45 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/23 17:09:18 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flagsvalidator(char flag)
{
	int		i;
	const char	base[6] = {'#', '0', '-', '+', ' ', '\0'};

	i = 0;
	while (base[i] != '\0')
	{
		if (flag == base[i])
		{
			// printf("FLAG - %c - IS FOUND\n", flag);
			return (SUCCESS);
		}
		++i;
	}
	// printf("FLAG - %c - IS NOT FOUND!\n", flag);
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
		return(len);
	return (FAIL);
}

int		ft_typevalidator(t_type *node, int len, size_t *i)
{
	int			j;
	const char	base[][4] = {"c", "s", "p",
	"d", "i", "o", "u", "x", "X",
	"hd", "hi", "ho", "hu", "hx", "hX", "hhd", "hhi", "hho", "hhu", "hhx", "hhX",
	"ld", "li", "lo", "lu", "lx", "lX", "lld", "lli", "llo", "llu", "llx", "llX",
	"f", "lf",  "Lf", "%", ""};

	while (len >= 1)
	{
		j = 0;
		while (strcmp(base[j], "") != 0)
		{
			if (ft_strcmp(node->type, base[j]) == 0)
			{
				// printf("TYPE - %s - IS FOUND IN INPUT\n", node->type);
				return (SUCCESS);
			}
			++j;
		}
		node->type[len - 1] = '\0';
		--len;
		*i = *i - 1;
	}
	// printf("TYPE IS NOT FOUND!\n");
	return (FAIL);
}

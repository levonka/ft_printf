/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:30:23 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/25 17:40:07 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag_in_struct(t_type *node, char flag)
{
	int		i;

	i = 0;
	while (node->flags[i] != '\0')
	{
		if (node->flags[i] == flag)
		{
			// printf("FLAG - %c - IS FOUND IN STRUCT, SO NEXT\n", flag);
			return (SUCCESS);
		}
		++i;
	}
	// printf("FLAG - %c - IS NOT FOUND IN STRUCT! NOW IT IS IN IT\n", flag);
	return (FAIL);
}

int		ft_flagssearcher(t_type *node, const char *format, size_t *i)
{
	int		j;

	j = 0;
	// node->flags = ft_strnew(5);
	while (format[*i] != '\0')
	{
		if (ft_flagsvalidator(format[*i]) == SUCCESS)
		{
			if (ft_isflag_in_struct(node, format[*i]) == FAIL)
			{
				node->flags[j] = format[*i];
				++j;
			}
		}
		else
			return (FAIL);
		*i = *i + 1;
	}
	return (SUCCESS);
}

int		ft_widthsearcher(t_type *node, const char *format, size_t *i)
{
	int		j;
	int		len;
	char	*number;

	j = 0;
	if ((len = ft_numvalidator(format, i)) > 0)
	{
		number = ft_strsubi(format, *i - len, *i - 1);
		node->width = ft_atoi(number);
		free(number);
		return (SUCCESS);
	}
	node->width = -1;
	return (FAIL);
}

int		ft_precisionsearcher(t_type *node, const char *format, size_t *i)
{
	int		j;
	int		len;
	char	*number;

	j = 0;

	while (format[*i] == '.' && format[*i] != '\0')
	{
		*i = *i + 1;
		if (ft_isdigit(format[*i]) == 0 && format[*i] != '.')
		{
			node->precision = 0;
			return (SUCCESS);
		}
		if ((len = ft_numvalidator(format, i)) > 0)
		{
			number = ft_strsubi(format, *i - len, *i - 1);
			node->precision = ft_atoi(number);
			free(number);
			return (SUCCESS);
		}
	}
	node->precision = -1;
	return (FAIL);
}

int		ft_typesearcher(t_type *node, const char *format, size_t *i)
{
	size_t	len;

	len = 0;
	while (len < 3 && format[*i] != '\0')
	{
		// printf("len = %zu | i = %zu | format = %c\n", len, *i, format[*i]);
		++len;
		*i = *i + 1;
	}
	if (len > 0)
	{
		node->type = ft_strsubi(format, *i - len, *i - 1);
		// printf("type = %s\n", node->type);
		ISFAILED(ft_typevalidator(node, len, i));
		return (SUCCESS);
	}
	return (FAIL);
}
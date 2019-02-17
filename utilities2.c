/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:23:17 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/17 15:27:07 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			add_flag(t_type **node, char mod)
{
	int i;
	
	i = 0;
	if (!(*node)->flags)
		(*node)->flags = ft_strnew(5);
	while ((*node)->flags[i] != '\0')
		i++;
	(*node)->flags[i] = mod;
	i++;
	(*node)->flags[i] = '\0';
}

static char		*add0x(char *str, int start, t_type *node)
{
	if (str[0] == '0' && str[1] == 'x')
		return (str);
	if ((str[start] == ' ' && str[start + 1] == ' ') ||
		(ft_strchr(node->flags, '0') && str[start] == '0' && str[start + 1]))
	{
		str[start] = '0';
		str[start + 1] = 'x';
		return (str);
	}
	else
		return (expand_str(str));
}

static char		*hashtag_mode_ext(char *str, t_type *node)
{
	if (str[0] == ' ' && str[1] == ' ')
	{
		str = shift_npos(str, 1);
		cmp(str, "0x") ? 0 : add0x(str, 0, node);
		return (add0x(str, 0, node));
	}
	else
	{
		if (str[0] == ' ')
			str = expand_str(str);
		if (node->precision < node->width)
		{
			if (ft_strchr(node->flags, '-'))
				str = shift_npos(str, 1);
			return (add0x(str, 0, node));
		}
		else
			return (expand_str(str));
	}
	return (str);
}

char			*hash(char *str, t_type *node, int i)
{
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	if (i < 3)
		return (hashtag_mode_ext(str, node));
	else
	{
		str[i - 2] = '0';
		str[i - 1] = 'x';
	}
	return (str);
}

char			*octo_addzero(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(str));
	new[0] = '0';
	while (str[i] != '\0')
	{
		new[i + 1] = str[i];
		i++;
	}
	new[i + 1] = '\0';
	return (new);
}

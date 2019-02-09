/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:30:59 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/08 16:51:40 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_abs(intmax_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int			ft_nlen(intmax_t n, int base)
{
	size_t		len;

	len = 0;
	if (n == 0)
		return(1);
	while (n)
	{
		len++;
		n = n / base;
	}
	return (len);
}

char		*ft_ntoa_base(uintmax_t n, int base)
{
	char	*res;
	int		len;
	static char	*nums = "0123456789abcdef";

	res = NULL;
	len = ft_nlen(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (len + 4))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (len && n)
	{
		res[len - 1] = nums[ft_abs(n % base)];
		n = n / base;
		len--;
	}
	return (res);
}

void		turnoff_fl(char *flags, char c)
{
	int i;
	char buf;

	i = -1;
	while(flags[++i] != '\0')
	{
		if (flags[i] == c)
		{
			if (flags[i + 1] == '\0')
				flags[i] = '\0';
			else
			{
				buf = flags[i];
				flags[i] = flags[i + 1];
				flags[i + 1] = buf;
			}
		}
	}
	// return (0);
}

void		str2upcase(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
}

static void	add0x(char *str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (ft_isprint(str[i]))
		i++;
	str[i] = ' ';
	str[++i] = ' ';
	while (len < 2)
	{
		j = i + 1;
		while (--j > 0)
			ft_swap(&str[j], &str[j - 1]);
		len++;
	}
	str[0] = '0';
	str[1] = 'x';
	str[ft_strlen(str)] = '\0';
}

int		ft_ntoa_dispatcher(t_type *node, char *n, int base)
{
	char *str = NULL;

	turnoff_fl(node->flags, '+');
	node->precision > 0 ? turnoff_fl(node->flags, '0') : 0;
	if (cmp(node->type, "x") || cmp(node->type, "X"))
	{
		if ((int)n < 0)
			str = ft_ntoa_base((unsigned long int)n, base);
		else
			str = ft_ntoa_base((int)n, base);
		// if (cmp(node->type, "X"))
		// {
		// 	str2upcase(str);
		// }

	}
	else if (cmp(node->type, "p"))
	{
		// str = ft_strdup("0x");
		turnoff_fl(node->flags, ' ');
		turnoff_fl(node->flags, '+');
		turnoff_fl(node->flags, '#');
		// if (node->precision > 12)
		// {
		// 	printf("his\n");
		// 	// str = ft_ntoa_base((unsigned long int)n, base);
		// }
		// str = ft_itoa_base(n, base);
		// a = va_arg(ap, char*);
		str = ft_ntoa_base((unsigned long int)n, base);
		add0x(str);
		// if (node->precision == 0)
		// ft_strcat(str, ft_ntoa_base((unsigned long int)n, base));
		// ft_print_x(node, str, 0);
	}
	else if (cmp(node->type, "b"))
		str = ft_ntoa_base((unsigned long int)n, base);
	return (ft_print_x(node, str, 0));
}

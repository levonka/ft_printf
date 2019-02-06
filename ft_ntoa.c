/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:30:59 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/06 12:04:33 by yharwyn-         ###   ########.fr       */
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
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
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

void turnoff_fl(char *flags, char c)
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

// void	ft_ntoa_dispatcher(t_type *node, uintmax_t n, int base)
// {
// 	char *str;


// 	str = ft_ntoa_base(n, base);

// 	// printf("%s\n", node->flags);
// 	// printf("%s\n", node->type);
// 	// cmp(node->type, 'x') ? ft_lower
// 	node->precision > 0 ? turnoff_fl(node->flags, '0') : 0;
// 	// printf("%s\n", node->flags);
// 	turnoff_fl(node->flags, '+');
// 	// turnoff_fl(node->flags, '+');

// 	// turnoff_fl(node->flags, '0');
// 	// node->flags
// 	// printf("%s\n", node->flags);

// 	ft_print_x(node, str, 0);

// 	// printf("%s\n", str);
// }

// char	*get_pointer(const void *arg)
// {
// 	char *hex;
// 	char *ret;
// 	int i;
// 	const int size = 32;
// 	const unsigned long **val = arg;

// 	hex = ft_strnew(size);
// 	symtohex((unsigned long)(*val), hex, size);
// 	i = 0;
// 	while(hex[i] == '0')
// 		i++;
// 	ret = ft_strnew(2 + size - i);
// 	ft_strcat(ret, "0x");
// 	ft_strcat(ret, hex + i);
// 	ft_strdel(&hex);
// 	return(ret);
// }




// char		*ft_ntoa_base(uintmax_t n, int base)
// {
// 	char	*res;
// 	int		len;
// 	static char	*nums = "0123456789ABCDEF";

// 	res = NULL;
// 	len = ft_nlen(n, base);
// 	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
// 		return (NULL);
// 	res[len] = '\0';
// 	if (n == 0)
// 		res[0] = '0';
// 	while (len && n)
// 	{
// 		res[len - 1] = nums[ft_abs(n % base)];
// 		n = n / base;
// 		len--;
// 	}
// 	return (res);
// }









void	ft_ntoa_dispatcher(t_type *node, char *n, int base)
{
	
	char *str = NULL;

	turnoff_fl(node->flags, '+');
	node->precision > 0 ? turnoff_fl(node->flags, '0') : 0;
	if (cmp(node->type, "x"))
	{
		// printf("%d\n", n);
		str = ft_ntoa_base((unsigned long int)n, base);
		// printf(">>%s\n", str);
		// ft_print_x(node, str, 0);
		// turnoff_fl(node->flags, '-');

	}
	else if (cmp(node->type, "p"))
	{
		turnoff_fl(node->flags, ' ');
		// str = ft_strdup("0x");
		turnoff_fl(node->flags, '+');
		// if (node->precision > 12)
		// {
		// 	printf("his\n");
		// 	// str = ft_ntoa_base((unsigned long int)n, base);

		// }
		// str = ft_itoa_base(n, base);
		// a = va_arg(ap, char*);
		str = ft_ntoa_base((unsigned long int)n, base);

		// ft_strcat(str, ft_ntoa_base((unsigned long int)n, base));
		// ft_print_x(node, str, 0);
	}
	else if (cmp(node->type, "b"))
		str = ft_ntoa_base((unsigned long int)n, base);
	ft_print_x(node, str, 0);
}

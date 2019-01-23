/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:01:44 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/23 09:09:25 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include "libft/libft.h"

void	ft_putnbr_long(long long n);
void	ft_putnbr_unsigned(unsigned long long n);
void	ft_printstring(char *str);
void	ft_printchar(char c);
int		ft_printf(const char *format, ...);
int		ft_sum_of_a_num(int num);
int		ft_printf_dispatcher(va_list args);

int		main(void)
{
	// char				arr[] = "something";
	// unsigned char				ch = 'A';
	// unsigned short 					num = SHRT_MAX;
	// unsigned int			num2 = UINT_MAX;
	// int			num4 = 12345439;
	// long				num3 = 4000000000045600020;
	// unsigned long long	num3 = ULONG_MAX;

	ft_putchar('\n');
	// ft_printf("str = %8d\n", num4);
	printf("'%-6d'\n", 123);
	ft_putchar('\n');
	return (0);
}

// int		ft_printf_dispatcher(va_list args)
// {
	// return (0);
// }

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*arr;
	size_t	i;
	int		len;
	int		len_2;
	int		num;
	int		flag;

	va_start(args, format);
	i = 0;
	flag = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			while (format[i] == ' ' && format[i] != '\0')
			{
				flag = 1;
				++i;
			}
			if (ft_isdigit(format[i]))
			{
				while (ft_isdigit(format[i + len]) == 1)
					++len;
				arr = ft_strsubi(format, i, i + len);
				i += len;
			}
			if (format[i] == 'c')
				ft_printchar(va_arg(args, int));
			else if (format[i] == 's')
				ft_printstring(va_arg(args, char *));
			else if (format[i] == '%')
				ft_putchar('%');
			else if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
			{
				(flag > 0) ? ft_putchar(' ') : (flag = 0);
				ft_putnbr_long(va_arg(args, long));
				++i;
			}
			else if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd' || format[i + 2] == 'i'))
			{
				(flag > 0) ? ft_putchar(' ') : (flag = 0);
				ft_putnbr_long(va_arg(args, long long));
				i += 2;
			}
			else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
			{
				ft_putnbr_unsigned(va_arg(args, unsigned int));
				i += 2;
			}
			else if (format[i] == 'h' && format[i + 1] == 'u')
			{
				ft_putnbr_unsigned(va_arg(args, unsigned int));
				++i;
			}
			else if (format[i] == 'l' && format[i + 1] == 'u')
			{
				ft_putnbr_unsigned(va_arg(args, unsigned long));
				++i;
			}
			else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
			{
				ft_putnbr_unsigned(va_arg(args, unsigned long long));
				i += 2;
			}
			else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'd')
			{
				(flag > 0) ? ft_putchar(' ') : (flag = 0);
				ft_putnbr_long(va_arg(args, signed int));
				i += 2;
			}
			else if (format[i] == 'h' && format[i + 1] == 'd')
			{
				(flag > 0) ? ft_putchar(' ') : (flag = 0);
				ft_putnbr_long(va_arg(args, int));
				++i;
			}
			else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
			{
				ft_putnbr_long(va_arg(args, unsigned int));
				i += 2;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				(flag > 0) ? ft_putchar(' ') : (flag = 0);
				num = va_arg(args, int);
				len = ft_atoi(arr);
				len_2 = ft_sum_of_a_num(num);
				while (len_2++ < len - flag)
					ft_putchar(' ');
				ft_putnbr_long(num);
			}
			else if (format[i] == 'u')
				ft_putnbr_unsigned(va_arg(args, unsigned int));
			else if (format[i] == 'f')
				ft_printf("goooo\n");
			else
				printf("has no any coincidence\n");
		}
		else
			ft_putchar(format[i]);
		++i;
	}
	va_end(args);
	return (0);
}

int		ft_sum_of_a_num(int num)
{
	static int		i;	// 0

	if (num <= 0)
		return (1);
	else
		ft_sum_of_a_num(num / 10);
	++i;
	return (i);
}

void	ft_putnbr_long(long long n)
{
	char	p;

	if (n == -9223372036854775807)
	{
		write(1, "-", 1);
		write(1, "9", 1);
		ft_putnbr_long(223372036854775807);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_long(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr_long(n / 10);
		p = (n % 10) + 48;
		write(1, &p, 1);
	}
	else
	{
		p = n + 48;
		write(1, &p, 1);
	}
}

void	ft_putnbr_unsigned(unsigned long long n)
{
	char	p;

	if (n >= 10)
	{
		ft_putnbr_long(n / 10);
		p = (n % 10) + 48;
		write(1, &p, 1);
	}
	else
	{
		p = n + 48;
		write(1, &p, 1);
	}
}

void	ft_printstring(char *str)
{
	ft_putstr(str);
}

void	ft_printchar(char c)
{
	ft_putchar(c);
}

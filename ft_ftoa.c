/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:53:39 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/08 10:57:54 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

// static void ft_reverse(char *str, int len)
// {
// 	int i = 0;
// 	int j = len - 1;
// 	int temp;

// 	while (i < j)
// 	{
// 		temp = str[i];
// 		str[i] = str[j];
// 		str[j] = temp;
// 		i++;
// 		j--;
// 	}
// }

// static int floatToStr(double x, char str[], int d)
// {
// 	int i = 0;
// 	int num;

// 	num = (int)x;
// 	while (num)
// 	{
// 		str[i] = (num % 10) + '0';
// 		num = num / 10;
// 		i++;
// 	}

// 	while (i < d)
// 		str[i++] = '0';

// 	ft_reverse(str, i);
// 	str[i] = '\0';
// 	return i;
// }


char	*floatpart_maker(double n)
{
	unsigned long	intpart;
	double			floatpart;
	char			*floatres;
	int				len;
	int				i;

	i = 0;
	intpart = (unsigned long)n;
	floatpart = n - (double)intpart;
	floatres = malloc(sizeof(char) * 500);     // изменить
	len = 17 - ft_nlen(intpart, 10);
	while (len > 0)
	{
		floatpart *= 10;
		floatres[i] = (int)floatpart + '0';
		floatpart -= (int)floatpart;
		len--;
		i++;
	}
	floatres[i] = '\0';
	return (floatres);

}

char	*floatpart_adjusting(char *floatres, int afterpoint, int *mem)
{
	int 	i;
	int 	len;

	i = afterpoint;
	if (floatres[afterpoint] >= '5')
	{
		while (floatres[afterpoint - 1] == '9' && afterpoint != 0)
		{
			floatres[afterpoint] = '0';
			afterpoint--;
		}
		if (afterpoint == 0)
			(*mem)++;
		else
		{
			floatres[afterpoint - 1]++;
			floatres[afterpoint] = '0';
		}
	}
	len = ft_strlen(floatres);
	while (len >= i)
	{
		floatres[len] = '\0';
		len--;
	}
	return (floatres);
}

static void		join_parts(char *intres, char *floatres, char *floatrdy)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(intres[i] != '\0')
	{
		floatrdy[j] = intres[i];
		i++;
		j++;
	}
	i = 0;
	floatrdy[j++] = '.';
	while(floatres[i] != '\0')
	{
		floatrdy[j] = floatres[i];
		i++;
		j++;
	}
	floatrdy[j] = '\0';
}


char			*ft_ftoa(double n, int afterpoint)
{
	unsigned long	intpart;
	char			*intres;
	char			*floatres;
	char			*floatrdy;
	int				mem;

	mem = 0;
	if (n == -1.00 / 0.00)
		return (ft_strdup("-inf"));
	else if (n == 1.00 / 0.00)
		return (ft_strdup("inf"));
	else if (n != n)
		return (ft_strdup("nan"));
	else if (n == -0)
	{
		if (*(unsigned long*)&n >> 63)
			return (ft_strdup("-0."));
	}
	// floatres = floatpart_maker(n);
	intpart = (unsigned long)n;
	floatres = floatpart_adjusting(floatpart_maker(n), afterpoint, &mem);
	mem > 0 ? intpart++ : 0;
	intres = ft_itoa_ull(intpart);
	floatrdy = malloc(sizeof(char) * ft_strlen(floatres) + ft_strlen(intres) + 1);
	if (!afterpoint)
		return (intres);
	join_parts(intres, floatres, floatrdy);
	return (floatrdy);
}


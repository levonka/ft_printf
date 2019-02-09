/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:53:39 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/09 09:09:02 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

static char	*floatpart_maker(double n, int afterpoint)
{
	unsigned long	intpart;
	double			floatpart;
	char			*floatres;
	int				len;
	int				i;

	i = 0;
	intpart = (unsigned long)n;
	floatpart = n - (double)intpart;
	floatres = malloc(sizeof(char) * 1000);     // изменить
	// len = 17 - ft_nlen(intpart, 10);
	len = afterpoint;
	intpart = 0;
	while (len > 0 || i < 17)			// СДЕЛАТЬ НЕ 17 РАЗ, А 17 - РАЗМЕР ПЕРВОЙ ЧАСТИ ЧИСЛА
	{
		floatpart *= 10;
		if (len > 0)
			floatres[i] = (int)floatpart + '0';
		intpart = (intpart * 10) + (int)floatpart;
		floatpart -= (int)floatpart;
		len--;
		i++;
	}
	floatres[i] = '\0';
	// printf("'>%lu'\n", intpart);
	return (floatres);
}

char	*floatpart_adjusting(char *floatres, int afterpoint, int *mem)
{
	int		i;
	int		len;

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

static void	join_parts(char *intres, char *floatres, char *floatrdy)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (intres[i] != '\0')
	{
		floatrdy[j] = intres[i];
		i++;
		j++;
	}
	i = 0;
	floatrdy[j++] = '.';
	while (floatres[i] != '\0')
	{
		floatrdy[j] = floatres[i];
		i++;
		j++;
	}
	floatrdy[j] = '\0';
}

static char	*isconst(double n)
{
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
	return (NULL);
}

char		*ft_ftoa(double n, int afterpoint)
{
	unsigned long	intpart;
	char			*intres;
	char			*floatres;
	char			*floatrdy;
	int				mem;

	mem = 0;
	if ((floatrdy = isconst(n)) != NULL)
		return (floatrdy);
	// floatres = floatpart_maker(n);
	intpart = (unsigned long)n;
	floatres = floatpart_adjusting(floatpart_maker(n, afterpoint), afterpoint, &mem);
	mem > 0 ? intpart++ : 0;
	intres = ft_itoa_ull(intpart);
	floatrdy = malloc(sizeof(char) * ft_strlen(floatres) + ft_strlen(intres) + 2);
	if (!afterpoint)
		return (intres);
	join_parts(intres, floatres, floatrdy);
	free(floatres);
	free(intres);
	return (floatrdy);
}

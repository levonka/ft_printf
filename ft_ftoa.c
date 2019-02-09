/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:53:39 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/09 14:27:15 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

static char	*floatpart_maker(double n, int len, long *intpart)
{
	double			floatpart;
	char			*floatres;
	int				limit;
	int				i;

	i = 0;
	if (n > 0.0)
		floatpart = n - (double)(*intpart);
	else
		floatpart = (n * -1) - (double)(*intpart);
	floatres = malloc(sizeof(char) * 1000);     // изменить
	limit = 17 - ft_nlen(*intpart, 10);
	(*intpart) = 0;
	while (len > 0 || i < limit)
	{
		printf("\n\n>>>>>>>%f\n", floatpart);
		floatpart *= 10;
		printf("<<<<<<<%f", floatpart);
		if (len > 0 || i < limit)
		{
			floatres[i] = (int)floatpart + '0';
			printf("\n~~~~~%s", floatres);
		}
		*intpart = ((*intpart) * 10) + (int)floatpart;
		floatpart -= (int)floatpart;
		len--;
		i++;
	}
	floatres[i] = '\0';
	printf("\n>%ld\n", *intpart);
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
		if (*(long*)&n >> 63)
			return (ft_strdup("-0."));
	}
	return (NULL);
}

char		*zeroprec(long inttest, long res, int len)
{
	long	num;

	num = 5;
	while (len > 0)
	{
		num *= 10;
		len--;
	}
	if (res % 2 == 0)
	{
		if (inttest > num)
			return (ft_itoa_ll(res + 1));
		else if (inttest < num)
			return (ft_itoa_ll(res));
		else if (inttest == num)
			return (ft_itoa_ll(res));
	}
	else
		if (inttest > num)
			return (ft_itoa_ll(res + 1));
		else if (inttest < num)
			return (ft_itoa_ll(res));
		else if (inttest == num)
			return (ft_itoa_ll(res + 1));
	return (ft_strdup("sw"));
}

char		*ft_ftoa(double n, int afterpoint)
{
	long			intpart;
	long			inttest;
	char			*intres;
	char			*floatres;
	char			*floatrdy;
	int				mem;
	int				minus;

	mem = 0;
	minus = 0;
	if ((floatrdy = isconst(n)) != NULL)
		return (floatrdy);
	if (n < 0.0)
	{
		minus = 1;
		intpart = (long)n * -1;
	}
	else
		intpart = (long)n;
	inttest = intpart;
	floatrdy = floatpart_maker(n, afterpoint, &inttest);
	if (afterpoint == 0)
		return (zeroprec(inttest, (long)n, ft_nlen(inttest, 10) - 1));
	floatres = floatpart_adjusting(floatrdy, afterpoint, &mem);
	mem > 0 ? intpart++ : 0;
	intres = ft_itoa_ll(intpart);
	// free(floatrdy);
	floatrdy = malloc(sizeof(char) * ft_strlen(floatres) + ft_strlen(intres) + 2);
	if (!afterpoint)
		return (intres);
	join_parts(intres, floatres, floatrdy);
	free(floatres);
	free(intres);
	return (floatrdy);
}

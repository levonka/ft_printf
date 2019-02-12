/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:53:39 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/12 08:56:42 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double	roundgenerator(int prec)
{
	int				i;
	double			round;

	i = 0;
	round = 0.5;
	while (i < prec)
	{
		round /= 10;
		i++;
	}
	return (round);
}

static char		*floatpart_maker(double n, int prec, long intpart)
{
	double	floatpart;
	char	*floatres;
	int		i;

	i = 0;
	if (n > 0.0)
		floatpart = n - (double)(intpart);
	else
		floatpart = (n * -1) - (double)(intpart);
	if (prec == 0)
		return (zeroprec(floatpart, intpart));
	floatres = malloc(sizeof(char) * 2000);
	floatpart += roundgenerator(prec);
	while (prec > 0)
	{
		floatpart *= 10;
		floatres[i] = (int)floatpart + '0';
		floatpart -= (int)floatpart;
		prec--;
		i++;
	}
	floatres[i] = '\0';
	return (floatres);
}

static void		join_parts(char *floatrdy, char *intres, char *floatres)
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

static char		*isconst(double n)
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

char			*zeroprec(double floatpart, long res)
{
	if (res % 2 == 0)
	{
		if (floatpart > 0.50000000000000000)
			return (ft_itoa_ll(res + 1));
		else if (floatpart < 0.50000000000000000 || floatpart == 0.5000000000000000)
			return (ft_itoa_ll(res));
	}
	else
	{
		if (floatpart > 0.50000000000000000 || floatpart == 0.50000000000000000)
			return (ft_itoa_ll(res + 1));
		else if (floatpart < 0.50000000000000000)
			return (ft_itoa_ll(res));
	}
	return (ft_strdup("sw"));
}

char			*ft_ftoa(double n, int afterpoint)
{
	long			intpart;
	char			*intres;
	char			*floatres;
	char			*floatrdy;
	int				minus;

	if ((floatrdy = isconst(n)) != NULL)
		return (floatrdy);
	minus = (n < 0.0) ? 1 : 0;
	intpart = (n < 0.0) ? (long)n * -1 : (long)n;
	floatres = floatpart_maker(n, afterpoint, intpart);
	if (afterpoint == 0)
		return (floatres);
	intres = ft_itoa_ll(intpart);
	floatrdy = malloc(sizeof(char) * ft_strlen(floatres) +
		ft_strlen(intres) + 2);
	join_parts(floatrdy, intres, floatres);
	free(floatres);
	free(intres);
	return (floatrdy);
}

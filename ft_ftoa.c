/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:11:57 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/02/18 11:03:04 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*zeroprec(double floatpart, long res)
{
	if (floatpart == 0.00)
		return (ft_itoa_ll(res));
	else if (res % 2 == 0)
	{
		if (floatpart > 0.50000000000000000)
			return (ft_itoa_ll(res + 1));
		else if (floatpart < 0.50000000000000000 ||
			floatpart == 0.5000000000000000)
			return (ft_itoa_ll(res));
	}
	else
	{
		if (floatpart > 0.50000000000000000 || floatpart == 0.50000000000000000)
		{
			return (ft_itoa_ll(res + 1));
		}
		else if (floatpart < 0.50000000000000000)
			return (ft_itoa_ll(res));
	}
	return (ft_strdup("sw"));
}

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

static char		*floatpart_maker(double n, int prec, long *intpart)
{
	double	floatpart;
	char	*floatres;
	int		i;

	i = 0;
	if (n == 0.0)
		floatpart = 0.0;
	else if (n > 0.0)
		floatpart = n - (double)(*intpart);
	else
		floatpart = (n * -1) - (double)(*intpart);
	if (prec == 0)
		return (zeroprec(floatpart, *intpart));
	floatres = ft_strnew(prec + 500);
	floatpart += roundgenerator(prec);
	(floatpart >= 1.0) ? (*intpart)++ : 0;
	while (prec > 0)
	{
		floatpart *= 10;
		floatres[i++] = ((int)floatpart == 10) ? '0' : (int)floatpart + '0';
		floatpart -= (int)floatpart;
		prec--;
	}
	floatres[i] = '\0';
	return (floatres);
}

static void		join_parts(char *floatrdy, char *intres, char *floatres)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(floatrdy) > 0 ? ft_strlen(floatrdy) - 1 : 0;
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
	else if (n == 0.0)
		if (*(long*)&n >> 63)
			return (ft_strdup("-0"));
	return (NULL);
}

static void		ft_flagminus_float(char *str, int len)
{
	int		i;

	i = 0;
	str[len] = '\0';
	str[len + 1] = '\0';
	if (ft_isdigit(str[0]))
	{
		len -= (str[ft_strlen(str) - 1] == ' ') ? 1 : 0;
		while (len > 0)
		{
			ft_swap(&str[len], &str[len - 1]);
			--len;
		}
		str[len] = '-';
	}
	else
	{
		while (str[i] == ' ' && str[i] != '0' && str[i] != '\0')
			i++;
		str[i - 1] = '-';
	}
}

static void			sharpmod(char *floatrdy)
{
	int		len;

	len = ft_strlen(floatrdy);
	floatrdy[len] = '.';
}

static char			*afterminus(t_type *node, char *fres, char *intres)
{
	char	*floatrdy;

	floatrdy = ft_strnew(ft_strlen(fres) + 6);
	floatrdy = ft_strcat(floatrdy, fres);
	ft_flagminus_float(floatrdy, ft_strlen(floatrdy));
	(ft_isfl_in(node, '#') == 0) ? sharpmod(floatrdy) : 0;
	free(fres);
	free(intres);
	return (floatrdy);
}

char			*retconst(char *floatrdy, char *intres, char *floatres, double n)
{
	if (n == 0.0)
	{
		join_parts(floatrdy, intres, floatres);
		free(intres);
		free(floatres);
	}
	return (floatrdy);
}

char			*ft_ftoa(double n, int afterpoint, t_type *node)
{
	long			intpart;
	char			*intres;
	char			*floatres;
	char			*floatrdy;

	intpart = (n < 0.0) ? (long)n * -1 : (long)n;
	floatres = floatpart_maker(n, afterpoint, &intpart);
	intres = ft_itoa_ll(intpart);
	if ((floatrdy = isconst(n)) != NULL)
		return (retconst(floatrdy, intres, floatres, n));
	if (afterpoint == 0)
	{
		if (n < 0.0)
			return (afterminus(node, floatres, intres));
		(ft_isfl_in(node, '#') == 0) ? sharpmod(floatres) : 0;
		return (floatres);
	}
	floatrdy = malloc(sizeof(char) * ft_strlen(floatres) +
		ft_strlen(intres) + 4);
	join_parts(floatrdy, intres, floatres);
	(n < 0.0) ? ft_flagminus_float(floatrdy, ft_strlen(floatrdy)) : 0;
	free(floatres);
	free(intres);
	return (floatrdy);
}

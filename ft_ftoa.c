/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:53:39 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/05 09:24:18 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

static void ft_reverse(char *str, int len)
{
    int i = 0;
    int j = len - 1;
    int temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

static int intToStr(int x, char str[], int d)
{
    int i = 0;

    while (x)
    {
        str[i] = (x % 10) + '0';
        x = x / 10;
        i++;
    }

    while (i < d)
        str[i++] = '0';

    ft_reverse(str, i);
    str[i] = '\0';
    return i;
}


static int floatToStr(double x, char str[], int d)
{
    int i = 0;
    int num;

    num = (int)x;
    while (num)
    {
        str[i] = (num % 10) + '0';
        num = num / 10;
        i++;
    }

    while (i < d)
        str[i++] = '0';

    ft_reverse(str, i);
    str[i] = '\0';
    return i;
}

char *ft_ftoa(double n, int afterpoint)
{
    int		intpart = (int)n;
    double	floatpart = n - (double)intpart;
    char	*res;


    if (n == -1.00 / 0.00)
    	return (ft_strdup("-inf"));
    else if (n == 1.00 / 0.00)
    	return (ft_strdup("inf"));
    else if (n != n)
        return (ft_strdup("nan"));

    res = malloc(sizeof(char) * 300);		// изменить
    int i = intToStr(intpart, res, 0);
    if (afterpoint != 0)
    {
        res[i] = '.';
        floatpart = floatpart * pow(10, afterpoint);
        floatToStr(floatpart, res + i + 1, afterpoint);
    }
    return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:53:39 by agottlie          #+#    #+#             */
/*   Updated: 2019/02/06 17:46:29 by yharwyn-         ###   ########.fr       */
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

// static int intToStr(int x, char str[], int d)
// {
//     int i = 0;

//     while (x)
//     {
//         str[i] = (x % 10) + '0';
//         x = x / 10;
//         i++;
//     }

//     while (i < d)
//         str[i++] = '0';

//     ft_reverse(str, i);
//     str[i] = '\0';
//     return i;
// }


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
    unsigned long 	intpart = (unsigned long)n;
    double	floatpart = n - (double)intpart;
    char	*intres;
    char    *floatres;
    int     len;
    int     i;

    i = 0;
    if (n == -1.00 / 0.00)
        return (ft_strdup("-inf"));
    else if (n == 1.00 / 0.00)
        return (ft_strdup("inf"));
    else if (n != n)
        return (ft_strdup("nan"));

    // add +- 0 checking

    // printf("%d\n", intpart);

    printf(">%.16f\n", floatpart);
    // printf(">%s\n", intres);

    if (afterpoint != 0)
    {
        floatres = malloc(sizeof(char) * 500);     // изменить
        len = 17 - ft_nlen(intpart, 10);
        while (len > 0)
        {
            printf("%d\n", (int)(floatpart * 10));
            floatpart *= 10;
            floatres[i] = (int)floatpart + '0';
            floatpart -= (int)floatpart;
            len--;
            i++;
        }
        floatres[i] = '\0';
        printf(">%s\n", floatres);
        int mem = 0;
        while (afterpoint > 0)
        {
            if (floatres[afterpoint] > 5)
            {
                mem++;
            } 
            floatres[afterpoint - 1] += 1; 
        }

        // floatres = malloc(sizeof(char) * afterpoint) + 1;
        // floatpart = floatpart * pow(10, afterpoint);
        // floatToStr(floatpart, intres + i + 1, afterpoint);
    }
    intres = ft_itoa_ull(intpart);
    return (intres);
}


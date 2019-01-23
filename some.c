/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:57:31 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/18 12:17:16 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	ft_privet(char num, ...)
{
	va_list args;
	char value;

	va_start(args, num);

	for (int i = 0; i < num - '0'; ++i)
	{
		value = va_arg(args, int);
		printf("%d: %d\n", i, value);
	}

	va_end(args);
}

int		main(void)
{
	ft_privet('5', 1, 2, 3, 4, 5);
	return (0);
}

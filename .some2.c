/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:15:33 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/18 13:01:22 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		done;
	char	*substring;

	substring = strstr(format, "Jacob");
	if (substring != format)
		return (0);

	va_start(args, format);

	done = vfprintf(stdout, format, args);

	va_end(args);
	return (done);
}

int		main(void)
{
	ft_printf("Something we don't want to say.\n");
	ft_printf("Jacob says, \"Hello World\"\n");
	return (0);
}

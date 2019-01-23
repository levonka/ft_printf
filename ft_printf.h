/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:55:21 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/23 09:45:47 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <limits.h>
#include "libft/libft.h"

enum { FAIL = -1, SUCCESS = 0 };

#define ISFAILED(f) if ((f) == FAIL) return (FAIL);

typedef struct		s_type
{
	char			*type;
	char			*flags;
	int				width;
	int				precision;
	int				status;
}					t_type;

int		ft_printf(const char *format, ...);
int		ft_solver(va_list args, const char *format, size_t *i);
t_type	*ft_create_ttr();
void	ft_freenode(t_type *node);

int		ft_typefinder(t_type *node, const char *format, size_t *i);

int		ft_isflag_in_struct(t_type *node, char flag);
int		ft_flagssearcher(t_type *node, const char *format, size_t *i);
int		ft_widthsearcher(t_type *node, const char *format, size_t *i);
int		ft_precisionsearcher(t_type *node, const char *format, size_t *i);
int		ft_typesearcher(t_type *node, const char *format, size_t *i);

int		ft_typevalidator(t_type *node, int len, size_t *i);
int		ft_flagsvalidator(char flag);
int		ft_numvalidator(const char *format, size_t *i);

void	ft_print_dispatcher(t_type *node, va_list args);
void	ft_putnbr_long(long long n);

#endif

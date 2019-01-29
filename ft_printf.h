#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <assert.h>
# include <limits.h>
# include "libft/libft.h"

enum { FAIL = -1, SUCCESS = 0 };

# define ISFAILED(f) if ((f) == FAIL) return (FAIL);
/*
** MIN will give us min value of type (ex: MIN(char) = -256)
*/
# define MIN(x) (1LL << (sizeof(x) * 8 - 1))

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
void	ft_diag_print(t_type *node);

int		ft_isflag_in_struct(t_type *node, char flag);
int		ft_flagssearcher(t_type *node, const char *format, size_t *i);
int		ft_widthsearcher(t_type *node, const char *format, size_t *i);
int		ft_precisionsearcher(t_type *node, const char *format, size_t *i);
int		ft_typesearcher(t_type *node, const char *format, size_t *i);

int		ft_typevalidator(t_type *node, int len, size_t *i);
int		ft_flagsvalidator(char flag);
int		ft_numvalidator(const char *format, size_t *i);

void	ft_print_dispatcher(t_type *node, va_list args);
int		cmp(char *type, char *c);

void	ft_flagminus(t_type *node, char *to, char *from, int *i);
void	ft_flagzero(t_type *node, char *str, int *i);

void	ft_print_string(t_type *node, char *str, int i);

void	ft_print_int(t_type *node, char *str, int i);

char	*ft_itoa_ll(long n);

char	*ft_itoa_ui(unsigned int n);

char	*ft_itoa_ull(unsigned long n);

void	ft_print_char(t_type *node, int c, int i);

void	ft_print_x(t_type *node, char *str, int i);
void	ft_ntoa_dispatcher(t_type *node, uintmax_t n, int base);

#endif

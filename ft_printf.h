#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <float.h>
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

void	ft_print_char(t_type *node, int c, int i);

void	ft_print_int(t_type *node, char *str, int i);
int		ft_isnegative(char *str);
void	ft_zerofiller(t_type *node, char *str, int len, int *i);
void	ft_fillin_num(t_type *node, char *to, char *from, int len);
void	ft_flagminus_num(t_type *node, char *str, int len);
void	ft_flagplus_num(t_type *node, char *str, int minus, int len);
void	ft_flagsp_num(char *str, int len);

char	*ft_itoa_ll(long n);
char	*ft_itoa_ull(unsigned long n);

void	ft_print_float(t_type *node, double n, int i);

void	ft_print_x(t_type *node, char *str, int i);
void	ft_ntoa_dispatcher(t_type *node, char *n, int base);
int		ft_nlen(intmax_t n, int base);

int		cmp(char *type, char *c);
double	ft_atof(char *s);
char	*ft_ftoa(double n, int afterpoint);


#endif

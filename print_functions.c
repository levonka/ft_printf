#include "ft_printf.h"

int		cmp(char *type, char *c)
{
	return ((ft_strcmp(type, c) == 0) ? 1 : 0);
}
/*
** s c d i hd hi hhd hhi ld lld li lli u lu llu hu hhu
*/
int		ft_print_dispatcher(t_type *node, va_list args)
{
	char	*t;
	int		len;

	len = 0;
	t = node->type;
	if (cmp(t, "s"))
		return (ft_print_string(node, va_arg(args, char *), 0));
	else if (cmp(t, "c"))
		return (ft_print_char(node, va_arg(args, int), 0));
	else if (cmp(t, "C"))
		return (ft_print_char(node, (wchar_t)va_arg(args, int), 0));
	else if (cmp(t, "d") || cmp(t, "i"))
		return (ft_print_int(node, ft_itoa(va_arg(args, int)), 0));
	else if (cmp(t, "hd") || cmp(t, "hi"))
		return (ft_print_int(node, ft_itoa((short)va_arg(args, int)), 0));
	else if (cmp(t, "hhd") || cmp(t, "hhi"))
		return (ft_print_int(node, ft_itoa((char)va_arg(args, int)), 0));
	else if (cmp(t, "ld") || cmp(t, "lld") || cmp(t, "li") || cmp(t, "lli") || cmp(t, "D"))
		return (ft_print_int(node, ft_itoa_ll(va_arg(args, long)), 0));
	else if (cmp(t, "u"))
		return (ft_print_u(node, ft_itoa_ui(va_arg(args, unsigned int)), 0));
	else if (cmp(t, "hu"))
		return (ft_print_u(node, ft_itoa_uh(va_arg(args, int)), 0));
	else if (cmp(t, "hhu"))
		return (ft_print_u(node, ft_itoa_uhh(va_arg(args, int)), 0));
	else if (cmp(t, "lu") || cmp(t, "llu") || cmp(t, "U"))
		return (ft_print_u(node, ft_itoa_ull(va_arg(args, unsigned long)), 0));
	else if (cmp(t, "f") || cmp(t, "lf"))
		return (ft_print_float(node, va_arg(args, double), 0));
	else if (ft_strchr(t, 'x') || ft_strchr(t, 'X'))
		return (ft_ntoa_dispatcher(node, va_arg(args, char*), 16));
	else if (cmp(t, "p"))
		return (ft_ntoa_dispatcher(node, va_arg(args, char*), 16));
	else if (cmp(t, "b"))
		return (ft_ntoa_dispatcher(node, va_arg(args, char*), 2));
	else if (cmp(t, "%"))
		return (ft_print_char(node, '%', 0));
	else if (ft_strchr(t, 'o') || ft_strchr(t, 'O'))
		return (ft_ntoa_dispatcher(node, va_arg(args, char*), 8));


	return (0);
}


// остались: %lf, %Lf, ho, hho, lo, llo, hx, hhx, lx, llx, X, hX, hhX, lX, llX
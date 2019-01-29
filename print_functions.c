#include "ft_printf.h"

int		cmp(char *type, char *c)
{
	return ((ft_strcmp(type, c) == 0) ? 1 : 0);
}
/*
** s c d i hd hi hhd hhi ld lld li lli u lu llu hu hhu
*/
void	ft_print_dispatcher(t_type *node, va_list args)
{
	char	*t;

	t = node->type;
	if (cmp(t, "s"))
		ft_print_string(node, ft_strdup(va_arg(args, char *)), 0);
	else if (cmp(t, "c"))
		ft_print_char(node, va_arg(args, int), 0);
	else if (cmp(t, "d") || cmp(t, "i") || cmp(t, "hd") || cmp(t, "hi") || cmp(t, "hhd") || cmp(t, "hhi"))
		ft_print_int(node, ft_itoa(va_arg(args, int)), 0);
	else if (cmp(t, "ld") || cmp(t, "lld") || cmp(t, "li") || cmp(t, "lli"))
		ft_print_int(node, ft_itoa_ll(va_arg(args, long)), 0);
	else if (cmp(t, "u") || cmp(t, "lu") || cmp(t, "llu") || cmp(t, "hu") || cmp(t, "hhu"))
		ft_print_int(node, ft_itoa_ull(va_arg(args, unsigned long)), 0);
	else if (cmp(t, "x") == 0)
		ntoa_dispatcher(node, va_arg(args, int), 0);
	else if (cmp(t, "p") == 0)
		ntoa_dispatcher(node, va_arg(args, int), 0);
}

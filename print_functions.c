#include "ft_printf.h"

int		cmp(char *type, char *c)
{
	return ((ft_strcmp(type, c) == 0) ? 1 : 0);
}

void	ft_print_dispatcher(t_type *node, va_list args)
{
	char	*t;

	t = node->type;
	if (cmp(t, "s"))
		ft_print_string(node, ft_strdup(va_arg(args, char *)), 0);
	else if (cmp(t, "d") || cmp(t, "i"))
		ft_print_int(node, ft_itoa(va_arg(args, int)), 0);
	else if (cmp(t, "c"))
		ft_print_char(node, va_arg(args, int), 0);
	else if (cmp(t, "x") == 0)
		ntoa_dispatcher(node, va_arg(args, int), 0);
	else if (cmp(t, "p") == 0)
		ntoa_dispatcher(node, va_arg(args, int), 0);
}

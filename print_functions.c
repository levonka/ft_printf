#include "ft_printf.h"

void	ft_print_dispatcher(t_type *node, va_list args)
{
	if (ft_strcmp(node->type, "s") == 0)
		ft_print_string(node, ft_strdup(va_arg(args, char *)), 0);
	else if (ft_strcmp(node->type, "d") == 0 || ft_strcmp(node->type, "i") == 0)
		ft_print_int(node, ft_itoa(va_arg(args, int)), 0);
	else if (ft_strcmp(node->type, "c") == 0)
		ft_print_char(node, va_arg(args, int), 0);
}

#include "ft_printf.h"

int		ft_solver(va_list args, const char *format, size_t *i)
{
	t_type	*node;
	int		len;
	int		len2;

	node = ft_create_ttr();
	ft_flagssearcher(node, format, i);
	ft_widthsearcher(node, format, i);
	ft_precisionsearcher(node, format, i);
	if (ft_typesearcher(node, format, i) == SUCCESS)
	{
		len = ft_print_dispatcher(node, args);
		ft_freenode(node);
		return (len);
	}
	else
	{
		free(node->type);
		node->type = ft_strnew(1);
		node->type[0] = format[*i];
		len2 = ft_print_char(node, node->type[0], 0);
		(*i)++;
		return (len2);
	}
	ft_freenode(node);
	return (FAIL);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (format == NULL)
		exit(1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			len += ft_solver(args, format, &i);
		}
		else
		{
			ft_putchar(format[i]);
			++len;
			++i;
		}
	}
	va_end(args);
	return (len);
}

t_type	*ft_create_ttr(void)
{
	t_type	*ptr;

	ptr = (t_type *)malloc(sizeof(t_type));
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

void	ft_freenode(t_type *node)
{
	free(node->type);
	free(node->flags);
	free(node);
}

void	ft_diag_print(t_type *node)
{
	printf("\n[flags:\t%s]\n", node->flags);
	printf("[width:\t%d]\n", node->width);
	printf("[pre-n:\t%d]\n", node->precision);
	printf("[type:\t%s]\n\n", node->type);
}

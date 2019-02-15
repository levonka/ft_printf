#include "ft_printf.h"

static char		*ntoa_xflags(t_type *node, char *n, int base)
{
	if (cmp(node->type, "x") || cmp(node->type, "X"))
		return (ft_ntoa_base((unsigned int)n, base));
	if (cmp(node->type, "lx") || cmp(node->type, "lX"))
		return (ft_ntoa_base((unsigned long int)n, base));
	if (!ft_strchr(node->type, 'h'))
	{
		if ((long)n < 0)
			return (ft_ntoa_base((unsigned long int)n, base));
		else
			return (ft_ntoa_base((long)n, base));
	}
	else
	{
		if (cmp(node->type, "hx") || cmp(node->type, "hX"))
				return (ft_ntoa_base((unsigned short)n, base));
		else
				return (ft_ntoa_base((unsigned char)n, base));
	}
}

static char		*ntoa_oflags(t_type *node, char *n, int base)
{
	if (cmp(node->type, "o"))
			return (ft_ntoa_base((unsigned int)n, base));
	if (cmp(node->type, "lo") || cmp(node->type, "llo"))
		return (ft_ntoa_base((long)n, base));
	if (!ft_strchr(node->type, 'h'))
	{
		if ((int)n < 0) //check it
			return (ft_ntoa_base((unsigned long int)n, base));
		else
			return (ft_ntoa_base((int)n, base));
	}
	else
	{
		if (cmp(node->type, "ho") || cmp(node->type, "hO"))
				return (ft_ntoa_base((unsigned short)n, base));
		else
				return (ft_ntoa_base((unsigned char)n, base));
	}
}

void			add_flag(t_type **node, char mod)
{
	if (!(*node)->flags)
		(*node)->flags = ft_strnew(5);
	int i;

	i = 0;
	while ((*node)->flags[i] != '\0')
		i++;
	(*node)->flags[i] = mod;
	i++;
	(*node)->flags[i] = '\0';
}

static char			*zero_cases(t_type *node, char *str)
{
	turnoff_fl(node->flags, '#');
	// ft_diag_print(node);
	node->width == -1 && node->precision == 0 ? ft_addflag(node, '@')  : 0;
	// ft_diag_print(node);
	if (node->width == 1 && node->precision == 0)
	{
		str = ft_strdup(" ");
		return (str);
	}
	if (!((ft_strchr(node->type, 'o') || ft_strchr(node->type, 'O')) && ft_strchr(node->flags, '#')))
		turnoff_fl(node->flags, '#');
	if (ft_strchr(node->type, 'p'))
	{
		if (node->precision == 0)
		{
			str = ft_strdup("0x");
			return(str);
		}
		else
			add_flag(&node, '#');
		return (str);
	}
	else if (node->precision == 0 && node->width > 1)
	{
		str = ft_strnew(node->width);
		ft_memset(str, ' ', node->width);
		return (str);
	}
	else if (node->precision == 0 && ft_strchr(node->flags, '#') && (ft_strchr(node->type, 'o') || ft_strchr(node->type, 'O')))
	{
		// printf("HELLO\n");
		// ft_diag_print(node);

		str = ft_strdup("0");
		ft_addflag(node, '^');
		return (str);
	}
	else if (ft_strchr(node->type, 'o') || ft_strchr(node->type, 'O') || ft_strchr(node->type, 'x') || ft_strchr(node->type, 'X'))
	{
		ft_addflag(node, '@');
		// ft_diag_print(node);

		// printf("hi\n");
		return (0);
	}
		return (0);
}

int				ft_ntoa_dispatcher(t_type *node, char *n, int base)
{
	char *str;
	char *tmp;

	str = NULL;
	turnoff_fl(node->flags, '+');
	turnoff_fl(node->flags, ' ');
	node->precision > 0 ? turnoff_fl(node->flags, '0') : 0;
	if (ft_strchr(node->type, 'x') || ft_strchr(node->type, 'X') || ft_strchr(node->type, 'p'))
	{
		if (n == NULL)
		{
			str = zero_cases(node, str);
			if (str)
				return (ft_print_x(node, str));
		}
		else if (ft_strchr(node->type, 'p') || cmp(node->type, "lp"))
		{
			add_flag(&node, '#');
			if (n == NULL)
			{
				str = zero_cases(node, str);
				if (str)
					return (ft_print_x(node, str));
			}
			add_flag(&node, '#');
		}
		str = ntoa_xflags(node, n, base);
	}
	else if (cmp(node->type, "b"))
		str = ft_ntoa_base((unsigned long int)n, base);
	else if (ft_strchr(node->type, 'o') || ft_strchr(node->type, 'O'))
	{
		if (n == NULL)
		{
			str = zero_cases(node, str);
	// ft_diag_print(node);
			if (str)
				return (ft_print_x(node, str));
		}
		str = ntoa_oflags(node, n, base);
		if ((int)ft_strlen(str) >= node->precision && ft_strchr(node->flags, '#'))
		{
			tmp = str;
			str = ft_strjoin("0", tmp);
			free(tmp);
		}
		if (ft_strchr(node->flags, '#'))
			ft_strchr(node->flags, '#')[0] = '^';
	}

	return (ft_print_x(node, str));
}



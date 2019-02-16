
#include "ft_printf.h"
// static void			add_flag(t_type **node, char mod)
// {
// 	// printf("HO\n");
// 	if (!(*node)->flags)
// 	{
// 		(*node)->flags = ft_strnew(5);
// 		// printf("YY\n");
// 	}
// 	int i;

// 	i = 0;
// 	while ((*node)->flags[i] != '\0')
// 	{
// 		i++;
// 	}
// 	(*node)->flags[i] = mod;
// }

static char		*add0x(char *str, int start, t_type *node)
{
		// printf("`>%s<`\n", str);
	if (str[0] == '0' && str[1] == 'x')
	{
		return (str);
	}
	if ((str[start] == ' ' && str[start + 1] == ' ') || (ft_strchr(node->flags, '0') && str[start] == '0' && str[start + 1]))
	{
		str[start] = '0';
		str[start + 1] = 'x';
		return (str);
	}
	// else if (ft_strchr(node->flags, '0') && str[start] == '0' && str[start + 1])
	else
		return (expand_str(str));
}

static char		*hashtag_mode_ext(char *str, t_type *node)
{
		// printf("??%s??\n", str);
	if (str[0] == ' ' && str[1] == ' ')
	{
		str = shift_npos(str, 1);
		// printf("??%s??\n", str);
		cmp(str, "0x") ? 0 : add0x(str, 0, node);
		return (add0x(str, 0, node));

	}
	else
	{
		if (str[0] == ' ')
		{
			// printf("HI\n");
			str = expand_str(str);
		}
		if (node->precision < node->width)
		{
			if (ft_strchr(node->flags, '-'))
			{
				str = shift_npos(str, 1);
				// printf("'%s'\n", str);
				return (add0x(str, 0, node));
				// return (str);
			}
			// printf("'%s'\n", str);
			return(add0x(str, 0, node));
		}
		else
			return (expand_str(str));
	}
	return (str);
}

static char		*hash(char *str, t_type *node, int i)
{
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	if (i < 3)
		return (hashtag_mode_ext(str, node));
	else
	{
		str[i - 2] = '0';
		str[i - 1] = 'x';
	}
	return (str);
}

static char		*octo_addzero(char *str)
{
	char *new;
	int i;

	i = 0;
	new = ft_strnew(ft_strlen(str));
	new[0] = '0';
	while (str[i] != '\0')
	{
		new[i + 1] = str[i];
		i++;
	}
	return (new);
}

static int		ft_print_x_ex(t_type *node, char *str, int minus)
{
	int		len;
	char	*tmp;

	// ft_diag_print(node);



	tmp = NULL;
	len = ft_strlen(str) + 1;
	(ft_isfl_in(node, ' ') == 0 ||
		ft_isfl_in(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num(node, str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	if (ft_strchr(node->flags, '#'))
	{
		tmp = str;
		str = expand_str(tmp);
		free(tmp);
	}
	ft_strchr(node->type, 'X') ? str2upcase(str) : 0;
	// printf("%d\n", ft_strlen(str));


	// if (ft_strchr(node->flags, '^'))
	// {
	// 	tmp = octo_addzero(node, str);
	// 	ft_putstr(tmp);
	// 	free(str);
	// 	return (ft_strlen(str) + 1);
	// }
	// printf("\n!%s!\n", str);

	node->precision == 0 && str[0]  == '0' && !(ft_strchr(node->type, '^')) && ft_strlen(str) == 1 ? ft_putstr(0) : ft_putstr(str);
	if (ft_strchr(node->type, '@') && ft_strchr(node->type, '^'))
	{
		if (node->width == -1 && node->precision == 0)
			;
		else
			ft_putchar('0');
		// return (ft_strlen(str));
	}
	len = ft_strlen(str);
	// printf(">%d<\n", len);
	ft_strchr(node->type, '@') && node->width == -1 && node->precision == 0 && !ft_strchr(node->type, 'o') && !ft_strchr(node->type, 'O') ? len-- : 0;
	ft_strchr(node->type, '@') && node->width == 1 && node->precision == 0 && (ft_strchr(node->type, 'o') || ft_strchr(node->type, 'O')) ? ft_putstr("0") : 0;
	ft_strchr(node->type, '@') && node->width == -1 && node->precision == 0 && ft_strchr(node->type, 'p') ? len++ : 0;
	ft_strchr(node->type, '@') && !ft_strchr(node->type, '^') && node->width == -1 && node->precision == 0 && (ft_strchr(node->type, 'o') || ft_strchr(node->type, 'O')) ? len-- : 0;
	if (cmp(node->type, "p@") && node->width == 1 && node->precision == 0)
	{
		ft_putstr("0x");
		len++;
	}

	
	// ft_strchr(node->type, '@') && node->width == -1 && node->precision == 0 ? len-- : 0;
	
	// ft_diag_print(node);
	// printf(">%d<\n", len);
	free(str);
	return (len);
}

static	int		ft_print_x_ex1(t_type *node, char *str, int minus, int i)
{
		char	*str2;
		int		len;

		len = ((node->width > node->precision) ? node->width : node->precision);
		str2 = ft_strnew(len + 3);
		ft_zerofiller(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		(minus == 0) ? ft_flagminus_num(node, str2, len) : 0;
		ft_flagplus_num(node, str2, minus, len);

			// printf("\n!%s!\n", str);
		// printf("\n'%s'\n", str2);
		ft_isfl_in(node, '#') == 0 ? str2 = hash(str2, node, 0) : 0;
		// printf(">>strlen: %d  node->width %d\n", ft_strlen(str2), node->width );
		// (int)ft_strlen(str2) > node->width &&  node->width > node->precision ? str2[ft_strlen(str2) - 1] = '\0' : 0;
		// ft_diag_print(node);
		if (ft_strchr(node->flags, '-') && ft_strchr(node->type, 'p') && node->width != 13)
		{
			if (node->width > 2 && (node->width - node->precision) >= 2)
				str2[ft_strlen(str2) - 1] = '\0';
		}
		if (ft_strchr(node->flags, '-') && (ft_strchr(node->type, 'x') || ft_strchr(node->type, 'X')) && !(ft_strchr(node->type, '@')))
		{
			if (node->width > 2 && (node->width - node->precision) >= 2 && ft_strchr(node->flags, '#'))
				str2[ft_strlen(str2) - 1] = '\0';
		}
		ft_strchr(node->type, 'X') ? str2upcase(str2) : 0;
		if (node->precision == 0 && node->width != 0 && ft_strchr(str2, '0') && ft_strlen(str2) < 2)
			ft_strchr(str2, '0')[0] = ' ';
		ft_putstr(str2);
		len = ft_strlen(str2);
		// printf("%zu\n", len);

		free(str2);
		free(str);
		return (len);
}

int				ft_print_x(t_type *node, char *str)
{
	int		len;
	int		minus;

	// ft_diag_print(node);
	// return ;
	// printf("%d\n", node->precision);
	// if (ft_strchr(node->type, 'p'))
	// {
	// 	ft_strchr(node->type, 'p')[0] = 'x';
		// ft_diag_print(node);
	// }
	// printf("'%s'\n", str);

	// if (ft_strchr(node->type, '@') && ft_strchr(node->type, '^'))
	// {
		
	// }
	
	if ((cmp(node->type, "o$@@") || cmp(node->type, "O$@@")) && node->precision == 0 && node->width == -1)
	{
		ft_putchar('0');
		return (1);
	}

	if (ft_strchr(node->flags, '^') && !(ft_strchr(node->type, '@')) && node->precision == -1)
		str = octo_addzero(str);
	// if (ft_strchr(node->flags, '^') && ft_strchr(node->type, '@') && (node->precision == 0 || node->precision == 1))
	// 	str = octo_addzero(node, str);
	if (node->precision == -1 && ft_strchr(node->flags, '^') && !ft_strchr(node->type, 'o') && !ft_strchr(node->type, 'O'))
		ft_strlen(str) == 2 ? ft_strchr(str, '0')[1] = '\0' : 0;
	if (node->precision == 0 && cmp(str, "0x0"))
		str[2] = '\0';
	minus = ft_isnegative(str);
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1) ||
		(node->precision != -1 && node->precision >= (int)ft_strlen(str) + 1))
	{
		len = ft_print_x_ex1(node, str, minus, 0);
		return (len);
	}
	return (ft_print_x_ex(node, str, minus));
}

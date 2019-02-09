#include "ft_printf.h"

static void		add0x(char *str, int start)
{
	str[start] = '0';
	str[start + 1] = 'x';
}

static char		*hashtag_mode_ext(char *str, t_type *node)
{
	if (str[0] != '0' && str[1] != '0')
	{
		shift_npos(str, 2);
		add0x(str, 0);
	}
	else
	{
		if (str[0] == ' ')
			str = expand_str(str);
		if (node->precision < node->width)
		{
			if (ft_strchr(node->flags, '-'))
			{
				shift_npos(str, 2);
				add0x(str, 0);
				return (str);
			}
			add0x(str, 0);
		}
		else
			return (expand_str(str));
	}
	return (str);
}

static char		*hashtag_mode(char *str, t_type *node, int i)
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

static int		ft_print_x_ex(t_type *node, char *str, int minus)
{
	int len;

	len = ft_strlen(str) + 1;
	(ft_isflag_in_struct(node, ' ') == 0 || ft_isflag_in_struct(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num(node, str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	ft_strchr(node->type, 'X') ? str2upcase(str) : 0;
	ft_putstr(str);
	free(str);
	return (len - 1);
}

int				ft_print_x(t_type *node, char *str, int i)
{
	int		len;
	int		minus;
	char	*str2;

	if (node->precision == 0 && cmp(str, "0x0"))
		str[2] = '\0';
	minus = ft_isnegative(str);
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1) ||
		(node->precision != -1 && node->precision >= (int)ft_strlen(str) + 1))
	{
		len = ((node->width > node->precision) ? node->width : node->precision);
		str2 = ft_strnew(len + 3);
		ft_zerofiller(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		(minus == 0) ? ft_flagminus_num(node, str2, len) : 0;
		ft_flagplus_num(node, str2, minus, len);
		ft_isflag_in_struct(node, '#') == SUCCESS ? str2 = hashtag_mode(str2, node, 0) : 0;
		ft_strchr(node->type, 'X') ? str2upcase(str2) : 0;
		ft_putstr(str2);
		len = ft_strlen(str2);
		free(str2);
		free(str);
		return (len);
	}
	return (ft_print_x_ex(node, str, minus));
}

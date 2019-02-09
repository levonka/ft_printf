#include "ft_printf.h"

void		ft_flagminus_num(t_type *node, char *str, int len)
{
	int		i;

	i = 0;
	if (str[0] == '0' && node->precision == -1)
		str[0] = '-';
	else if (ft_isdigit(str[0]))
	{
		len -= (str[ft_strlen(str) - 1] == ' ') ? 1 : 0;
		while (len > 0)
		{
			ft_swap(&str[len], &str[len - 1]);
			--len;
		}
		str[len] = '-';
	}
	else
	{
		while (str[i] == ' ' && str[i] != '0' && str[i] != '\0')
			i++;
		str[i - 1] = '-';
	}
}

static int	istype(char *str)
{
	const char	base[][4] = { "u", "lu", "llu", "hu", "hhu", "x", "X",
								"o", "O", "" };
	int			i;

	i = 0;
	while (cmp((char *)base[i], "") != SUCCESS)
	{
		if (cmp((char *)base[i], str))
			return (1);
		i++;
	}
	return (0);
}

void		ft_flagplus_num(t_type *node, char *str, int minus, int len)
{
	int		i;

	i = 0;
	if (ft_isflag_in_struct(node, '+') == 0 && minus == -1)
	{
		if (ft_isdigit(str[0]))
		{
			(str[len - 1] == ' ') ? str[len - 1] = '\0' : 0;
			while (len > 0)
			{
				ft_swap(&str[len], &str[len - 1]);
				--len;
			}
			str[0] = ((istype(node->type)) ? ' ' : '+');
		}
		else
		{
			while (str[i] == ' ' && str[i] != '\0')
				++i;
			str[(i == 0) ? 0 : i - 1] = ((istype(node->type)) ? ' ' : '+');
		}
	}
}

int			ft_print_int2(t_type *node, char *str, int minus)
{
	int		len;

	len = ft_strlen(str) + 1;
	(ft_isflag_in_struct(node, ' ') == 0 ||
		ft_isflag_in_struct(node, '+') == 0) ? ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num(node, str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}

int			ft_print_int(t_type *node, char *str, int i)
{
	int		len;
	int		minus;
	char	*str2;

	minus = ft_isnegative(str);
	if (cmp(str, "0") && (node->precision == 0))
		str[0] = '\0';
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1) ||
		(node->precision != -1 && node->precision >= (int)ft_strlen(str) + 1))
	{
		len = ((node->width > node->precision) ? node->width : node->precision);
		str2 = ft_strnew(len + 1);
		ft_zerofiller(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		(minus == 0) ? ft_flagminus_num(node, str2, len) : 0;
		ft_flagplus_num(node, str2, minus, len);
		write(1, str2, ft_strlen(str2));
		len = ft_strlen(str2);
		free(str2);
		free(str);
		return (len);
	}
	return (ft_print_int2(node, str, minus));
}

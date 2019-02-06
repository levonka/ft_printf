
#include "ft_printf.h"

void	ft_zerofiller(t_type *node, char *str, int len, int *i)
{
	int		pr_copy;

	pr_copy = node->precision;
	if (ft_isflag_in_struct(node, '-') == SUCCESS)
		while (*i < node->precision)
		{
			str[*i] = '0';
			*i = *i + 1;
		}
	else
		while (pr_copy > 0)
		{
			str[len - 1] = '0';
			--len;
			--pr_copy;
		}
	while (*i < len)
	{
		if ((ft_isflag_in_struct(node, '0') == SUCCESS))
			 str[*i] = (ft_isflag_in_struct(node, '-')) ? '0' : ' ';
		else
			str[*i] = ' ';
		*i = *i + 1;
	}
}


void	ft_fillin_num(t_type *node, char *to, char *from, int len)
{
	int		i;
	int		str_len;
	int		pr_copy;

	i = 0;
	str_len = ft_strlen(from) - 1;
	pr_copy = node->precision - 1;
	if (ft_isflag_in_struct(node, '-') == SUCCESS)
		while (str_len >= 0)
		{
			if (pr_copy > str_len)
				to[pr_copy] = from[str_len];
			else
				to[i] = from[i];
			++i;
			--str_len;
			--pr_copy;
		}
	else
		while (str_len >= 0)
		{
			to[len - 1] = from[str_len];
			--len;
			--str_len;
		}
}

void	ft_swap(char *a, char *b)
{
	char	buff;

	buff = *a;
	*a = *b;
	*b = buff;
}

int		ft_isnegative(char *str)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
		if (str[i++] == '-')
		{
			flag = 1;
			break;
		}
	i = 0;
	if (flag == 1)
	{
		while (str[i + 1] != '\0')
		{
			ft_swap(&str[i], &str[i + 1]);
			++i;
		}
		str[i] = '\0';
		return (SUCCESS);
	}
	return (FAIL);
}

void	ft_flagminus_num(t_type *node, char *str, int len)
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

void	ft_flagsp_num(char *str, int len)
{
	int		i;

	i = 0;
	while (len > 0)
	{
		ft_swap(&str[len], &str[len - 1]);
		--len;
	}
	str[0] = ' ';
}

void	ft_flagplus_num(t_type *node, char *str, int minus, int len)
{
	int		i;

	i = 0;
	if (ft_isflag_in_struct(node, '+') == 0 && minus == -1)
	{
		if (ft_isdigit(str[0]))
		{
			// --len;
			(str[len - 1] == ' ') ? str[len - 1] = '\0' : 0;
			while (len > 0)
			{
				ft_swap(&str[len], &str[len - 1]);
				--len;
			}
			str[0] = ((cmp(node->type, "u") || cmp(node->type, "lu") || cmp(node->type, "llu") || cmp(node->type, "hu") || cmp(node->type, "hhu") || cmp(node->type, "x") || cmp(node->type, "X") || cmp(node->type, "o") || cmp(node->type, "O")) ? ' ' : '+');
		}
		else
		{
			while (str[i] == ' ' && str[i] != '\0')
				++i;
			str[(i == 0) ? 0 : i - 1] = ((cmp(node->type, "u")  || cmp(node->type, "lu") || cmp(node->type, "llu") || cmp(node->type, "hu") || cmp(node->type, "hhu") || cmp(node->type, "x") || cmp(node->type, "X") || cmp(node->type, "o") || cmp(node->type, "O")) ? ' ' : '+');
		}
	}
}

void	ft_print_int(t_type *node, char *str, int i)
{
	int		len;
	int		minus;
	char	*str2;

	minus = ft_isnegative(str);
	if ((node->width != -1 && node->width >= (int)ft_strlen(str) + 1) ||
		(node->precision != -1 && node->precision >= (int)ft_strlen(str) + 1))
	{
		len = ((node->width > node->precision) ? node->width : node->precision);
		str2 = ft_strnew(len + 1);
		ft_zerofiller(node, str2, len, &i);
		ft_fillin_num(node, str2, str, len);
		(minus == 0) ? ft_flagminus_num(node, str2, len) : 0;
		// printf("%s\n", str2);
		ft_flagplus_num(node, str2, minus, len);
		write(1, str2, ft_strlen(str2));
		free(str2);
		free(str);
		return ;
	}
	len = ft_strlen(str) + 1;
	(ft_isflag_in_struct(node, ' ') == 0 || ft_isflag_in_struct(node, '+') == 0) ?
	ft_flagsp_num(str, len) : 0;
	(minus == 0) ? ft_flagminus_num(node, str, len) : 0;
	ft_flagplus_num(node, str, minus, len);
	write(1, str, ft_strlen(str));
	free(str);
}

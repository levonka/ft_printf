#include "ft_printf.h"

void		turnoff_fl(char *flags, char c)
{
	int i;
	char buf;

	i = -1;
	while(flags[++i] != '\0')
	{
		if (flags[i] == c)
		{
			if (flags[i + 1] == '\0')
				flags[i] = '\0';
			else
			{
				buf = flags[i];
				flags[i] = flags[i + 1];
				flags[i + 1] = buf;
			}
		}
	}
}

char		*ft_ntoa_base(uintmax_t n, int base)
{
	char	*res;
	int		len;
	static char	*nums = "0123456789abcdef";

	res = NULL;
	len = ft_nlen(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (len + 4))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (len && n)
	{
		res[len - 1] = nums[ft_abs(n % base)];
		n = n / base;
		len--;
	}
	return (res);
}

void		shift_npos(char *str, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(n > 0)
	{
		while (str[i] != ' ')
			i++;
		j = i;
		while(i >= 0 && str[i - 1] != ' ')
		{
			ft_swap(&str[i - 1], &str[i]);
			i--;
		}
		n--;
		i++;
	}
}

char		*expand_str(char *str)
{
	char *exp;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	j != 1 ? j = 0 : 0;
	exp = ft_strnew(ft_strlen(str) + 2);
	exp[i++] = '0';
	exp[i++] = 'x';
	while (str[j] != '\0')
	{
		exp[i] = str[j];
		j++;
		i++;
	}
	exp[i] = '\0';
	return (exp);
}

double		int2pow(double nb, int pow)
{
	double x;

	x = nb;
	if (pow == 0)
		return (1);
	if (pow < 0)
		return (-1);
	while (--pow)
		nb *= x;
	return (nb);
}
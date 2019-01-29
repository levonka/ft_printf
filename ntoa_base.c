#include "ft_printf.h"

static void		*ft_reverse(char *str)
{
	int		i;
	char	*rev;
	int		len;

	len = ft_strlen(str);
	rev = ft_strnew(len);
	i = 0;
	while (len > 0)
		rev[i++] = str[len-- - 1];
	return (rev);
}

static size_t	udigit_count(uintmax_t n, unsigned int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

static char		*ft_uitoa(uintmax_t n, unsigned int base, char *nums)
{
	size_t		count;
	char		*str;

	count = udigit_count(n, base);
	// printf("%d\n", precision);
	// if (count < precision)
	// {
	// 	count = precision;
	// }
	str = ft_strnew(count + 1);
	// printf("%d\n", count);
	while (count > 0)
	{
		if (n % base >= 10)
			str[count-1] = 97 + n % base - 10;
		else
			str[count - 1] = nums[n % base];
		n /= base;
		--count;
	}
	return (str);
}


char			*hex_maker(int hex, char x)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(21);
	printf("%d\n", hex);
	while (1)
	{
		if (hex <= 15)
		{
			if (hex >= 10)
				str[i] = x + hex - 10;
			else
				str[i] = hex + '0';
			return (ft_reverse(str));
		}
		if (hex % 16 >= 10)
			str[i] = x + (hex % 16) - 10;
		else
			str[i] = hex % 16 + '0';
		hex /= 16;
		++i;
	}
}

char			*oct_maker(int octet, int base)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(15);
	while (1)
	{
		if (octet <= base - 1)
		{
			str[i] = octet + '0';
			return (ft_reverse(str));
		}
		else
			str[i] = octet % base + '0';
		octet /= base;
		++i;
	}
}

static void	nums_array_filler(char *str, int i)
{
	while (i < 10)
	{
		str[i] = i + '0';
		i++;
	}
	str[i] = '\0';
}

void ntoa_dispatcher(t_type *node, unsigned int nb, int i)
{
	char nums[11];
	char *str;

	nums_array_filler(nums, 0);
	str = ft_uitoa(nb, 16, nums);
	// printf("'%s'\n", str);
	printf("%s", str);
}
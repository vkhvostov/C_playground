#include "ft_printf.h"

int	print_hex(unsigned int n, char spec)
{
	char	*base;
	char	*hex_str;
	int		count;

	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	hex_str = number_to_hex(n, base);
	if (!hex_str)
		return (-1);
	count = ft_putstr(hex_str);
	free(hex_str);
	return (count);
}

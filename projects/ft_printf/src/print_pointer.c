#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	char	*hex_str;
	int		count;
	int		temp;

	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	hex_str = number_to_hex((uintptr_t)ptr, "0123456789abcdef");
	if (!hex_str)
		return (-1);
	temp = ft_putstr(hex_str);
	if (temp < 0)
	{
		free(hex_str);
		return (-1);
	}
	count += temp;
	free(hex_str);
	return (count);
}

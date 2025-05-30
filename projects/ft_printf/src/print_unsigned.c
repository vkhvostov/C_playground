#include "ft_printf.h"

int	print_unsigned(unsigned int number)
{
	char	*str;
	int		count;

	str = utoa(number);
	if (!str)
		return (-1);
	count = write(1, str, ft_strlen(str));
	free(str);
	return (count);
}

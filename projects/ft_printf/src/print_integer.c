#include "ft_printf.h"

int	print_integer(int n)
{
	int	count;

	count = 0;
	return (ft_putnbr(n, &count));
}

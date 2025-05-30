#include "ft_printf.h"

int	print_string(char *s)
{
	if (!s)
		s = "(null)";
	return (ft_putstr(s));
}

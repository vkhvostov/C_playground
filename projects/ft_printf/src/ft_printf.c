#include "ft_printf.h"

static int	handle_format(char spec, va_list *args)
{
	if (spec == 'c')
		return (print_char(va_arg(*args, int)));
	if (spec == 's')
		return (print_string(va_arg(*args, char *)));
	if (spec == 'p')
		return (print_pointer(va_arg(*args, void *)));
	if (spec == 'd' || spec == 'i')
		return (print_integer(va_arg(*args, int)));
	if (spec == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(*args, unsigned int), spec));
	if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		current_count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			current_count = handle_format(*str, &args);
		}
		else
			current_count = write(1, str, 1);
		if (current_count < 0)
			return (-1);
		count += current_count;
		str++;
	}
	va_end(args);
	return (count);
}

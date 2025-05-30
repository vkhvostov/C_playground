#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (0);
	count = write(1, s, ft_strlen(s));
	return (count);
}

int	ft_putnbr(int n, int *count)
{
	char	digit;
	int		current_count;

	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		current_count = ft_putchar('-');
		if (current_count == -1)
			return (-1);
		*count += current_count;
		n = -n;
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10, count) == -1)
			return (-1);
	}
	digit = n % 10 + '0';
	current_count = ft_putchar(digit);
	if (current_count == -1)
		return (-1);
	*count += current_count;
	return (*count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

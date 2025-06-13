#include "../includes/fdf.h"

#define BASE_LOW "0123456789abcdef"
#define BASE_HIGH "0123456789ABCDEF"

static int	digit_to_base(char *digit, int position)
{
	int	index;
	int	current_result;

	index = 0;
	while (BASE_LOW[index] || BASE_HIGH[index])
	{
		if (BASE_LOW[index] == *digit || BASE_HIGH[index] == *digit)
			break ;
		else
			index++;
	}
	current_result = 1;
	while (position > 0)
	{
		current_result *= 16;
		position--;
	}
	return (index * current_result);
}

int	hex_to_int(char *str)
{
	int	index;
	int	num;

	index = 0;
	num = 0;
	index = ft_strlen(str);
	while (*str && index--)
	{
		num += digit_to_base(str, index);
		str++;
	}
	return (num);
}

#include "push_swap.h"

static int	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static int	is_number(char *arg)
{
	int	index;

	index = 0;
	if (arg[0] == '-' || arg[0] == '+')
	{
		index++;
		if (!arg[index])
			return (0);
	}
	while (arg[index])
	{
		if (!ft_isdigit(arg[index]))
			return (0);
		index++;
	}
	return (1);
}

static long	ft_strtol(char *str)
{
	int		index;
	long	result;
	int		sign;

	index = 0;
	result = 0;
	sign = 1;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result * sign);
}

static int	is_int(char *arg)
{
	long	number;

	number = ft_strtol(arg);
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	return (1);
}

int	is_input_valid(int count, char *args[])
{
	int	index;
	int	inner_index;

	index = 1;
	while (index < count)
	{
		if (ft_strlen(args[index]) == 0)
			return (exit_error());
		if (!is_number(args[index]))
			return (exit_error());
		if (!is_int(args[index]))
			return (exit_error());
		inner_index = index + 1;
		while (inner_index < count)
		{
			if (ft_atoi(args[index]) == ft_atoi(args[inner_index]))
				return (exit_error());
			inner_index++;
		}
		index++;
	}
	return (1);
}

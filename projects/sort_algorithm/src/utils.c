#include "push_swap.h"

int	bigger_than(int a, int b)
{
	return (a > b);
}

int	smaller_than(int a, int b)
{
	return (a < b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	contains(t_lis *l, int value)
{
	int	i;

	i = 0;
	while (i < l->length)
	{
		if (l->sequence[i] == value)
			return (1);
		i++;
	}
	return (0);
}

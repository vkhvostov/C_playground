#include "push_swap.h"

/**
 * Helper to get the integer content of the node
 */
int	int_content(t_list *node)
{
	return ((int)(intptr_t)node->content);
}

/**
 * Helper to repeat a function multiple times
 */
void	repeat(t_stacks *stacks, void (*f)(t_stacks *), int times)
{
	while (times--)
		f(stacks);
}

int	*to_array(t_list *node)
{
	int	*array;
	int	index;

	array = malloc(ft_lstsize(node) * sizeof(int));
	index = 0;
	while (node)
	{
		array[index] = int_content(node);
		node = node->next;
		index++;
	}
	return (array);
}

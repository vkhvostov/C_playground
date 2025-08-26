#include "checker.h"

/**
 * Checks if the list is sorted, starting from provided node
 */
int	is_sorted(t_list *node)
{
	t_list	*current;

	if (node == NULL)
		return (1);
	current = node;
	while (current->next)
	{
		if (int_content(current) > int_content(current->next))
			return (0);
		current = current->next;
	}
	return (1);
}

/**
 * Helper to get the integer content of the node
 */
int	int_content(t_list *node)
{
	return ((int)(intptr_t)node->content);
}

/**
 * Free memory of the list
 */
void	free_nodes(t_list *node)
{
	t_list	*next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

/**
 * Free memory of the stacks
 */
void	free_memory(t_stacks *stacks)
{
	if (stacks == NULL)
		return ;
	free_nodes(stacks->top_a);
	free_nodes(stacks->top_b);
	free_nodes(stacks->instructions);
}

/**
 * Externalization of freeing the memory and printing the error message
 */
int	exit_error(t_stacks *stacks)
{
	if (stacks)
		free_memory(stacks);
	ft_putstr_fd("Error\n", 2);
	return (0);
}

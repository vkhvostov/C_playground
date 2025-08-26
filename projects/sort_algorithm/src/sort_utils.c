#include "push_swap.h"

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
 * Sorts two elements in the list
 * It is able to sort in both ascending and descending order
 * Works with both stacks A and B
 */
void	sort_two(t_list **top, int ascending, t_stacks *stacks,
		void (*swap)(t_stacks *stacks))
{
	if (ascending)
	{
		if (int_content(*top) > int_content((*top)->next))
			swap(stacks);
	}
	else
	{
		if (int_content(*top) < int_content((*top)->next))
			swap(stacks);
	}
}

/**
 * Sorts three elements in the list
 * Works only with stack A
 */
void	sort_three(t_stacks *stacks)
{
	int	current_value;
	int	next_value;

	while (!is_sorted(stacks->top_a))
	{
		current_value = int_content(stacks->top_a);
		next_value = int_content((stacks->top_a)->next);
		if (current_value > next_value
			&& current_value > int_content((stacks->top_a)->next->next))
			ra(stacks);
		else if (current_value > next_value)
			sa(stacks);
		else
			rra(stacks);
	}
}

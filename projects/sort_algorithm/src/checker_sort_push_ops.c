#include "checker.h"

void	pa(t_stacks *stacks)
{
	t_list	*node;

	if (stacks->top_b == NULL)
		return ;
	node = stacks->top_b;
	stacks->top_b = node->next;
	node->next = stacks->top_a;
	stacks->top_a = node;
}

void	pb(t_stacks *stacks)
{
	t_list	*node;

	if (stacks->top_a == NULL)
		return ;
	node = stacks->top_a;
	stacks->top_a = node->next;
	node->next = stacks->top_b;
	stacks->top_b = node;
}

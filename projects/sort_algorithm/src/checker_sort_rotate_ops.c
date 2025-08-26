#include "checker.h"

static void	rotate(t_list **top)
{
	t_list	*last;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	last = *top;
	while (last->next)
		last = last->next;
	last->next = *top;
	*top = (*top)->next;
	last->next->next = NULL;
}

void	ra(t_stacks *stacks)
{
	rotate(&stacks->top_a);
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->top_b);
}

void	rr(t_stacks *stacks)
{
	rotate(&stacks->top_a);
	rotate(&stacks->top_b);
}

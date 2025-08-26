#include "checker.h"

static void	swap_top(t_list **top)
{
	t_list	*new_top;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	new_top = (*top)->next;
	(*top)->next = new_top->next;
	new_top->next = *top;
	*top = new_top;
}

void	sa(t_stacks *stacks)
{
	swap_top(&stacks->top_a);
}

void	sb(t_stacks *stacks)
{
	swap_top(&stacks->top_b);
}

void	ss(t_stacks *stacks)
{
	swap_top(&stacks->top_a);
	swap_top(&stacks->top_b);
}

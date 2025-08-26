#include "push_swap.h"

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
	ft_lstadd_back(&stacks->instructions, ft_lstnew("sa"));
}

void	sb(t_stacks *stacks)
{
	swap_top(&stacks->top_b);
	ft_lstadd_back(&stacks->instructions, ft_lstnew("sb"));
}

void	ss(t_stacks *stacks)
{
	swap_top(&stacks->top_a);
	swap_top(&stacks->top_b);
	ft_lstadd_back(&stacks->instructions, ft_lstnew("ss"));
}

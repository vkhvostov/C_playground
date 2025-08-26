#include "push_swap.h"

static void	reverse_rotate(t_list **top)
{
	t_list	*last;
	t_list	*new_last;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	last = *top;
	while (last->next)
	{
		if (last->next->next == NULL)
			new_last = last;
		last = last->next;
	}
	new_last->next = NULL;
	last->next = *top;
	*top = last;
}

void	rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->top_a);
	ft_lstadd_back(&stacks->instructions, ft_lstnew("rra"));
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->top_b);
	ft_lstadd_back(&stacks->instructions, ft_lstnew("rrb"));
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&stacks->top_a);
	reverse_rotate(&stacks->top_b);
	ft_lstadd_back(&stacks->instructions, ft_lstnew("rrr"));
}

#include "checker.h"

static void	execute_instructions(t_stacks *stacks, char *instruction)
{
	if (ft_strncmp(instruction, "sa", 3) == 0)
		sa(stacks);
	else if (ft_strncmp(instruction, "sb", 3) == 0)
		sb(stacks);
	else if (ft_strncmp(instruction, "ss", 3) == 0)
		ss(stacks);
	else if (ft_strncmp(instruction, "pa", 3) == 0)
		pa(stacks);
	else if (ft_strncmp(instruction, "pb", 3) == 0)
		pb(stacks);
	else if (ft_strncmp(instruction, "ra", 3) == 0)
		ra(stacks);
	else if (ft_strncmp(instruction, "rb", 3) == 0)
		rb(stacks);
	else if (ft_strncmp(instruction, "rr", 3) == 0)
		rr(stacks);
	else if (ft_strncmp(instruction, "rra", 4) == 0)
		rra(stacks);
	else if (ft_strncmp(instruction, "rrb", 4) == 0)
		rrb(stacks);
	else if (ft_strncmp(instruction, "rrr", 4) == 0)
		rrr(stacks);
}

static int	verify_instructions(t_stacks *stacks)
{
	t_list	*instruction;
	char	*content;

	instruction = stacks->instructions;
	content = (char *)instruction->content;
	while (instruction)
	{
		execute_instructions(stacks, content);
		instruction = instruction->next;
		if (instruction)
			content = (char *)instruction->content;
	}
	free_nodes(stacks->instructions);
	stacks->instructions = NULL;
	return (is_sorted(stacks->top_a) && stacks->top_b == NULL);
}

int	check(t_stacks *stacks)
{
	if (is_sorted(stacks->top_a) && stacks->top_b == NULL
		&& stacks->instructions == NULL)
		return (1);
	if (stacks->top_a != NULL && stacks->top_a->next == NULL
		&& stacks->top_b == NULL && stacks->instructions == NULL)
		return (1);
	if (stacks->instructions != NULL)
		return (verify_instructions(stacks));
	return (0);
}

#include "push_swap.h"

static void	free_nodes(t_list *node)
{
	t_list	*next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

static void	free_memory(t_stacks *stacks)
{
	t_list	*node;

	if (stacks == NULL)
		return ;
	node = stacks->top_a;
	free_nodes(node);
	node = stacks->top_b;
	free_nodes(node);
	node = stacks->instructions;
	free_nodes(node);
}

static void	print_instructions(t_list *instructions)
{
	t_list	*current;
	char	*instruction;

	current = instructions;
	while (current)
	{
		instruction = (char *)current->content;
		ft_putstr_fd(instruction, 1);
		ft_putstr_fd("\n", 1);
		current = current->next;
	}
}

static t_list	*process_input(int count, char *args[])
{
	int		i;
	t_list	*head;
	t_list	*node;

	head = ft_lstnew((void *)(intptr_t)ft_atoi(args[1]));
	node = head;
	if (node == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	i = 2;
	while (i < count)
	{
		node->next = ft_lstnew((void *)(intptr_t)ft_atoi(args[i]));
		if (node->next == NULL)
		{
			free_nodes(head);
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		node = node->next;
		i++;
	}
	return (head);
}

int	main(int count, char *args[])
{
	t_stacks	stacks;

	if (count < 2)
		return (0);
	if (!is_input_valid(count, args))
		return (1);
	stacks.top_a = process_input(count, args);
	stacks.top_b = NULL;
	stacks.instructions = NULL;
	sort(&stacks);
	print_instructions(stacks.instructions);
	free_memory(&stacks);
	return (0);
}

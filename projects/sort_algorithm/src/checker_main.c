#include "checker.h"

static t_list	*process_input(int count, char *args[])
{
	int		i;
	t_list	*head;
	t_list	*node;

	head = ft_lstnew((void *)(intptr_t)ft_atoi(args[1]));
	node = head;
	if (node == NULL)
	{
		exit_error(NULL);
		return (NULL);
	}
	i = 2;
	while (i < count)
	{
		node->next = ft_lstnew((void *)(intptr_t)ft_atoi(args[i]));
		if (node->next == NULL)
		{
			free_nodes(head);
			exit_error(NULL);
			return (NULL);
		}
		node = node->next;
		i++;
	}
	return (head);
}

static void	free_split(char **array)
{
	char	**temp;

	temp = array;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(array);
}

static int	process_instructions_2(t_stacks *stacks, char *line, char **temp)
{
	if (!valid_instructions(stacks->instructions, line))
	{
		free(line);
		free_split(temp);
		return (exit_error(stacks));
	}
	check(stacks);
	free(line);
	free_split(temp);
	return (1);
}

static int	process_instructions(t_stacks *stacks)
{
	char	**instructions;
	char	*line;
	char	**temp;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (line[ft_strlen(line) - 1] != '\n')
			return (exit_error(stacks));
		instructions = ft_split(line, '\n');
		temp = instructions;
		while (*instructions)
		{
			if (stacks->instructions == NULL)
				stacks->instructions = ft_lstnew(*instructions);
			else
				ft_lstadd_back(&stacks->instructions, ft_lstnew(*instructions));
			instructions++;
		}
		if (!process_instructions_2(stacks, line, temp))
			return (0);
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
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
	if (!process_instructions(&stacks))
		return (1);
	if (check(&stacks))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_memory(&stacks);
	return (0);
}

#include "checker.h"

static int	count_char(char *buffer, char c)
{
	int	count;

	count = 0;
	while (*buffer)
	{
		if (*buffer == c)
			count++;
		buffer++;
	}
	return (count);
}

static int	valid_instruction(char *instruction)
{
	if (ft_strncmp(instruction, "sa", 3) == 0
		|| ft_strncmp(instruction, "sb", 3) == 0
		|| ft_strncmp(instruction, "ss", 3) == 0
		|| ft_strncmp(instruction, "pa", 3) == 0
		|| ft_strncmp(instruction, "pb", 3) == 0
		|| ft_strncmp(instruction, "ra", 3) == 0
		|| ft_strncmp(instruction, "rb", 3) == 0
		|| ft_strncmp(instruction, "rr", 3) == 0
		|| ft_strncmp(instruction, "rra", 4) == 0
		|| ft_strncmp(instruction, "rrb", 4) == 0
		|| ft_strncmp(instruction, "rrr", 4) == 0)
		return (1);
	return (0);
}

int	valid_instructions(t_list *instruction, char *buffer)
{
	char	*content;

	if (count_char(buffer, '\n') != ft_lstsize(instruction))
		return (0);
	while (instruction)
	{
		content = (char *)instruction->content;
		if (!valid_instruction(content))
			return (0);
		instruction = instruction->next;
	}
	return (1);
}

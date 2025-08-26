#include "push_swap.h"

/**
 * Optimize the rotations for the given index and value
 * The function will return the best rotations to move the value from stack A
 * to stack B
 * It tries to optimize the number of operations by rotating stacks in the right
 * direction and if possible rotating both stacks at the same time
 */
static t_rotations	optimize_rotations(int index, int value, t_stacks *stacks)
{
	t_rotation	rot_a;
	t_rotation	rot_b;
	t_rotations	rots;
	int			index_b;

	rot_a = distance_to_top(index, ft_lstsize(stacks->top_a));
	index_b = match_value_index(value, stacks->top_b,
			smaller_than, bigger_than);
	rot_b = distance_to_top(index_b, ft_lstsize(stacks->top_b));
	if (rot_a.direction == rot_b.direction)
		rots = create_rotations(rot_a, rot_b);
	else
	{
		rots.rotation_both.count = 0;
		rots.rotation_both.direction = 0;
		rots.rotation_a = rot_a;
		rots.rotation_b = rot_b;
	}
	rots.count = rots.rotation_a.count + rots.rotation_b.count
		+ rots.rotation_both.count;
	return (rots);
}

/**
 * Find the smallest number of operations required to move a value from stack A
 * to stack B
 * All values from the stack A are evaluated and the best rotations are returned
 */
static t_rotations	count_ops(t_stacks *stacks, t_lis *lis)
{
	int			index;
	t_rotations	rotations;
	t_rotations	best_rot;
	t_list		*current;

	index = 0;
	best_rot.count = -1;
	current = stacks->top_a;
	while (current)
	{
		if (contains(lis, int_content(current)))
		{
			current = current->next;
			index++;
			continue ;
		}
		rotations = optimize_rotations(index, int_content(current), stacks);
		if (best_rot.count == -1 || rotations.count < best_rot.count)
			best_rot = rotations;
		current = current->next;
		index++;
	}
	return (best_rot);
}

/**
 * Execute the operations based on the rotations provided
 */
static void	execute_ops(t_rotations rotations, t_stacks *stacks,
		void (*push)(t_stacks *))
{
	if (rotations.rotation_both.direction > 0)
		repeat(stacks, rr, rotations.rotation_both.count);
	else
		repeat(stacks, rrr, rotations.rotation_both.count);
	if (rotations.rotation_a.direction > 0)
		repeat(stacks, ra, rotations.rotation_a.count);
	else
		repeat(stacks, rra, rotations.rotation_a.count);
	if (rotations.rotation_b.direction > 0)
		repeat(stacks, rb, rotations.rotation_b.count);
	else
		repeat(stacks, rrb, rotations.rotation_b.count);
	push(stacks);
}

/**
 * Initial checks and all operations required to move values from stack A to
 * stack B in the right order + sort the remaining values in stack A
 */
static int	initial_sort_part(t_stacks *stacks)
{
	t_lis	*lis;

	if (stacks->top_a == NULL || is_sorted(stacks->top_a)
		|| ft_lstsize(stacks->top_a) == 1)
		return (0);
	if (ft_lstsize(stacks->top_a) == 2)
	{
		sort_two(&stacks->top_a, 1, stacks, sa);
		return (0);
	}
	if (ft_lstsize(stacks->top_a) == 3)
	{
		sort_three(stacks);
		return (0);
	}
	lis = find_lis(to_array(stacks->top_a), ft_lstsize(stacks->top_a));
	while (ft_lstsize(stacks->top_a) > max(3, lis->length))
		execute_ops(count_ops(stacks, lis), stacks, pb);
	if (ft_lstsize(stacks->top_a) == 2)
		sort_two(&stacks->top_a, 1, stacks, sa);
	else if (ft_lstsize(stacks->top_a) == 3)
		sort_three(stacks);
	free(lis->sequence);
	free(lis);
	return (1);
}

/**
 * Main sorting function that sorts stacks and calls other functions
 */
void	sort_stacks(t_stacks *stacks)
{
	t_rotation	rotation;
	t_rotations	rotations;

	if (!initial_sort_part(stacks))
		return ;
	while (stacks->top_b)
	{
		rotation = distance_to_top(
				match_value_index(int_content(stacks->top_b), stacks->top_a,
					bigger_than, smaller_than), ft_lstsize(stacks->top_a));
		rotations.count = rotation.count;
		rotations.rotation_a = rotation;
		rotations.rotation_b.count = 0;
		rotations.rotation_b.direction = 0;
		rotations.rotation_both.count = 0;
		rotations.rotation_both.direction = 0;
		execute_ops(rotations, stacks, pa);
	}
	rotation = distance_to_top(find_value_index(stacks->top_a, smaller_than),
			ft_lstsize(stacks->top_a));
	if (rotation.direction > 0)
		repeat(stacks, ra, rotation.count);
	else
		repeat(stacks, rra, rotation.count);
}

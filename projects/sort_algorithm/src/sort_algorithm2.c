#include "push_swap.h"

/**
 * Find the shortest distance to the top of the stack based on the index
 */
t_rotation	distance_to_top(int index, int size)
{
	t_rotation	rotation;

	if (index < (size + 1) / 2)
	{
		rotation.count = index;
		rotation.direction = 1;
	}
	else
	{
		rotation.count = size - index;
		rotation.direction = -1;
	}
	return (rotation);
}

/**
 * Find the index of the value, which is either max or min,
 * depending on the compare function provided
 */
int	find_value_index(t_list *stack, int (*compare)(int, int))
{
	int	index;
	int	search_index;
	int	search_value;

	index = 0;
	search_index = 0;
	if (stack == NULL)
		return (index);
	search_value = int_content(stack);
	while (stack)
	{
		if (compare(int_content(stack), search_value))
		{
			search_value = int_content(stack);
			search_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (search_index);
}

/**
 * Find the index of the value, which is closest to the candidate,
 * depending on the compare function provided, i.e.
 * when bigger_than is provided, the function will return the index of the value
 * which is closest to the candidate and bigger than the candidate
 * when smaller_than is provided, the function will return the index of the value
 * which is closest to the candidate and smaller than the candidate
 */
static int	find_closest_value_index(int candidate, t_list *stack,
	int (*compare)(int, int))
{
	int	index;
	int	best_index;
	int	best_distance;

	index = 0;
	best_index = -1;
	best_distance = INT_MAX;
	while (stack)
	{
		if (int_content(stack) == candidate)
			return (index);
		if (compare(int_content(stack), candidate))
		{
			if (ABS(candidate - int_content(stack)) < best_distance)
			{
				best_distance = ABS(candidate - int_content(stack));
				best_index = index;
			}
		}
		stack = stack->next;
		index++;
	}
	return (best_index);
}

/**
 * Find the index of the value, which is matching to the candidate,
 * Such that it is either bigger or smaller than the candidate, depending on the
 * compare function provided.
 * If the candidate is smaller than all values in stack A, it is placed above
 * the largest value in the stack B
 * If the candidate is bigger than all values in stack A, it is placed below
 * the smallest value in the stack B
 */
int	match_value_index(int candidate, t_list *stack,
	int (*bigger_or_smaller)(int, int), int (*max_or_min)(int, int))
{
	int	closes_value_index;

	closes_value_index = find_closest_value_index(candidate, stack,
			bigger_or_smaller);
	if (closes_value_index != -1)
		return (closes_value_index);
	else
		return (find_value_index(stack, max_or_min));
}

/**
 * Create a structure with the rotations, just spitted due to the Norms
 */
t_rotations	create_rotations(t_rotation rotation_a, t_rotation rotation_b)
{
	t_rotations	rotations;

	if (rotation_a.count > rotation_b.count)
	{
		rotations.rotation_both.count = rotation_b.count;
		rotations.rotation_both.direction = rotation_b.direction;
		rotation_a.count -= rotation_b.count;
		rotation_b.count = 0;
		rotations.rotation_a = rotation_a;
		rotations.rotation_b = rotation_b;
	}
	else
	{
		rotations.rotation_both.count = rotation_a.count;
		rotations.rotation_both.direction = rotation_a.direction;
		rotation_b.count -= rotation_a.count;
		rotation_a.count = 0;
		rotations.rotation_a = rotation_a;
		rotations.rotation_b = rotation_b;
	}
	return (rotations);
}

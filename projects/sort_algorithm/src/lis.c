#include "push_swap.h"

static int	binary_search(int arr[], int sub[], int length, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = length;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (arr[sub[mid]] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

static void	construct_lis(int arr[], int parent[], t_lis *result, int end_index)
{
	int	index;

	index = result->length - 1;
	while (end_index >= 0)
	{
		result->sequence[index] = arr[end_index];
		end_index = parent[end_index];
		index--;
	}
}

static t_lis	*allocate(int length, int arr[], int *parent, int end_index)
{
	t_lis	*result;

	result = malloc(sizeof(t_lis));
	result->length = length;
	result->sequence = malloc(length * sizeof(int));
	construct_lis(arr, parent, result, end_index);
	free(arr);
	return (result);
}

static t_lis_vars	*init_lis_vars(int n)
{
	t_lis_vars	*vars;

	vars = malloc(sizeof(t_lis_vars));
	vars->sub = malloc(n * sizeof(int));
	vars->parent = malloc(n * sizeof(int));
	vars->length = 0;
	vars->end_index = -1;
	vars->index = 0;
	return (vars);
}

t_lis	*find_lis(int arr[], int n)
{
	t_lis_vars	*vars;
	t_lis		*result;

	vars = init_lis_vars(n);
	while (vars->index < n)
	{
		vars->pos = binary_search(arr, vars->sub, vars->length,
				arr[vars->index]);
		vars->sub[vars->pos] = vars->index;
		if (vars->pos > 0)
			vars->parent[vars->index] = vars->sub[vars->pos - 1];
		else
			vars->parent[vars->index] = -1;
		if (vars->pos == vars->length)
		{
			vars->length++;
			vars->end_index = vars->index;
		}
		vars->index++;
	}
	result = allocate(vars->length, arr, vars->parent, vars->end_index);
	free(vars->sub);
	free(vars->parent);
	free(vars);
	return (result);
}

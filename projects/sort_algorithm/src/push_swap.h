#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

# define ABS(value) ((value) * (((value) > 0) - ((value) < 0)))

typedef struct s_stacks
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*instructions;
}	t_stacks;

typedef struct s_rotation
{
	int	count;
	int	direction;
}	t_rotation;

typedef struct s_rotations
{
	int			count;
	t_rotation	rotation_a;
	t_rotation	rotation_b;
	t_rotation	rotation_both;
}	t_rotations;

typedef struct s_lis
{
	int	length;
	int	*sequence;
}	t_lis;

typedef struct s_lis_vars
{
	int	*sub;
	int	*parent;
	int	length;
	int	end_index;
	int	index;
	int	pos;
}	t_lis_vars;

void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

int			bigger_than(int a, int b);
int			smaller_than(int a, int b);
int			max(int a, int b);
int			contains(t_lis *l, int value);

t_lis		*find_lis(int arr[], int n);

int			is_input_valid(int count, char *args[]);

t_rotation	distance_to_top(int index, int size);
int			find_value_index(t_list *stack, int (*compare)(int, int));
int			match_value_index(int candidate, t_list *stack,
				int (*bg_or_sm)(int, int), int (*max_or_min)(int, int));
t_rotations	create_rotations(t_rotation rotation_a, t_rotation rotation_b);

int			int_content(t_list *node);
void		repeat(t_stacks *stacks, void (*f)(t_stacks *), int times);
int			*to_array(t_list *node);

int			is_sorted(t_list *node);
void		sort_two(t_list **top, int ascending, t_stacks *stacks,
				void (*swap)(t_stacks *stacks));
void		sort_three(t_stacks *stacks);
void		sort_stacks(t_stacks *stacks);

void		sort(t_stacks *stacks);

#endif

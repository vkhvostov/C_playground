#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define BUFFER_SIZE 30000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define FD_MAX 1024

typedef struct s_stacks
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*instructions;
}	t_stacks;

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

int		is_input_valid(int count, char *args[]);
int		valid_instructions(t_list *instruction, char *buffer);

int		int_content(t_list *node);
int		is_sorted(t_list *node);
int		exit_error(t_stacks *stacks);
void	free_nodes(t_list *node);
void	free_memory(t_stacks *stacks);

int		check(t_stacks *stacks);

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}

/* 
#include <stdio.h>
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list *elem1 = ft_lstnew("element1");
	t_list *elem2 = ft_lstnew("element2");
	t_list *elem3 = ft_lstnew("element3");

	ft_lstadd_back(&elem1, elem2);
	ft_lstadd_back(&elem2, elem3);
	ft_lstiter(elem1, &print_content);
	return (0);
}
 */
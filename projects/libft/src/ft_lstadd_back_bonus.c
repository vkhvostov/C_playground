#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last)
		last->next = new;
	else
		*lst = new;
}

/* 
#include <stdio.h>
int	main(void)
{
	t_list *elem = ft_lstnew("element1");
	t_list *elem2 = ft_lstnew("element2");
	t_list *elem3 = ft_lstnew("element3");

	ft_lstadd_back(&elem, elem2);
	ft_lstadd_back(&elem2, elem3);
	t_list *current = elem;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
 */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current && current->next)
		current = current->next;
	return (current);
}

/* 
#include <stdio.h>
int	main(void)
{
	t_list *elem1 = ft_lstnew("element1");
	t_list *elem2 = ft_lstnew("element2");
	t_list *elem3 = ft_lstnew("element3");

	ft_lstadd_front(&elem1, elem2);
	ft_lstadd_front(&elem2, elem3);
	printf("%s\n", (char *)ft_lstlast(elem3)->content);
	return (0);
}
 */
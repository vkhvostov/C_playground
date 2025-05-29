#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 0;
	current = lst;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
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
	printf("%d\n", ft_lstsize(elem3));
	return (0);
}
 */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* 
#include <stdio.h>
int	main(void)
{
	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;

	elem = ft_lstnew("element1");
	elem2 = ft_lstnew("element2");
	elem3 = ft_lstnew("element3");

	ft_lstadd_front(&elem, elem2);
	while (elem)
	{
		printf("%s\n", (char *)elem->content);
		elem = elem->next;
	}
	printf("\n");
	ft_lstadd_front(&elem2, elem3);
	while (elem2)
	{
		printf("%s\n", (char *)elem2->content);
		elem2 = elem2->next;
	}
	return (0);
}
 */
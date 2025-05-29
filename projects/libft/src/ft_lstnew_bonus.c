#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

/* 
#include <stdio.h>
int	main(void)
{
	t_list	*elem;

	elem = ft_create_elem("Hello");
	printf("%s\n", (char *)elem->content);
	return (0);
}
 */
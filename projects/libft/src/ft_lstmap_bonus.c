#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		current = ft_lstnew(new_content);
		if (!current)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, current);
		lst = lst->next;
	}
	return (new_lst);
}

/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void	*to_upper(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)content;
	new_str = (char *)malloc(strlen(str) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new_str[i] = str[i] - 32;
		else
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *elem1 = ft_lstnew("element1");
	t_list *elem2 = ft_lstnew("element2");
	t_list *elem3 = ft_lstnew("element3");

	ft_lstadd_back(&elem1, elem2);
	ft_lstadd_back(&elem2, elem3);
	t_list *current = elem1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	printf("\n");
	t_list *new_lst = ft_lstmap(elem1, &to_upper, &del);
	current = new_lst;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
 */
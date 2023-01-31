#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			break ;
		i++;
	}
	if (i > ft_strlen(s))
		return (NULL);
	return ((char *)s + i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node)
	{
		if (last_node->next == NULL)
			return (last_node);
		last_node = last_node->next;
	}
	return (NULL);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (t)
	{
		t->content = content;
		t->next = NULL;
		return (t);
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

t_list	*create_list(int i)
{
	int	x;
	t_list	*head;
	t_list	*node;
	char *str = "abcdefghijklmnopqrstuvwxyz";
	x = 0;
	head = ft_lstnew(ft_strchr(str, 'a'+ x));
	x++;
	node = head;
	while (x < i)
	{
		node->next = ft_lstnew(ft_strchr(str, 'a'+ x));
		ft_lstadd_back(&head, node);
		x++;
		node = node->next;
	}
	printf("%s\n", node->content);
	return (head);
}

int main(void)
{
	t_list	*first_node;
	t_list	*node_pointer;

		create_list(4);
	//printf("%s\n", first_node->content);
	// node_pointer = first_node;

	// for (int i = 0; i < 7; i++)
	// {
	// 	printf("%s\n", node_pointer->content);
	// 	node_pointer = node_pointer->next;
	// 	i++;
	// }
	
}
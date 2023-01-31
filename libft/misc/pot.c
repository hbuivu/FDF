











#include <stdio.h>
int main (void)
{
	char dst[] = "sentence";
	char *str = ft_memmove(dst + 2, dst, 5);

	char *str1 = memmove(dst + 2, dst, 5);
	printf("%s\n", str);
	printf("%s\n", str1);
}

int main(void)
{
	char *str = "manosh";
	char *s1 = ft_strchr(str, '\0');
	char *s2 = strchr(str, '\0');

	printf("ft: %s\n", s1);
	printf("std: %s\n", s2);
}

int main(void)
{
	char d1[11];
	char d2[11];
	char *src = "happyhippo";

	printf("ft: %zu\n", ft_strlcpy(d1, src, 0));
	printf("ft: %s\n", d1);
	printf("std: %zu\n", ft_strlcpy(d2, src, 0));
	printf("std: %s\n", d2);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
	char d1[10] = "hungry";
	char d2[10] = "hungry";
	char *src = "hippo";

	printf("ft: %zu\n", ft_strlcat(d1, src, 0));
	printf("ft: %s\n", d1);
	printf("std: %zu\n", strlcat(d2, src, 0));
	printf("std: %s\n", d2);
}


 int main(void)
 {
    char str[] = "sentence";
    char *s = ft_memchr(str, 'n', 5);

    printf("%s\n", s);
 }

 int main (void)
{
    char str1[] = "sentence";
    char str2[] = "sentence";

    printf("%i\n", ft_memcmp(str1, str2, 0));
}

int main(void)
{
	char *s1 = "sentence";
	char *s2 = "ent";
	char *str = strnstr(s1, s2, 6);
	printf("%s\n", str);
}

int main(void)
{
	char *str = "the.dog...ran.over.the.hill...";
	char c = '.';
	//printf("%i\n", num_strs(str, c));
	char **buffer = ft_split(str, '.');
	int i = 0;
	while (buffer[i] != NULL)
	{
		printf("%s\n", buffer[i]);
		i++;
	}
		
}

#include <stdio.h>
#include <string.h>
int main(void)
{
	char d1[] = "";
	char d2[10] = "hungry";
	char *src = "hippo";

	// printf("ft: %zu\n", ft_strlcat((void *)0, src, 0));
	// printf("ft: %s\n", d1);

	printf("strlen: %zu\n", ft_strlen((void *)0));
	//printf("std: %zu\n", strlcat(((void *)0), src, 0));
	//printf("std: %s\n", d2);
}


int main(void)
{
	char *s1 = "\xff\xaa\xde\x12";
	char *s2 = "\xff\xaa\xde\x12MACOSAAAAA";
	size_t size = 4;
	// printf("%c\n", s2[3]);
	// printf("%c\n", s1[3]);

	printf("%i\n", ft_memcmp(s1, s2, size));
}


int main(void)
{
	char *str = "      +2";
	printf("%i\n", atoi(str));
	printf("%i\n", ft_atoi(str));
}

#include <stdio.h>
int main(void)
{
	char *str = "sentence";
	char *s1 = ft_substr(str, 3, 3);

	printf("%s\n", s1);
}

#include <stdio.h>
int main(void)
{
	char *str = "";
	char *str2 = "dog";
	char *str3 = ft_strjoin(str, str2);

	printf("%s\n", str3);
}

	// if (n == -2147483648)
	// {
	// 	nbr[1] = '2';
	// 	n = -147483648;
	// }

#include <stdio.h>
int main(void)
{
	char *src = "abcabcabzellacjkb";
	char *set = "";
	char *s = ft_strtrim(src, set);
	printf("%s\n", s);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%lu\n", SIZE_MAX);
// }

// int main(void)
// {
	// char *set = "abc";
	// printf("%i\n", is_sep('d', set));

	// char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	// char *set = " \n\t";
	// char *s2  = "Hello \t  Please\n Trim me !";
	// printf("%i\n", str_size(s1, set));
	// printf("%zu\n", ft_strlen(s2));
	// ft_strtrim(s1, set);

	// char *s1 = "  \t \t \n   \n\n\n\t";
	// printf("strlen: %zu\n", ft_strlen(s1));
	// char *set = " \n\t";
	// printf("strsize: %i\n", str_size(s1, set));
	// str_size(s1, set);

	//char *ret = ft_strtrim(s1, " \n\t");

//}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i; 
	size_t	j; 
	size_t	dst_len;

	i = 0;
	j = 0;
	if (!dstsize) 
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	if (dst_len < dstsize && dstsize > 0)
	{
		while (dst[i])
			i++;
		while (i < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	else
		dst_len = dstsize;
	return (dst_len + ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i; 
	size_t	dst_len;

	if (!dstsize) 
		return (ft_strlen(src));
	dst_len = 0
	while (dst[dst_len])
		dst_len++;
	i = 0;
	if (dst_len < dstsize && dstsize > 0)
	{
		while (i < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (dst_len > dstsize)
		dst_len = dstsize;
	return (dst_len + ft_strlen(src));
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_head;
	t_list	*new_lst;
    t_list  *node;
    t_list  *tmp;

    if(!lst)
        return (NULL);
	//create new list head	
    new_head = NULL;
	//initiate temp ptr to iterate through lst
	tmp = lst;
    while(tmp)
    {
        //malloc new node
        node = malloc(sizeof(t_list));
        //del if node doesn't malloc
        if (!node)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
        //if successful malloc, create new node
        node->content = f(tmp->content);
		node->next = NULL;
        //link node - lst_add_back
        if (new_head == NULL)
		{
			new_head = node;
			new_lst = new_head;
		}
        else
        {
            new_lst->next = node;
			new_lst = new_lst->next;
        }
		//ft_lstadd_back(&new_head, node);
        //go to the next node
        tmp = tmp->next;
    }
	new_lst->next = NULL;
    return (new_head);
}

	// if (i > 2147483647 && neg == 1)
		// 	return (-1);
		// else if (i > 2147483648 && neg == -1)
		// 	return (0);

static char	*cpystr(char const *s, char c)
{
	char	*buffer;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	buffer = malloc (sizeof(char) * i + 1);
	if (!buffer)
		return (NULL);
	// i = 0;
	// while (s[i] && s[i] != c)
	// {
	// 	buffer[i] = s[i];
	// 	i++;
	// }
	// buffer[i] = '\0';
	ft_strlcpy(buffer, s, i + 1);
	return (buffer);
}
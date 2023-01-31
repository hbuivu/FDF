/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:13:23 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 10:53:14 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_color(char *str)
{
	int		i;
	int		j;
	int		num;
	char	*base;

	i = 2;
	j = 0;
	num = 0;
	base = "0123456789ABCDEF";
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		while (base[j] != str[i])
			j++;
		num = num * 16 + j;
		i++;
		j = 0;
	}
	return (num);
}

int	count_columns(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
			&& (s[i + 1] == ' ' || s[i + 1] == '\n' || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	calculate_coordinates(t_plist **plist, t_mlist *m)
{
	int		x;
	int		y;
	t_plist	*cur;

	cur = *plist;
	while (cur)
	{
		x = 0;
		y = cur->y;
		while (x < m->max_col)
		{
			cur->arr[x].newx = roundf(m->scale * (x - y) * m->cosa + m->xshift);
			cur->arr[x].newy = roundf(m->scale * (x + y) * m->sina
					- (cur->arr[x].z * m->zscale) + m->yshift);
			x++;
		}
		cur = cur->next;
	}
}

void	free_llist(t_llist *llist)
{
	if (llist->plist)
	{
		ft_lstclear(llist->plist, free);
		free(llist->plist);
	}
	if (llist->master)
		free(llist->master);
	if (llist->mlx.mlx_ptr)
		free(llist->mlx.mlx_ptr);
	if (llist)
		free(llist);
}

void	clear_gnl(char *line, int fd, t_llist *llist)
{
	if (!line)
		return ;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free_llist(llist);
	close(fd);
	exit(-1);
}

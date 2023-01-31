/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:55:31 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 11:06:40 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	release_lines(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
	{
		free(split_line[i]);
		i++;
	}
	free(split_line[i]);
	free(split_line);
}

void	fill_zarray(char *str, t_zlist *zlist, int x)
{
	char	**split_color;

	if (ft_strchr(str, ','))
	{
		split_color = ft_split(str, ',');
		if (!split_color)
		{
			free(zlist);
			return ;
		}
		zlist[x].z = ft_atoi(split_color[0]);
		zlist[x].color = read_color(split_color[1]);
		release_lines(split_color);
	}
	else
	{
		zlist[x].z = ft_atoi(str);
		zlist[x].color = WHITE;
	}
}

t_zlist	*create_array(char *line, t_mlist *master)
{
	t_zlist	*zlist;
	char	**split_list;
	int		x;

	zlist = (t_zlist *)ft_calloc(master->max_col, sizeof(t_zlist));
	if (!zlist)
		return (NULL);
	split_list = ft_split(line, ' ');
	if (!split_list)
	{
		free(zlist);
		return (NULL);
	}
	x = -1;
	while (++x < master->max_col)
		fill_zarray(split_list[x], zlist, x);
	release_lines(split_list);
	return (zlist);
}

t_plist	*create_node(char *line, t_mlist *master, int y)
{
	t_plist	*new_node;

	new_node = (t_plist *)ft_calloc(1, sizeof(t_plist));
	if (!new_node)
		return (NULL);
	new_node->arr = create_array(line, master);
	if (!new_node->arr)
	{
		free(new_node);
		return (NULL);
	}
	new_node->y = y;
	new_node->next = NULL;
	return (new_node);
}

void	read_map(int fd, char *line, t_llist *llist)
{
	t_plist	*temp;
	int		y;

	y = 0;
	llist->plist = (t_plist **)ft_calloc(1, sizeof(t_plist *));
	if (!llist->plist)
	{
		clear_gnl(line, fd, llist);
		exit (-1);
	}
	while (line)
	{
		if (count_columns(line) != llist->master->max_col)
			break ;
		temp = create_node(line, llist->master, y);
		if (!temp)
			break ;
		ft_lstadd_front(llist->plist, temp);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	clear_gnl(line, fd, llist);
}

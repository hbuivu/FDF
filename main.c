/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:35:42 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 11:51:34 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_master(t_llist *llist, char *line, int fd)
{
	llist->master = (t_mlist *)ft_calloc(1, sizeof(t_mlist));
	if (!llist->master)
	{
		perror("master list creation unsuccessful");
		clear_gnl(line, fd, llist);
	}
	llist->master->max_col = count_columns(line);
	llist->master->angle = 0.698132;
	llist->master->cosa = cos(llist->master->angle);
	llist->master->sina = sin(llist->master->angle);
	llist->master->scale = 10;
	llist->master->zscale = 5;
	llist->master->xshift = WIDTH / 3;
	llist->master->yshift = HEIGHT / 3;
}

t_llist	*init_llist(int fd)
{
	char	*line;
	t_llist	*llist;

	llist = (t_llist *)ft_calloc(1, sizeof(t_llist));
	if (!llist)
	{
		perror("llist creation unsuccessful\n");
		close(fd);
		exit (-1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		perror("no line detected");
		free(llist);
		close(fd);
		exit (-1);
	}	
	init_master(llist, line, fd);
	read_map(fd, line, llist);
	return (llist);
}

int	main(int argv, char **argc)
{
	int		fd;
	t_llist	*llist;

	if (argv != 2)
	{
		perror("Submit: ./fdf \"filename\"");
		return (-1);
	}
	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	llist = init_llist(fd);
	close(fd);
	fdf(llist);
	return (0);
}

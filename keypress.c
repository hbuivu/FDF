/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:23:46 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 10:51:30 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(int key, t_llist *llist)
{
	if (key == 18 || key == 20 || key == 23)
	{
		llist->master->angle += 0.0872665;
		if (key == 18 || key == 20)
			llist->master->cosa = cos(llist->master->angle);
		if (key == 18 || key == 23)
			llist->master->sina = sin(llist->master->angle);
	}
	else if (key == 19 || key == 21 || key == 22)
	{
		llist->master->angle -= 0.0872665;
		if (key == 19 || key == 21)
			llist->master->cosa = cos(llist->master->angle);
		if (key == 19 || key == 22)
			llist->master->sina = sin(llist->master->angle);
	}
}

void	resize(int key, t_llist *llist)
{
	if (key == 24)
		llist->master->scale += 2;
	else if (key == 27)
		llist->master->scale -= 2;
	else if (key == 6)
		llist->master->zscale += 1;
	else if (key == 7)
		llist->master->zscale -= 1;
}

void	shift(int key, t_llist *llist)
{
	if (key == 125)
		llist->master->yshift += 5;
	else if (key == 126)
		llist->master->yshift -= 5;
	else if (key == 124)
		llist->master->xshift += 5;
	else if (key == 123)
		llist->master->xshift -= 5;
}

void	revert_original(t_llist *llist)
{
	llist->master->angle = 0.698132;
	llist->master->cosa = cos(llist->master->angle);
	llist->master->sina = sin(llist->master->angle);
	llist->master->scale = 10;
	llist->master->zscale = 5;
}

int	key_press(int key, t_llist *llist)
{
	if (key == 53)
	{
		mlx_destroy_window(llist->mlx.mlx_ptr, llist->mlx.mlx_win);
		free_llist(llist);
		exit (0);
	}
	if (key == 24 || key == 27 || key == 6 || key == 7)
		resize(key, llist);
	else if (key == 125 || key == 126 || key == 124 || key == 123)
		shift(key, llist);
	else if (key >= 18 && key <= 23)
		rotate(key, llist);
	else if (key == 34)
		revert_original(llist);
	else
		return (0);
	mlx_clear_window(llist->mlx.mlx_ptr, llist->mlx.mlx_win);
	mlx_destroy_image(llist->mlx.mlx_ptr, llist->img.img);
	put_img(llist);
	return (0);
}

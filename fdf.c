/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:36:49 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 10:51:02 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_llist *llist)
{
	mlx_destroy_window(llist->mlx.mlx_ptr, llist->mlx.mlx_win);
	free_llist(llist);
	exit (0);
}

int	esc_press(int key, t_llist *llist)
{
	if (key == 53)
	{
		mlx_destroy_window(llist->mlx.mlx_ptr, llist->mlx.mlx_win);
		free_llist(llist);
		exit (0);
	}
	return (0);
}

void	init_window(t_llist *llist)
{
	llist->mlx.mlx_ptr = mlx_init();
	if (llist->mlx.mlx_ptr == NULL)
	{
		perror("mlx_ptr creation unsuccessful");
		free_llist(llist);
		exit (-1);
	}
	llist->mlx.mlx_win = mlx_new_window(llist->mlx.mlx_ptr, WIDTH, HEIGHT,
			"FDF");
	if (llist->mlx.mlx_win == NULL)
	{
		perror("mlx_win creation unsucessful");
		free_llist(llist);
		exit(-1);
	}
}

void	put_img(t_llist *llist)
{
	llist->img.img = mlx_new_image(llist->mlx.mlx_ptr, WIDTH, HEIGHT);
	llist->img.addr = mlx_get_data_addr(llist->img.img, &llist->img.bpp,
			&llist->img.line_length, &llist->img.endian);
	calculate_coordinates(llist->plist, llist->master);
	draw_img(&llist->img, llist->plist, llist->master);
	mlx_put_image_to_window(llist->mlx.mlx_ptr, llist->mlx.mlx_win,
		llist->img.img, 0, 0);
}

void	fdf(t_llist *llist)
{
	init_window(llist);
	put_img(llist);
	mlx_hook(llist->mlx.mlx_win, 17, 0, close_win, &llist->mlx);
	mlx_hook(llist->mlx.mlx_win, 2, 0, esc_press, &llist->mlx);
	mlx_loop(llist->mlx.mlx_ptr);
	mlx_destroy_window(llist->mlx.mlx_ptr, llist->mlx.mlx_win);
	free(llist->mlx.mlx_ptr);
	free_llist(llist);
}

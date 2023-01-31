/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfbonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:36:49 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 10:51:16 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_llist *llist)
{
	mlx_destroy_window(llist->mlx.mlx_ptr, llist->mlx.mlx_win);
	free_llist(llist);
	exit (0);
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

int	put_legend(t_llist *llist)
{
	void	*p;
	void	*w;

	p = llist->mlx.mlx_ptr;
	w = llist->mlx.mlx_win;
	mlx_string_put(p, w, 5, 5, WHITE, "Up/Down = Arrow Up/Down");
	mlx_string_put(p, w, 5, 35, WHITE, "Right/Left = Arrow Right/Left");
	mlx_string_put(p, w, 5, 65, WHITE, "Zoom In/Out = -/+");
	mlx_string_put(p, w, 5, 95, WHITE, "Z Up/Down = z/x");
	mlx_string_put(p, w, 5, 125, WHITE, "Diagonal Rotate = 1/2");
	mlx_string_put(p, w, 5, 155, WHITE, "X Rotate = 3/4");
	mlx_string_put(p, w, 5, 185, WHITE, "Y Rotate = 5/6");
	mlx_string_put(p, w, 5, 215, WHITE, "Isometric View = i");
	return (0);
}

void	fdf(t_llist *llist)
{
	init_window(llist);
	put_img(llist);
	mlx_hook(llist->mlx.mlx_win, 17, 0, close_win, &llist->mlx);
	mlx_hook(llist->mlx.mlx_win, 2, 0, key_press, &llist->mlx);
	mlx_loop_hook(llist->mlx.mlx_ptr, &put_legend, &llist->mlx);
	mlx_loop(llist->mlx.mlx_ptr);
	mlx_destroy_window(llist->mlx.mlx_ptr, llist->mlx.mlx_win);
	free(llist->mlx.mlx_ptr);
	free_llist(llist);
}

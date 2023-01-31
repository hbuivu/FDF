/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:45:19 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 10:49:58 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bpp / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

float	ft_max(float i, float j)
{
	if (i < 0)
		i *= -1;
	if (j < 0)
		j *= -1;
	if (i < j)
		return (j);
	return (i);
}

void	draw_line(t_data *data, t_zlist p1, t_zlist p2, int color)
{
	float	dx;
	float	dy;
	float	delta;

	dx = p2.newx - p1.newx;
	dy = p2.newy - p1.newy;
	delta = ft_max(dx, dy);
	if (dx == 0)
		dy = 1;
	else if (dy == 0)
		dx = 1;
	else
	{
		dx = dx / delta;
		dy = dy / delta;
	}
	while (delta > 0)
	{
		if (p1.newx >= 0 && p1.newx < WIDTH && p1.newy >= 0 && p1.newy < HEIGHT)
			ft_pixel_put(data, p1.newx, p1.newy, color);
		p1.newx += dx;
		p1.newy += dy;
		delta--;
	}	
	return ;
}

void	draw_img(t_data *data, t_plist **plist, t_mlist *master)
{
	int		i;
	t_plist	*p;

	i = 0;
	p = *plist;
	while (p)
	{
		while (i < master->max_col)
		{
			if (p->y == 0 && i == master->max_col - 1)
				return ;
			else if (p->y == 0)
				draw_line(data, p->arr[i], p->arr[i + 1], p->arr[i].color);
			else
			{
				draw_line(data, p->arr[i], p->next->arr[i], p->arr[i].color);
				if (i != master->max_col - 1)
					draw_line(data, p->arr[i], p->arr[i + 1], p->arr[i].color);
			}
			i++;
		}
		i = 0;
		p = p->next;
	}
}

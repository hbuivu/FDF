/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:42:15 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 10:53:46 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct t_zlist
{
	int		z;
	int		color;
	float	newx;
	float	newy;
}	t_zlist;

typedef struct points_list
{
	int					y;
	t_zlist				*arr;
	struct points_list	*next;
}	t_plist;

typedef struct master_list
{
	int		max_col;
	int		max_row;
	float	angle;
	float	cosa;
	float	sina;
	int		scale;
	int		zscale;
	int		xshift;
	int		yshift;
}	t_mlist;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_vars;

typedef struct list_list
{
	t_vars	mlx;
	t_data	img;
	t_mlist	*master;
	t_plist	**plist;
}	t_llist;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:40:43 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/31 10:54:54 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WHITE	0xFFFFFF
# define RED	0xFF0000

# define HEIGHT	1080
# define WIDTH	1920

int		read_color(char *str);
int		count_columns(char *s);
void	read_map(int fd, char *line, t_llist *llist);
void	draw_img(t_data *data, t_plist **plist, t_mlist *master);
void	calculate_coordinates(t_plist **plist, t_mlist *m);
void	free_llist(t_llist *llist);
void	clear_gnl(char *line, int fd, t_llist *llist);
void	fdf(t_llist *llist);
void	put_img(t_llist *llist);
int		key_press(int key, t_llist *llist);

#endif
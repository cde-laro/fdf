/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:34:29 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/03 16:35:50 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_draw_diagonal(t_env *e, int x, int y)
{
	t_point		a;
	t_point		b;

	if (e->s->diag == 0)
		return ;
	a.x = fdf_conv_x(x, y, e->map->data[y][x], e);
	a.y = fdf_conv_y(x, y, e->map->data[y][x], e);
	if (x + 1 < e->map->maxx && y + 1 < e->map->maxy)
	{
		b.x = fdf_conv_x(x + 1, y + 1, e->map->data[y + 1][x + 1], e);
		b.y = fdf_conv_y(x + 1, y + 1, e->map->data[y + 1][x + 1], e);
		if (e->map->data[y][x] > e->map->data[y + 1][x + 1])
			check_line(e, a, b, e->map->data[y][x]);
		else
			check_line(e, a, b, e->map->data[y + 1][x + 1]);
	}
	if (x - 1 >= 0 && y + 1 < e->map->maxy)
	{
		b.x = fdf_conv_x(x - 1, y + 1, e->map->data[y + 1][x - 1], e);
		b.y = fdf_conv_y(x - 1, y + 1, e->map->data[y + 1][x - 1], e);
		if (e->map->data[y][x] > e->map->data[y + 1][x - 1])
			check_line(e, a, b, e->map->data[y][x]);
		else
			check_line(e, a, b, e->map->data[y + 1][x - 1]);
	}
}

void		fdf_draw_next(t_env *e, int x, int y)
{
	t_point		a;
	t_point		b;

	a.x = fdf_conv_x(x, y, e->map->data[y][x], e);
	a.y = fdf_conv_y(x, y, e->map->data[y][x], e);
	if (x + 1 < e->map->maxx)
	{
		b.x = fdf_conv_x(x + 1, y, e->map->data[y][x + 1], e);
		b.y = fdf_conv_y(x + 1, y, e->map->data[y][x + 1], e);
		if (e->map->data[y][x] > e->map->data[y][x + 1])
			check_line(e, a, b, e->map->data[y][x]);
		else
			check_line(e, a, b, e->map->data[y][x + 1]);
	}
	if (y + 1 < e->map->maxy)
	{
		b.x = fdf_conv_x(x, y + 1, e->map->data[y + 1][x], e);
		b.y = fdf_conv_y(x, y + 1, e->map->data[y + 1][x], e);
		if (e->map->data[y][x] > e->map->data[y + 1][x])
			check_line(e, a, b, e->map->data[y][x]);
		else
			check_line(e, a, b, e->map->data[y + 1][x]);
	}
	fdf_draw_diagonal(e, x, y);
}

void		fdf_draw_grid(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	fdf_init_img(e);
	while (y < e->map->maxy)
	{
		x = 0;
		while (x < e->map->maxx)
		{
			fdf_draw_next(e, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr_img, 0, 0);
	display(e);
	mlx_destroy_image(e->mlx, e->img->ptr_img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:41:09 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/18 14:17:04 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_line(t_env *e, t_point a, t_point b, int z)
{
	if ((a.x < 0 && b.x < 0) || (a.y < 0 && b.y < 0))
		return ;
	if ((a.x > WIN_Y && b.x > WIN_Y) || (a.y > WIN_X && b.y > WIN_X))
		return ;
	if (z <= e->s->void_lvl && e->s->void_enabled)
		return ;
	draw_line(e, a, b, get_color(e, z));
	pix_put_img(e, a.y, a.x, get_color(e, z));
	pix_put_img(e, b.y, b.x, get_color(e, z));
}

void	draw_line(t_env *e, t_point a, t_point b, int z)
{
	t_point		d;
	t_point		s;
	int			e1;
	int			e2;

	d.x = ABS(b.x - a.x);
	d.y = ABS(b.y - a.y);
	s.x = (a.x < b.x ? 1 : -1);
	s.y = (a.y < b.y ? 1 : -1);
	e1 = (d.x > d.y ? d.x : -d.y) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		pix_put_img(e, a.y, a.x, z);
		e2 = e1;
		if (e2 > -d.x)
		{
			e1 -= d.y;
			a.x += s.x;
		}
		if (e2 < d.y)
		{
			e1 += d.x;
			a.y += s.y;
		}
	}
}

void	pix_put_img(t_env *e, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < WIN_Y && x < WIN_X)
	{
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x) + 2] = r;
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x) + 1] = g;
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x)] = b;
	}
}

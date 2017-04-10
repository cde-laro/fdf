/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:00:49 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/18 16:03:00 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_conv_x(int x, int y, int z, t_env *e)
{
	int		h;
	int		a;
	int		bx;
	double	dest;
	int		k;

	k = (e->map->maxz > 5 ? -(e->map->maxz / 5) : 1);
	x -= (e->map->maxx / 2);
	y -= (e->map->maxy / 2);
	a = (2 * e->s->size + 1);
	h = e->s->h;
	bx = e->s->size + e->s->y;
	dest = y * cos(e->s->ay) * cos(e->s->az);
	dest = dest + x * -sin(e->s->az) * cos(e->s->ay);
	dest = (dest + ((h * z) / k) * sin(e->s->ay)) * a + bx;
	return ((int)dest);
}

int		fdf_conv_y(int x, int y, int z, t_env *e)
{
	int		h;
	int		a;
	int		by;
	double	dest;
	int		k;

	k = (e->map->maxz > 5 ? -(e->map->maxz / 5) : 1);
	x -= (e->map->maxx / 2);
	y -= (e->map->maxy / 2);
	h = e->s->h;
	by = e->s->size + e->s->x;
	a = -sin(e->s->ax) * -sin(e->s->ay);
	dest = y * (cos(e->s->az) * a + sin(e->s->az) * cos(e->s->ax));
	dest = dest + x * (-sin(e->s->az) * a + cos(e->s->az) * cos(e->s->ax));
	a = (2 * e->s->size + 1);
	dest = (dest + ((h * z) / k) * -sin(e->s->ax) * cos(e->s->ay)) * a + by;
	return ((int)dest);
}

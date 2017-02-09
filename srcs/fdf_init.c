/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:38:55 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/09 21:15:37 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_init_img(t_env *e)
{
	e->img->ptr_img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->img->bts = mlx_get_data_addr(e->img->ptr_img, &(e->img->bpp),
			&(e->img->size_line), &(e->img->end));
}

void		fdf_init_settings(t_env *e)
{
	e->s->size = 5;
	e->s->ax = 0;
	e->s->ay = 0.5;
	e->s->az = 0;
	e->s->h = 1;
	e->s->sx = 0;
	e->s->sy = 0;
	e->s->x = 50;
	e->s->y = 50;
	e->s->water_enabled = 0;
	e->s->water_lvl = 0;
	e->s->void_enabled = 0;
	e->s->void_lvl = -1;
	e->s->display = 0;
	e->s->color_preset = 0;
	e->s->mode = 0;

}

void		fdf_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, e->name);
	e->drawed = 0;
	e->s = (t_setting *)malloc(sizeof(t_setting));
	e->img = (t_img *)malloc(sizeof(t_img));
	fdf_init_settings(e);
	fdf_init_img(e);
}

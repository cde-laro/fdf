/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:38:55 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 21:16:37 by cde-laro         ###   ########.fr       */
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
	e->s->ay = 0;
	e->s->az = 0;
	e->s->h = 10;
	e->s->x = WIN_X / 2;
	e->s->y = WIN_Y / 2;
	e->s->water_enabled = 0;
	e->s->water_lvl = 0;
	e->s->void_enabled = 0;
	e->s->void_lvl = -1;
	e->s->display = 0;
	e->s->color = 0;
	e->s->mode = KEY_S;
	e->s->diag = 0;
}

int			red_cross(int key, t_env *e)
{
	(void)key;
	(void)*e;
	exit(0);
	return (0);
}

void		fdf_error(int code)
{
	ft_putstr("An error has occured: ");
	ft_putnbr(code);
	ft_putstr(" Leaving program...");
	exit(-1);
}

void		fdf_init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		fdf_error(1);
	if (!(e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fractol")))
		fdf_error(2);
	e->drawed = 0;
	if (!(e->s = (t_setting *)malloc(sizeof(t_setting))))
		fdf_error(3);
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		fdf_error(4);
	fdf_init_settings(e);
	fdf_init_img(e);
	mlx_hook(e->win, 17, (1L << 17), red_cross, e);
	mlx_hook(e->win, 2, 3, fdf_key_funct, e);
}

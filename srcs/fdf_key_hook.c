/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:00:17 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/18 14:18:21 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_key_add_sub(t_env *e, int k)
{
	if (e->s->mode == KEY_S)
	{
		if (k == KEY_PAD_ADD)
			e->s->size++;
		else if (e->s->size != 0)
			e->s->size--;
	}
	else if (e->s->mode == KEY_X)
		e->s->ax += (k == KEY_PAD_ADD ? PI / 36 : -(PI / 36));
	else if (e->s->mode == KEY_Y)
		e->s->ay += (k == KEY_PAD_ADD ? PI / 36 : -(PI / 36));
	else if (e->s->mode == KEY_Z)
		e->s->az += (k == KEY_PAD_ADD ? PI / 36 : -(PI / 36));
	else if (e->s->mode == KEY_H)
		e->s->h = e->s->h + (k == KEY_PAD_ADD ? 1 : -1);
	else if (e->s->mode == KEY_W)
		e->s->water_lvl = e->s->water_lvl + (k == KEY_PAD_ADD ? 1 : -1);
	else if (e->s->mode == KEY_V && e->s->void_enabled)
		e->s->void_lvl = e->s->void_lvl + (k == KEY_PAD_ADD ? 1 : -1);
	else
		return ;
}

void	fdf_key_move(t_env *e, int k)
{
	if (k == KEY_UP)
		e->s->y -= 10;
	else if (k == KEY_DOWN)
		e->s->y += 10;
	else if (k == KEY_LEFT)
		e->s->x -= 10;
	else if (k == KEY_RIGHT)
		e->s->x += 10;
	else
		return ;
}

void	fdf_key_enter(t_env *e)
{
	if (e->s->mode == KEY_W)
		e->s->water_enabled = (e->s->water_enabled ? 0 : 1);
	else if (e->s->mode == KEY_V)
		e->s->void_enabled = (e->s->void_enabled ? 0 : 1);
	else
		return ;
}

int		fdf_key_funct(int k, t_env *e)
{
	if (k == KEY_S || k == KEY_X || k == KEY_Y || k == KEY_Z || k == KEY_H ||
			k == KEY_W || k == KEY_V)
		e->s->mode = k;
	else if (k == KEY_PAD_ADD || k == KEY_PAD_SUB)
		fdf_key_add_sub(e, k);
	else if (k == KEY_UP || k == KEY_DOWN || k == KEY_LEFT || k == KEY_RIGHT)
		fdf_key_move(e, k);
	else if (k == KEY_ENTER)
		fdf_key_enter(e);
	else if (k == KEY_C)
		fdf_color_change(e);
	else if (k == KEY_D)
		e->s->display = (e->s->display == 0 ? 1 : 0);
	else if (k == KEY_SPACEBAR)
		fdf_init_settings(e);
	else if (k == KEY_PAD_DIVIDE)
		e->s->diag = (e->s->diag == 0 ? 1 : 0);
	else if (k == KEY_ESCAPE)
		exit(0);
	else
		return (0);
	fdf_draw_grid(e);
	return (0);
}

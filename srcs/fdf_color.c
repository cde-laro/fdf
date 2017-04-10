/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:19:09 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/18 12:39:38 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_color_change(t_env *e)
{
	if (e->s->color == 8)
		e->s->color = 0;
	else
		e->s->color++;
	fdf_draw_grid(e);
}

void		fdf_print_color_name(t_env *e)
{
	ft_putstr("Color mode: ");
	if (e->s->color == 0)
		ft_putendl("Map");
	else if (e->s->color == 1)
		ft_putendl("Thermal");
	else if (e->s->color == 2)
		ft_putendl("RAINBOW :D");
	else if (e->s->color == 3)
		ft_putendl("Green");
	else if (e->s->color == 4)
		ft_putendl("White");
	else if (e->s->color == 5)
		ft_putendl("Red");
	else if (e->s->color == 6)
		ft_putendl("Orange");
	else if (e->s->color == 7)
		ft_putendl("Purple");
	else if (e->s->color == 8)
		ft_putendl("Blue");
}

int			get_color(t_env *e, int z)
{
	if (e->s->color == 0)
		return (fdf_map_color(e, z));
	else if (e->s->color == 1)
		return (fdf_thermal_color(e, z));
	else if (e->s->color == 2)
		return (fdf_rainbow_color(e, z));
	else if (e->s->color == 3)
		return (GREEN_1);
	else if (e->s->color == 4)
		return (WHITE);
	else if (e->s->color == 5)
		return (RED_1);
	else if (e->s->color == 6)
		return (ORANGE_1);
	else if (e->s->color == 7)
		return (PURPLE);
	else
		return (BLUE_1);
}

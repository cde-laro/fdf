/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_pack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:42:17 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/18 14:23:23 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_map_color(t_env *e, int z)
{
	if (z <= e->s->water_lvl)
		return (BLUE_2);
	else if (z < e->map->maxz / 4)
		return (GREEN_2);
	else if (z < e->map->maxz / 2)
		return (ORANGE_2);
	else if (z < 3 * (e->map->maxz / 4))
		return (BROWN);
	else
		return (WHITE);
}

int		fdf_thermal_color(t_env *e, int z)
{
	int		diff;
	int		diff_max;

	diff_max = ABS(e->map->minz - e->map->maxx) / 7;
	diff = z + ABS(e->map->minz);
	if (z <= diff_max / 7)
		return (BLACK);
	else if (z <= 2 * diff_max)
		return (BLUE_2);
	else if (z <= 3 * diff_max)
		return (PURPLE);
	else if (z <= 4 * diff_max)
		return (RED_1);
	else if (z <= 5 * diff_max)
		return (ORANGE_2);
	else if (z <= 6 * diff_max)
		return (YELLOW);
	else
		return (WHITE);
}

int		fdf_rainbow_color(t_env *e, int z)
{
	int		diff;
	int		diff_max;

	diff_max = ABS(e->map->minz - e->map->maxz) / 8;
	diff = z + ABS(e->map->minz);
	if (z <= diff_max)
		return (RED_1);
	else if (z <= 2 * diff_max)
		return (ORANGE_2);
	else if (z <= 3 * diff_max)
		return (YELLOW);
	else if (z <= 4 * diff_max)
		return (GREEN_2);
	else if (z <= 5 * diff_max)
		return (CYAN);
	else if (z <= 6 * diff_max)
		return (PINK);
	else if (z <= 7 * diff_max)
		return (PURPLE);
	else
		return (RED_1);
}

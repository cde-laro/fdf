/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:19:36 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/09 21:03:57 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env		*e;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf map.fdf");
		return (-1);
	}
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	e->name = av[1];
	e->map = fdf_parse(av[1]);
	ft_putendl("Parsed");
	fdf_init(e);
	ft_putendl("init");
	fdf_draw_grid(e);
	ft_putendl("drawed");
	mlx_loop(e->mlx);
	return (0);
}

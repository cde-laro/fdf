/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:19:36 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/24 15:04:18 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_char(char *str, char *filename)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[i] == '\n' || str[i] == '\t' ||
			str[i] == ' ' || str[i] == '-')))
		{
			system("clear");
			ft_putstr("There is a \"");
			ft_putchar(str[i]);
			ft_putstr("\" on char: ");
			ft_putnbr(i);
			ft_putstr(" of ");
			ft_putstr(filename);
			ft_putendl("\nPlease check your file");
			return (-1);
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env		e;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf map.fdf");
		return (-1);
	}
	e.name = av[1];
	ft_putendl("Extraction ...");
	if (!(e.map = fdf_parse(av[1])))
		return (-1);
	fdf_init(&e);
	ft_putendl("Drawing ...");
	find_minmaxz(&e);
	fdf_draw_grid(&e);
	mlx_loop(e.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_text_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:40:36 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/23 14:43:06 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_print_current_mode(t_env *e)
{
	ft_putstr("Current Mode: ");
	if (e->s->mode == KEY_S)
		ft_putendl("Zoom");
	else if (e->s->mode == KEY_X)
		ft_putendl("Angle X");
	else if (e->s->mode == KEY_Y)
		ft_putendl("Angle Y");
	else if (e->s->mode == KEY_Z)
		ft_putendl("Angle Z");
	else if (e->s->mode == KEY_H)
		ft_putendl("Height");
	else if (e->s->mode == KEY_W)
		ft_putendl("Water");
	else if (e->s->mode == KEY_V)
		ft_putendl("Void");
}

void	fdf_print_user_guide(t_env *e)
{
	ft_putendl("Press S to select Zoom and +/- to Zoom in/out");
	ft_putendl("Press X/Y/Z to select the desired angle and +/- to rotate");
	ft_putendl("Press H to change the heigth with +/-");
	ft_putstr("Press W/V then Enter to toggle water/void, or use +/- to chang");
	ft_putendl("e the level of water/void");
	ft_putendl("Press C to switch color");
	ft_putendl("Press / to enable/disable diagnonals");
	ft_putendl("Press D to switch between the User guide and the setting");
	ft_putendl("Press Space to reset settings");
	ft_putendl("Press Escape or click on the red cross to leave the program");
	fdf_print_current_mode(e);
}

void	fdf_text_display(t_env *e)
{
	ft_putstr("Zoom:");
	ft_putnbr(e->s->size);
	ft_putstr("\nAngle X: ");
	ft_putnbr(ABS((int)(180 * e->s->ax / PI) % 360));
	ft_putstr("\nAngle Y: ");
	ft_putnbr(ABS((int)(180 * e->s->ay / PI) % 360));
	ft_putstr("\nAngle Z: ");
	ft_putnbr(ABS((int)(180 * e->s->az / PI) % 360));
	ft_putstr("\nHeight: ");
	ft_putnbr(e->s->h);
	ft_putstr("\nStart: [");
	ft_putnbr(e->s->x);
	ft_putstr("][");
	ft_putnbr(e->s->y);
	ft_putstr("]\nLevel of Water: ");
	ft_putnbr(e->s->water_lvl);
	ft_putendl((e->s->void_enabled ? "\nVoid enabled" : "\nVoid disabled"));
	ft_putstr("Level of Void: ");
	ft_putnbr(e->s->void_lvl);
	ft_putchar('\n');
	ft_putendl((e->s->diag ? "Diagonals enabled" : "Diagonals disabled"));
	fdf_print_current_mode(e);
	fdf_print_color_name(e);
}

void	display(t_env *e)
{
	system("clear");
	if (e->s->display == 0)
		fdf_print_user_guide(e);
	else
		fdf_text_display(e);
}

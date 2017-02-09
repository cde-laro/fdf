/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:29:20 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/09 20:55:34 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdlib.h>
# include "libft.h"
# include <math.h>
# include "keys.h"
# include <limits.h>
# include "color.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>


# define WIN_X 2560
# define WIN_Y 1440
# define BUFF_SIZE 424242
# define PI 3.141592653

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_map
{
	int			**data;
	int			maxX;
	int			maxY;
	int			minZ;
	int			maxZ;
}				t_map;

typedef struct	s_img
{
	void		*ptr_img;
	char		*bts;
	int			size_line;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_setting
{
	int			size;
	double		ax;
	double		ay;
	double		az;
	double		h;
	int			sx;
	int			sy;
	int			x;
	int			y;
	int			water_enabled;
	int			water_lvl;
	int			void_enabled;
	int			void_lvl;
	int			display;
	int			color_preset;
	int			mode;
}				t_setting;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		*data;
	int			drawed;
	t_setting	*s;
	t_map		*map;
	char		*name;
}				t_env;

void			pix_put_img(t_env *e, int height, int width, int color);
int				fdf_conv_x(int x, int y, int z, t_env *e);
int				fdf_conv_y(int x, int y, int z, t_env *e);
void			draw_line_win(t_env *e, t_point a, t_point b, int color);
void			fdf_img_creation(t_env *e);
void			print_fdf(t_env *e, t_map *map);
char			*fdf_extract(int fd);
int				ft_key_funct(int keycode, t_env *e);
int				red_cross(int key, t_env *e);
char			*ft_strjoin_free(char *s1, char *s2);
t_map			*fdf_parse(char *str);
t_env			*fdf_initialisation(t_env *e, char *win_name);
void			fdf_print_user_guide(t_env *e);
void			fdf_key_add(t_env *e);
void			fdf_key_sub(t_env *e);
void			fdf_key_move(t_env *e, int key);
void			fdf_key_enter(t_env *e);
int				fdf_key_funct_2(int k, t_env *e);
void			reset_settings(t_env *e);
void			print_params(t_env *e);
void			switch_display(t_env *e);
void			display(t_env *e);
int				color_selection(t_env *e, int z);
void			print_raw_params(t_env *e);
void			print_color_name(t_env *e);

void		find_minmaxz(t_map *map);
char		*ft_strjoin_free(char *s1, char *s2);
char		*fdf_extract(int fd);
t_map		*fdf_parse(char *path);
void		fdf_init_settings(t_env *e);
void		fdf_init(t_env *e);
void		fdf_init_img(t_env *e);
void		draw_line(t_env *e, t_point a, t_point b, int z);
void		fdf_draw_grid(t_env *e);

#endif

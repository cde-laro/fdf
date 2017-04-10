/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:29:20 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/18 14:21:00 by cde-laro         ###   ########.fr       */
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

# define WIN_X 1920
# define WIN_Y 1070
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
	int			maxx;
	int			maxy;
	int			minz;
	int			maxz;
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
	int			x;
	int			y;
	int			water_enabled;
	int			water_lvl;
	int			void_enabled;
	int			void_lvl;
	int			display;
	int			diag;
	int			color;
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
int				fdf_key_funct(int keycode, t_env *e);
void			find_minmaxz(t_env *e);
char			*ft_strjoin_free(char *s1, char *s2);
char			*fdf_extract(int fd, char *filename);
t_map			*fdf_parse(char *path);
void			fdf_init_settings(t_env *e);
void			fdf_init(t_env *e);
void			fdf_init_img(t_env *e);
void			draw_line(t_env *e, t_point a, t_point b, int z);
void			fdf_draw_grid(t_env *e);
void			fdf_color_change(t_env *e);
int				fdf_map_color(t_env *e, int z);
int				fdf_thermal_color(t_env *e, int z);
int				fdf_rainbow_color(t_env *e, int z);
int				get_color(t_env *e, int z);
void			check_line(t_env *e, t_point a, t_point b, int z);
int				check_char(char *str, char *filename);
void			fdf_print_color_name(t_env *e);
void			display(t_env *e);

#endif

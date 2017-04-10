/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:26:26 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/23 14:49:29 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*dest;

	n = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[n])
	{
		dest[n] = s1[n];
		n++;
	}
	i = 0;
	while (s2[i])
	{
		dest[n] = s2[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	free(s1);
	return (dest);
}

char		*fdf_extract(int fd, char *filename)
{
	int			i;
	int			ret;
	char		buf[BUFF_SIZE];
	char		*filecontent;

	i = 0;
	filecontent = ft_strdup("");
	while (0 < (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		filecontent = ft_strjoin_free(filecontent, buf);
	}
	if (-1 == check_char(filecontent, filename) || !ft_strlen(filecontent))
		return (NULL);
	return (filecontent);
}

void		find_minmaxz(t_env *e)
{
	int		i;
	int		j;

	e->map->maxz = INT_MIN;
	e->map->minz = INT_MAX;
	i = 0;
	while (i < e->map->maxy)
	{
		j = 0;
		while (j < e->map->maxx)
		{
			if (e->map->maxz < e->map->data[i][j])
				e->map->maxz = e->map->data[i][j];
			if (e->map->minz > e->map->data[i][j])
				e->map->minz = e->map->data[i][j];
			j++;
		}
		i++;
	}
}

int			check_line_len(char **tab, int maxy)
{
	int		i;
	int		dest;

	i = 1;
	dest = ft_countelem(tab[0], ' ');
	while (i < maxy)
	{
		if (ft_countelem(tab[i], ' ') != dest)
		{
			system("clear");
			ft_putstr("Line ");
			ft_putnbr(i);
			ft_putendl(" don't have the same lenght than other lines");
			ft_putendl("Check your map");
			return (-1);
		}
		i++;
	}
	return (dest);
}

t_map		*fdf_parse(char *path)
{
	t_map		*map;
	char		*filecontent;
	char		**tab;
	int			fd;

	if (!(map = (t_map *)malloc(sizeof(map))))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (!(filecontent = fdf_extract(fd, path)))
		return (NULL);
	map->maxy = ft_countchar(filecontent, '\n');
	close(fd);
	tab = ft_strsplit(filecontent, '\n');
	if ((map->maxx = check_line_len(tab, map->maxy)) == -1)
		return (NULL);
	map->data = (int **)malloc(sizeof(int *) * map->maxy + 1);
	fd = -1;
	while (++fd < map->maxy)
	{
		map->data[fd] = ft_strsplit_to_int(tab[fd], ' ');
		free(tab[fd]);
	}
	free(filecontent);
	free(tab);
	return (map);
}

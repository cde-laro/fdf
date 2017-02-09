/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:26:26 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/09 18:09:13 by cde-laro         ###   ########.fr       */
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

char		*fdf_extract(int fd)
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
	return (filecontent);
}

void		find_minmaxz(t_map *map)
{
	int		i;
	int		j;

	map->maxZ = INT_MIN;
	map->minZ = INT_MAX;
	i = 0;
	while (i < map->maxY)
	{
		j = 0;
		while (j < map->maxX)
		{
			if (map->maxZ < map->data[i][j])
				map->maxZ = map->data[i][j];
			if (map->minZ > map->data[i][j])
				map->minZ = map->data[i][j];
			j++;
		}
		i++;
	}
}

t_map		*fdf_parse(char *path)
{
	t_map		*map;
	char		*filecontent;
	char		**tab;
	int			fd;
	int			n;

	n = 0;
	if (!(map = (t_map *)malloc(sizeof(map))))
		return (NULL);
	fd = open(path, O_RDONLY);
	filecontent = fdf_extract(fd);
	map->maxY = ft_countchar(filecontent, '\n');
	close(fd);
	tab = ft_strsplit(filecontent, '\n');
	map->maxX = ft_countelem(tab[0], ' ');
	map->data = (int **)malloc(sizeof(int *) * map->maxY + 1);
	while (n < map->maxY)
	{
		map->data[n] = ft_strsplit_to_int(tab[n], ' ');
		free(tab[n]);
		n++;
	}
	find_minmaxz(map);
	free(tab);
	return (map);
}

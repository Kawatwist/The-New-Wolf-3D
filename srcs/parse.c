/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:21:03 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 11:51:28 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	map_malloc(t_acz *az, t_map *map)
{
	int		i;

	(map->map = (int **)malloc(sizeof(int *) * az->info->y)) == NULL ?
		stop_exec("Erreur parse\n", az) : 0;
	i = -1;
	while (++i < az->info->y)
		(map->map[i] = (int *)malloc(sizeof(int) * az->info->x)) == NULL ?
			stop_exec("Erreur parse\n", az) : 0;
}

void		map_parse(t_acz **az, char *name)
{
	int		i;
	int		fd;
	char	*line;

	if (!(fd = open(name, O_RDONLY)) || read(fd, 0, 0) < 0)
		stop_exec("Open failed\n", *az);
	get_next_line(fd, &line);
	i = 0;
	while (line[++i] != '\0')
		(line[i] == ' ') ? (*az)->info->x += 1 : 0;
	free(line);
	while (get_next_line(fd, &line))
	{
		(*az)->info->y += 1;
		free(line);
	}
	if ((*az)->info->y != 60 || (*az)->info->x < 60 || (*az)->info->x > 61)
		stop_exec("Map invalid\n", *az);
	close(fd);
	if (!(fd = open(name, O_RDONLY)) || read(fd, 0, 0) < 0)
		stop_exec("Open failed\n", *az);
	map_malloc((*az), (*az)->map);
	map_stock((*az), (*az)->map, fd);
}

static void	fillselect(t_acz *az, int sizex, int sizey)
{
	int x;
	int y;

	y = -1;
	while (++y < sizey && y < 60)
	{
		x = -1;
		while (++x < sizex && x < 60)
			az->info->selmap[y][x] =
				az->info->editmap[y + az->info->selecty][x + az->info->selectx];
	}
}

static void	freesel(t_acz *az)
{
	int i;

	i = -1;
	while (++i < az->info->selsizey && az->info->selmap[i] != NULL)
		az->info->selmap[i] != NULL ? free(az->info->selmap[i]) : 0;
	az->info->selmap != NULL ? free(az->info->selmap) : 0;
}

void		parseselect(t_acz *az)
{
	int i;
	int j;
	int tmp;

	tmp = 0;
	i = (ft_abs(az->info->selectx - (az->info->editx / 10)));
	j = (ft_abs(az->info->selecty - (az->info->edity / 10)));
	az->info->selsizex = i;
	az->info->selsizey = j;
	if (i == 0 && j == 0)
		return ;
	if (az->info->selmap != NULL)
	{
		freesel(az);
		az->info->selmap = NULL;
	}
	((az->info->selmap = (int**)malloc(sizeof(int*) * j)) == NULL ?
	stop_exec("Malloc select\n", az) : 0);
	while (tmp < j)
	{
		((az->info->selmap[tmp] = (int*)malloc(sizeof(int*) * i)) == NULL ?
		stop_exec("Malloc select\n", az) : 0);
		tmp++;
	}
	fillselect(az, i, j);
}

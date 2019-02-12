/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:21:03 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/12 14:19:59 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	map_stock(t_acz *az, t_map *map, int fd)
{
	int 	x;
	int 	y;
	int		index;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line))
	{
		x = 0;
		index = 0;
		while (x < az->info->x)
		{
			if (line[index] == ' ' || line[index] == '\0') 
				index++;
			else
			{
				map->map[y][x] = ft_atoi(&line[index]);
				if (map->map[y][x] == SPAWN)
				{
					map->persox = x;
					map->persoy = y;
				}
				while (line[index] != ' ' && line[index] != '\0')
					index++;
				x++;
			}
		}
		y++;
	}
}

static void	map_malloc(t_acz *az, t_map *map)
{
	int		i;

	(map->map = (int **)malloc(sizeof(int *) *az->info->y)) == NULL ? stop_exec("Erreur parse\n") : 0;
	i = -1;
	while (++i < az->info->y)
		(map->map[i] = (int *)malloc(sizeof(int) *az->info->x)) == NULL ? stop_exec("Erreur parse\n") : 0;
}

void		map_parse(t_acz **az, char *name)
{
	int		i;
	int		fd;
	char	*line;

	if (!(fd = open(name, O_RDONLY)) || read(fd, 0, 0) < 0)
		stop_exec("Open failed\n");
	get_next_line(fd, &line);
	i = 0;
	while (line[++i] != '\0')
		(line[i] == ' ') ? (*az)->info->x += 1 : 0;
	while (get_next_line(fd, &line))
		(*az)->info->y += 1;
	close(fd);
	if (!(fd = open(name, O_RDONLY)) || read(fd, 0, 0) < 0)
		stop_exec("Open failed\n");
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
			az->info->selmap[y][x] = az->info->editmap[y + az->info->selecty][x + az->info->selectx];
	}
}

void		parseselect(t_acz *az)
{
	int i;
	int j;
	int tmp;

	tmp = 0;
	i = (ft_abs (az->info->selectx - (az->info->editx / 10)));
	j = (ft_abs(az->info->selecty - (az->info->edity / 10)));
	printf("%d, %d\n", i, j);
	az->info->selsizex = i;
	az->info->selsizey = j;
	if (i == 0 && j == 0)
		return ;
	if (az->info->selmap != NULL)
	{
		free(az->info->selmap);
		az->info->selmap = NULL;
	}
	((az->info->selmap = (int**)malloc(sizeof(int*) * j)) == NULL ? stop_exec("Malloc select\n") : 0);
	while (tmp < j)
	{
		((az->info->selmap[tmp] = (int*)malloc(sizeof(int*) * i)) == NULL ? stop_exec("Malloc select\n") : 0);
		tmp++;
	}
	fillselect(az, i, j);
}

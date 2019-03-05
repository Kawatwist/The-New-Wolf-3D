/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:21:03 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 13:45:59 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	map_stock2(t_map *map, int *x, int *y, char *line)
{
	static int index = 0;

	*x == 0 ? index = 0 : 0;
	if (line[index] == ' ' || line[index] == '\0')
		index += 1;
	else
	{
		map->map[*y][*x] = ft_atoi(&line[index]);
		if (map->map[*y][*x] == SPAWN)
		{
			map->persox = *x;
			map->persoy = *y;
		}
		else if (map->map[*y][*x] == ENEMY)
			map->nbenemy += 1;
		while (line[index] != ' ' && line[index] != '\0')
			index += 1;
		*x += 1;
	}
}

void		map_stock(t_acz *az, t_map *map, int fd)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line))
	{
		x = 0;
		while (x < az->info->x)
			map_stock2(map, &x, &y, line);
		y++;
		free(line);
	}
}

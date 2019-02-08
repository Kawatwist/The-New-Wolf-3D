/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:22:39 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/03 10:34:39 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	parsemap2(t_win *wn, int fd, int x, int y)
{
	int	y2;
	int	x2;
	int	i;
	char	*line;

	if (!(wn->map = (int **)malloc(sizeof(int*) * y)))
		exit(0);
	y2 = -1;
	while (++y2 < y)
		if (!(wn->map[y2] = (int *)malloc(sizeof(int) * x)))
			exit(0);
	y2 = 0;
	while (get_next_line(fd, &line))
	{
		x2 = 0;
		i = 0;
		while (x2 < x)
		{
			if (line[i] == ' ' || line[i] == '\0')
				i++;
			else
			{
				wn->map[y2][x2] = ft_atoi(&line[i]);
				if (wn->map[y2][x2] == SPAWN)
				{
					wn->perso->posx = x2;
					wn->perso->posy = y2;
				}
				while (line[i] != ' ' && line[i] != '\0')
					i++;
				x2++;
			}
		}
		y2++;
	}
	wn->perso->posx = (wn->perso->posx * wn->xscreen / x) + 10;
	wn->perso->posy = (wn->perso->posy * wn->yscreen / y2) + 10;
}

void		parsemap(t_win *wn, void *path)
{
	int	i;
	int	j;
	int	fd;
	int	find;
	char	*line;

	wn->x = 1;
	find = 0;
	if (!(fd = open(path, O_RDONLY)) || read(fd, 0, 0) < 0)
		exit(0);
	get_next_line(fd, &line);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		line[i] == ' ' ? wn->x += 1 : 0;
		i++;
	}
	wn->y = 1;
	while (get_next_line(fd, &line))
		wn->y += 1;
	close(fd);
	if (!(fd = open(path, O_RDONLY)) || read(fd, 0, 0) < 0)
		exit(0);
	i = wn->x;
	j = wn->y;
	parsemap2(wn, fd, i, wn->y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:26:34 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 11:01:47 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		initsprite(t_sprite *sprite, int type, t_acz *az)
{
	if (type == 1)
	{
		sprite->sizex = 64;
		sprite->sizey = 64;
		sprite->tex = az->game->door;
	}
	if (type == 2)
	{
		sprite->sizex = 64;
		sprite->sizey = 64;
		sprite->tex = az->game->enemy;
	}
}

static t_sprite	*create_sprite(double posx, double posy, int type, t_acz *az)
{
	t_sprite *new;

	if (!(new = (t_sprite*)malloc(sizeof(t_sprite))))
		return (NULL);
	new->posx = posx;
	new->posy = posy;
	new->next = NULL;
	initsprite(new, type, az);
	return (new);
}

static void		add_sprite(t_sprite **list, t_sprite *new)
{
	t_sprite *tmp;

	if (list == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void			load_sprites(t_acz *az)
{
	int i;
	int j;

	az->sprite = NULL;
	i = 0;
	while (i < 60)
	{
		j = 0;
		while (j < 60)
		{
			if (az->map->map[i][j] == 20)
				add_sprite(&(az->sprite), (create_sprite(j
				+ 0.5, i + 0.5, 1, az)));
			if (az->map->map[i][j] == 21)
				add_sprite(&(az->sprite), (create_sprite(j
				+ 0.5, i + 0.5, 2, az)));
			j++;
		}
		i++;
	}
}

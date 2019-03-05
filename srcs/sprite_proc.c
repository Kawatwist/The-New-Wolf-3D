/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:28:11 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 10:53:48 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	sort_sprite2(t_sprite **sprite, t_sprite *new, t_sprite *curr)
{
	t_sprite *currn;
	t_sprite *prevn;
	t_sprite *tmp;

	while (curr != NULL)
	{
		currn = new;
		prevn = NULL;
		while (currn != NULL && curr->dist < currn->dist)
		{
			prevn = currn;
			currn = currn->next;
		}
		tmp = curr;
		curr = curr->next;
		if (prevn != NULL)
			prevn->next = tmp;
		else
			new = tmp;
		tmp->next = currn;
	}
	*sprite = new;
}

void		sort_sprite(t_sprite **sprite)
{
	t_sprite *new;
	t_sprite *curr;
	t_sprite *currn;
	t_sprite *prevn;
	t_sprite *tmp;

	if (*sprite == NULL)
		return ;
	new = *sprite;
	curr = new->next;
	new->next = NULL;
	sort_sprite2(sprite, new, curr);
}

void		sprite_dist(t_acz *az)
{
	t_sprite *tmp;

	tmp = az->sprite;
	while (tmp != NULL)
	{
		tmp->dist = sqrt((az->map->persox - tmp->posx)
			* (az->map->persox - tmp->posx) + (az->map->persoy
			- tmp->posy) * (az->map->persoy - tmp->posy));
		tmp = tmp->next;
	}
	az->sdetect.dxf = az->map->persox - az->ray[0]->posx;
	az->sdetect.dyf = az->map->persoy - az->ray[0]->posy;
	az->sdetect.dxl = az->map->persox - az->ray[XSCREEN - 1]->posx;
	az->sdetect.dyl = az->map->persoy - az->ray[XSCREEN - 1]->posy;
}

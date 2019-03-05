/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:43:08 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 13:54:02 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	changeray2(t_acz *az, int portal, int i)
{
	double ang;

	ang = (i * 0.00144) + az->info->angle;
	if (portal == 6)
	{
		az->ray[i]->posx = (az->info->range * cos(ang)) +
			(az->info->range * sin(ang)) + (az->map->persox);
		az->ray[i]->posy = (az->info->range * -sin(ang)) +
			(az->info->range * cos(ang)) + (az->map->persoy);
	}
	else
	{
		az->ray[i]->posx = (az->info->range * cos(ang)) +
			(az->info->range * sin(ang)) + (az->map->persox);
		az->ray[i]->posy = (az->info->range * -sin(ang)) +
			(az->info->range * cos(ang)) + (az->map->persoy);
	}
}

void		changeray(t_acz *az, int portal)
{
	int		i;
	double	rotate;

	i = -1;
	az->info->angle += -rotpos(az, portal);
	while (++i < XSCREEN)
		changeray2(az, portal, i);
}

int		frontblock(t_acz *az, int type, int portal)
{
	int value;

	value = 0;
	if (portal == 6)
	{
		value += (az->map->blue[0] == 5 && type == 2 ? SBLOCK + 10 : 0);
		value += (az->map->blue[0] == 6 && type == 1 ? SBLOCK + 10 : 0);
		value += (az->map->blue[0] == 7 && type == 2 ? -10 : 0);
		value += (az->map->blue[0] == 8 && type == 1 ? -10 : 0);
	}
	else
	{
		value += (az->map->blue[0] == 5 && type == 2 ? SBLOCK + 10 : 0);
		value += (az->map->blue[0] == 6 && type == 1 ? SBLOCK + 10 : 0);
		value += (az->map->blue[0] == 7 && type == 2 ? -10 : 0);
		value += (az->map->blue[0] == 8 && type == 1 ? -10 : 0);
	}
	return (value);
}

int			diffside(t_acz *az, t_dda *dda)
{
	int	value1;
	int	value2;
	int	portal;

	value1 = dda->x / SBLOCK;
	value2 = dda->y / SBLOCK;
	portal = az->map->map[value2][value1];
	if ((((az->map->map[(dda->y - 1) / SBLOCK][value1]) == 6) &&
				((az->map->map[(dda->y + 1) / SBLOCK][value1]) == 6)))
	{
		if (dda->pasx == -1)
			return ((az->map->blue[0] = 7));
		return ((az->map->blue[0] = 5));
	}
	if ((((az->map->map[value2][(dda->x - 1) / SBLOCK]) == 6) &&
				((az->map->map[value2][(dda->x + 1) / SBLOCK]) == 6)))
	{
		if (dda->pasy == -1)
			return ((az->map->blue[0] = 8));
		return ((az->map->blue[0] = 6));
	}
	if ((((az->map->map[(dda->y - 1) / SBLOCK][value1]) == 7) &&
				((az->map->map[(dda->y + 1) / SBLOCK][value1]) == 7)))
	{
		if (dda->pasx == -1)
			return ((az->map->orange[0] = 7));
		return ((az->map->orange[0] = 5));
	}
	if ((((az->map->map[value2][(dda->x - 1) / SBLOCK]) == 7) &&
				((az->map->map[value2][(dda->x + 1) / SBLOCK]) == 7)))
	{
		if (dda->pasy == -1)
			return ((az->map->orange[0] = 8));
		return ((az->map->orange[0] = 6));
	}
	return (0);
}

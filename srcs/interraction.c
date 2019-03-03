/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:43:08 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/02 11:44:09 by lomasse          ###   ########.fr       */
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
		value += (az->map->blue[0] == 5  && type == 2 ? SBLOCK + 10 : 0);
		value += (az->map->blue[0] == 6  && type == 1 ? SBLOCK + 10 : 0);
		value += (az->map->blue[0] == 7  && type == 2 ? -10 : 0);
		value += (az->map->blue[0] == 8  && type == 1 ? -10 : 0);
	}
	else
	{
		value += (az->map->blue[0] == 5  && type == 2 ? SBLOCK + 10 : 0);
		value += (az->map->blue[0] == 6  && type == 1 ? SBLOCK + 10 : 0);
		value += (az->map->blue[0] == 7  && type == 2 ? -10 : 0);
		value += (az->map->blue[0] == 8  && type == 1 ? -10 : 0);
	}
	return (value);
}

void		setportal(t_acz *az, t_dda dda, int portal)
{
	int i;
	int	j;

	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
			az->map->map[j][i] == portal ? az->map->map[j][i] = 1 : 0; // reset block
	}
	az->map->map[dda.y / SBLOCK][dda.x / SBLOCK] = portal;
	if (portal == 6)
	{
		az->map->blue[1] = dda.y - (dda.y % SBLOCK);
		az->map->blue[2] = dda.x - (dda.x % SBLOCK);
		if (az->map->orange[0] != 0)
		{
			az->map->blue[3] = -rotpos(az, 6);
			az->map->orange[3] = az->map->blue[3] * -1;
			az->map->blue[4] = az->map->orange[1];
			az->map->blue[5] = az->map->orange[2];
		}
		az->map->blue[4] += frontblock(az, 1, 6);
		az->map->blue[5] += frontblock(az, 2, 6);
	}
	else
	{
		az->map->orange[1] = dda.y - (dda.y % SBLOCK);
		az->map->orange[2] = dda.x - (dda.x % SBLOCK);
		if (az->map->orange[0] != 0)
		{
			az->map->orange[3] = -rotpos(az, 7);
			az->map->blue[3] = az->map->orange[3] * -1;
			az->map->orange[4] = az->map->blue[1];
			az->map->orange[5] = az->map->blue[2];
		}
		az->map->orange[4] += frontblock(az, 1, 6);
		az->map->orange[5] += frontblock(az, 2, 6);
	}
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

void    dds(t_acz *az, t_dda *dda, int portal)
{
	dda->pasx = (dda->dx = ((int)(dda->dstx)) - dda->x) < 0 ? -1 : 1;
	dda->pasy = (dda->dy = ((int)(dda->dsty)) - dda->y) < 0 ? -1 : 1;
	dda->dx = ft_abs(dda->dx);
	dda->dy = ft_abs(dda->dy);
	if (dda->dx > dda->dy)
	{
		dda->pente = 1;
		dda->e = dda->dx;
	}
	else
		dda->e = dda->dy;
	dda->dx = dda->dx * 2;
	dda->dy = dda->dy * 2;
	while (dda->dist < az->info->range)
	{
		if (dda->pente == 1)
		{
			dda->distx++;
			dda->x += dda->pasx;
			dda->e = dda->e - dda->dy;
			if (dda->e < 0)
			{
				dda->disty++;
				dda->y += dda->pasy;
				dda->e += dda->dx;
			}
		}else
		{
			dda->disty++;
			dda->y += dda->pasy;
			dda->e = dda->e - dda->dx;
			if (dda->e < 0)
			{
				dda->distx++;
				dda->x+= dda->pasx;
				dda->e += dda->dy;
			}
		}
		dda->dist = sqrt((dda->distx * dda->distx) + (dda->disty * dda->disty));
		az->side[dda->i] = -1;
		if (dda->y < 0 || dda->y / SBLOCK > 59 || dda->x < 0 || dda->x / SBLOCK > 59)
		{
			az->side[dda->i] = 0;
			az->ray[dda->i]->obs = 60 * SBLOCK;
			break ;
		}
		if ((az->map->map[(int)(dda->y / SBLOCK)][(int)(dda->x / SBLOCK)]) != 0)
		{
			az->side[dda->i] = get_side(dda, az);
			dda->dist = (dda->dist * cos((dda->i - (XSCREEN / 2)) * 0.00144));
			dda->dist = (dda->dist != 0 ? (dda->dist) : 0);
			az->ray[dda->i]->obs = (dda->dist / (YSCREEN / 2));
			break ;
		}
	}
	if (dda->dist == az->info->range)
		az->ray[dda->i]->obs = dda->dist;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:43:08 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/15 15:08:04 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	changeray(t_acz *az, int portal)
{
	int		i;
	double	ang;
	double	rotate;
	i = -1;

	rotate = (((az->map->orange[0]) - (az->map->blue[0]) * 90) * 0.017453);
	az->info->angle += (portal == 6 ? -rotate : rotate);
	while (++i < XSCREEN)
	{
		ang = (i * 0.00144) + az->info->angle;
		if (portal == 6)
		{
			az->ray[i]->posx = (az->info->range * cos(ang)) + (az->info->range * -sin(ang)) + (az->map->persox);
			az->ray[i]->posy = (az->info->range * sin(ang)) + (az->info->range * cos(ang)) + (az->map->persoy);
		}
		else
		{
			az->ray[i]->posx = (az->info->range * cos(ang)) + (az->info->range * -sin(ang)) + (az->map->persox);
			az->ray[i]->posy = (az->info->range * sin(ang)) + (az->info->range * cos(ang)) + (az->map->persoy);
		}
	}
}

void	setportal(t_acz *az, int y, int x, int portal)
{
	int i;
	int	j;

	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
			az->map->map[j][i] == portal ? az->map->map[j][i] = 1 : 0;
	}
	az->map->map[y][x] = portal;
	if (portal == 6)
	{
		az->map->blue[1] = y;
		az->map->blue[2] = x;
	}
	else 
	{
		az->map->orange[1] = y;
		az->map->orange[2] = x;
	}
}

int	diffside(t_acz *az, t_dda *dda)
{
	int	value1;
	int	value2;
	int	portal;

	value1 = dda->x / SBLOCK;
	value2 = dda->y / SBLOCK;
	portal = az->map->map[value2][value1];
	if ((((az->map->map[(dda->y - 1) / SBLOCK][value1]) == 6) && ((az->map->map[(dda->y + 1) / SBLOCK][value1]) == 6)))
	{
		if (dda->pasx == -1)
			return ((az->map->blue[0] = 7));
		return ((az->map->blue[0] = 5));
	}
	if ((((az->map->map[value2][(dda->x - 1) / SBLOCK]) == 6) && ((az->map->map[value2][(dda->x + 1) / SBLOCK]) == 6)))
	{
		if (dda->pasy == -1)
			return ((az->map->blue[0] = 8));
		return ((az->map->blue[0] = 6));
	}
	if ((((az->map->map[(dda->y - 1) / SBLOCK][value1]) == 7) && ((az->map->map[(dda->y + 1) / SBLOCK][value1]) == 7)))
	{
		if (dda->pasx == -1)
			return ((az->map->orange[0] = 7));
		return ((az->map->orange[0] = 5));
	}
	if ((((az->map->map[value2][(dda->x - 1) / SBLOCK]) == 7) && ((az->map->map[value2][(dda->x + 1) / SBLOCK]) == 7)))
	{
		if (dda->pasy == -1)
			return ((az->map->orange[0] = 8));
		return ((az->map->orange[0] = 6));
	}
	return (0);
}

void	portalapply(t_acz *az, t_dda *current, int facediff, int portal)
{
	double	tmp;
	int		difportal;
	int		xoff;
	int		yoff;

	facediff *= 90;
	difportal = (portal == 6 ? (az->map->blue[0] - az->map->orange[0]) : (az->map->orange[0] - az->map->blue[0]));
	xoff = (portal == 6 ? (az->map->blue[2] - az->map->orange[2]) : (az->map->orange[2] - az->map->blue[2]));
	yoff = (portal == 6 ? (az->map->blue[1] - az->map->orange[1]) : (az->map->orange[1] - az->map->blue[1]));
	
	tmp = (cos((difportal * 90) * 0.017453) + (xoff) + (sin((difportal * 90) * 0.017453) + (yoff)));
	current->dy = (-sin((difportal * 90) * 0.017453) + (xoff)) + (cos((difportal * 90) * 0.017453) + (yoff));
	current->dx = tmp;
}

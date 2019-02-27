/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:47:12 by cbilga            #+#    #+#             */
/*   Updated: 2019/02/27 18:32:12 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int 		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void initdda(t_dda *dda)
{
	dda->pasx = 0;
	dda->pasy = 0;
	dda->distx = 0;
	dda->disty = 0;
	dda->dist = 0;
	dda->side = 0;
	dda->dx = 0;
	dda->dy = 0;
	dda->e = 0;
	dda->pente = 0;
}

int	get_side(t_dda *dda, t_acz *az)
{
	// 1 - Nord , 2 - Sud , 3 - Ouest , 4 -Est , 0 - coin
	if (((az->map->map[(dda->y - 1) / SBLOCK][dda->x / SBLOCK]) == 1) && ((az->map->map[(dda->y + 1) / SBLOCK][dda->x / SBLOCK]) == 1))
	{
		if (dda->pasx == -1)
			return (3 * SBLOCK + dda->y % SBLOCK);
		return (4 * SBLOCK + dda->y % SBLOCK);
	}
	if (((az->map->map[dda->y / SBLOCK][(dda->x - 1) / SBLOCK]) == 1) && ((az->map->map[dda->y / SBLOCK][(dda->x + 1) / SBLOCK]) == 1))
	{
		if (dda->pasy == -1)
			return (1 * SBLOCK + dda->x % SBLOCK);
		return (2 * SBLOCK + dda->x % SBLOCK);
	}
	if ((az->map->map[dda->y / SBLOCK][(dda->x - 1) / SBLOCK]) == 5)
		return (5 * SBLOCK + dda->x % SBLOCK);
	return (0);
}

void	raycast(t_acz *az)
{
	t_dda dda;
	int		tmp;

	dda.i = 0;
	tmp = 0;
	while (dda.i < XSCREEN)
	{
		initdda(&dda);
		dda.x = (int)(az->map->persox * SBLOCK);
		dda.y = (int)(az->map->persoy * SBLOCK);
		dda.pasx = (dda.dx = ((int)(az->ray[dda.i]->posx * SBLOCK)) - dda.x) < 0 ? -1 : 1;
		dda.pasy = (dda.dy = ((int)(az->ray[dda.i]->posy * SBLOCK)) - dda.y) < 0 ? -1 : 1;
		dda.dx = ft_abs(dda.dx);
		dda.dy = ft_abs(dda.dy);
		if (dda.dx > dda.dy)
		{
			dda.pente = 1;
			dda.e = dda.dx;
		}
		else
			dda.e = dda.dy;
		dda.dx = dda.dx * 2;
		dda.dy = dda.dy * 2;
		while (dda.dist < az->info->range)
		{
			if (dda.pente == 1)
			{
				dda.distx++;
				dda.x += dda.pasx;
				dda.e = dda.e - dda.dy;
				if (dda.e < 0)
				{
					dda.disty++;
					dda.y += dda.pasy;
					dda.e += dda.dx;
				}
			}
			else
			{
				dda.disty++;
				dda.y += dda.pasy;
				dda.e = dda.e - dda.dx;
				if (dda.e < 0)
				{
					dda.distx++;
					dda.x+= dda.pasx;
					dda.e += dda.dy;
				}
			}
			dda.dist = sqrt((dda.distx * dda.distx) + (dda.disty * dda.disty));
			az->side[dda.i] = -1;
			if (dda.y < 0 || dda.y / SBLOCK > 59 || dda.x < 0 || dda.x / SBLOCK > 59)
			{
				az->side[dda.i] = 0;
				az->ray[dda.i]->obs = 60 * SBLOCK;
				break ;
			}
			if ((az->map->map[(int)(dda.y / SBLOCK)][(int)(dda.x / SBLOCK)]) != 0)
			{
				if ((az->map->map[dda.y / SBLOCK][dda.x / SBLOCK]) == 1 || az->map->map[dda.y / SBLOCK][dda.x / SBLOCK] == 5)
				{
					az->side[dda.i] = get_side(&dda, az);
					az->shoot == 1 && dda.i == XSCREEN / 2 && tmp == 0 ? setportal(az, dda.y / SBLOCK, dda.x / SBLOCK, 6) : 0;
					az->shoot1 == 1 && dda.i == XSCREEN / 2 && tmp == 0 ? setportal(az, dda.y / SBLOCK, dda.x / SBLOCK, 7) : 0;
					az->shoot == 1 && dda.i == XSCREEN / 2 && tmp == 0 ? diffside(az, &dda) : 0;
					az->shoot1 == 1 && dda.i == XSCREEN / 2 && tmp == 0? diffside(az, &dda) : 0;
					dda.dist = (dda.dist * cos((dda.i - (XSCREEN / 2)) * 0.00144));
					dda.dist = (dda.dist != 0 ? (dda.dist) : 0);
					az->zbuffer[dda.i] = dda.dist / SBLOCK;
					az->ray[dda.i]->obs = (dda.dist / (YSCREEN / 2));
					break ;
				}
				if ((az->map->map[dda.y / SBLOCK][dda.x / SBLOCK]) == 6)
				{
					dda.i == XSCREEN / 2 ? tmp = 1 : 0;
					portalapply(az, &dda, 6);
				}
				else if(az->map->map[dda.y / SBLOCK][dda.x / SBLOCK] == 7)
				{
					dda.i == XSCREEN / 2 ? tmp = 1 : 0;
					portalapply(az, &dda, 7);
				}
			}
		}
		if (dda.dist == az->info->range)
			az->ray[dda.i]->obs = dda.dist;
		dda.i += 1;
	}
}

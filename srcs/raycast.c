/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:38:10 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/06 10:01:54 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	raycast5(t_acz *az, t_dda *dda)
{
	if ((az->map->map[dda->y / SBLOCK][dda->x / SBLOCK]) == 6)
	{
		dda->i == XSCREEN / 2 ? dda->tmp = 1 : 0;
		newportail(az, dda, 6);
	}
	else if (az->map->map[dda->y / SBLOCK][dda->x / SBLOCK] == 7)
	{
		dda->i == XSCREEN / 2 ? dda->tmp = 1 : 0;
		newportail(az, dda, 7);
	}
}

static int	raycast4(t_acz *az, t_dda *dda)
{
	if ((az->map->map[(int)(dda->y / SBLOCK)][(int)(dda->x / SBLOCK)]) != 0)
	{
		if ((az->map->map[dda->y / SBLOCK][dda->x / SBLOCK]) == 1
			|| az->map->map[dda->y / SBLOCK][dda->x / SBLOCK] == 5)
		{
			az->side[dda->i] = get_side(dda, az);
			az->shoot == 1 && dda->i == XSCREEN / 2 && dda->tmp
				== 0 ? setportal(az, *dda, 6) : 0;
			az->shoot1 == 1 && dda->i == XSCREEN / 2 && dda->tmp
				== 0 ? setportal(az, *dda, 7) : 0;
			az->shoot == 1 && dda->i == XSCREEN / 2 && dda->tmp
				== 0 ? diffside(az, dda) : 0;
			az->shoot1 == 1 && dda->i == XSCREEN / 2 && dda->tmp
				== 0 ? diffside(az, dda) : 0;
			dda->dist = (dda->dist * cos((dda->i - (XSCREEN / 2)) * 0.00195));
			dda->dist = (dda->dist != 0 ? (dda->dist) : 0);
			az->zbuffer[dda->i] = dda->dist / SBLOCK;
			az->ray[dda->i]->obs = (dda->dist / (YSCREEN / 2));
			return (1);
		}
	}
	raycast5(az, dda);
	return (0);
}

static void	raycast3(t_dda *dda)
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
	}
	else
	{
		dda->disty++;
		dda->y += dda->pasy;
		dda->e = dda->e - dda->dx;
		if (dda->e < 0)
		{
			dda->distx++;
			dda->x += dda->pasx;
			dda->e += dda->dy;
		}
	}
}

static void	raycast2(t_acz *az, t_dda *dda)
{
	while (dda->dist < az->info->range)
	{
		raycast3(dda);
		dda->dist = sqrt((dda->distx * dda->distx) + (dda->disty * dda->disty));
		az->side[dda->i] = -1;
		if (dda->y < 0 || dda->y > 3775 || dda->x < 0 || dda->x > 3775)
		{
			unlimitedmap(dda);
		}
		if (raycast4(az, dda))
			break ;
	}
}

void		raycast(t_acz *az)
{
	t_dda dda;

	dda.i = 0;
	dda.tmp = 0;
	while (dda.i < XSCREEN)
	{
		initdda(&dda, az);
		if (dda.dx > dda.dy)
		{
			dda.pente = 1;
			dda.e = dda.dx;
		}
		else
			dda.e = dda.dy;
		dda.dx = dda.dx * 2;
		dda.dy = dda.dy * 2;
		raycast2(az, &dda);
		if (dda.dist == az->info->range)
			az->ray[dda.i]->obs = dda.dist;
		dda.i += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:47:12 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 13:22:45 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void		initdda(t_dda *dda, t_acz *az)
{
	dda->x = (int)(az->map->persox * SBLOCK);
	dda->y = (int)(az->map->persoy * SBLOCK);
	dda->dx = (int)(az->ray[dda->i]->posx * SBLOCK);
	dda->dy = (int)(az->ray[dda->i]->posy * SBLOCK);
	dda->pasx = (dda->dx - dda->x) < 0 ? -1 : 1;
	dda->pasy = (dda->dy - dda->y) < 0 ? -1 : 1;
	dda->dx = ft_abs(dda->dx);
	dda->dy = ft_abs(dda->dy);
	dda->distx = 0;
	dda->disty = 0;
	dda->dist = 0;
	dda->side = 0;
	dda->e = 0;
	dda->pente = 0;
}

int			get_side(t_dda *dda, t_acz *az)
{
	if (((az->map->map[(dda->y - 1) / SBLOCK][dda->x / SBLOCK]) == 1)
		&& ((az->map->map[(dda->y + 1) / SBLOCK][dda->x / SBLOCK]) == 1))
	{
		if (dda->pasx == -1)
			return (3 * SBLOCK + dda->y % SBLOCK);
		return (4 * SBLOCK + dda->y % SBLOCK);
	}
	if (((az->map->map[dda->y / SBLOCK][(dda->x - 1) / SBLOCK]) == 1)
		&& ((az->map->map[dda->y / SBLOCK][(dda->x + 1) / SBLOCK]) == 1))
	{
		if (dda->pasy == -1)
			return (1 * SBLOCK + dda->x % SBLOCK);
		return (2 * SBLOCK + dda->x % SBLOCK);
	}
	if ((az->map->map[dda->y / SBLOCK][(dda->x - 1) / SBLOCK]) == 5)
		return (5 * SBLOCK + dda->x % SBLOCK);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:39:08 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 13:58:55 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	setportal3(t_acz *az, t_dda dda, int portal)
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

static void	setportal2(t_acz *az, t_dda dda, int portal)
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

void		setportal(t_acz *az, t_dda dda, int portal)
{
	int i;
	int j;

	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
			az->map->map[j][i] == portal ? az->map->map[j][i] = 1 : 0;
	}
	az->map->map[dda.y / SBLOCK][dda.x / SBLOCK] = portal;
	if (portal == 6)
		setportal3(az, dda, portal);
	else
		setportal2(az, dda, portal);
}

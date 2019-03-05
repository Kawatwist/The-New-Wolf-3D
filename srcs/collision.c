/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:54:23 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 19:10:08 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	collision4(t_acz *az)
{
	if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 6 &&
		az->map->orange[0] != 0)
	{
		az->map->persoy = az->map->orange[1] / SBLOCK;
		az->map->persox = az->map->orange[2] / SBLOCK;
		changeray(az, 6);
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 7 &&
			az->map->blue[0] != 0)
	{
		az->map->persoy = az->map->blue[1] / SBLOCK;
		az->map->persox = az->map->blue[2] / SBLOCK;
		changeray(az, 7);
	}
}

static void	collision3(t_acz *az)
{
	if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 4)
	{
		az->inv->key += 1;
		az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
	}
	if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 5)
	{
		if (az->inv->key > 0)
		{
			az->inv->key -= 1;
			az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
		}
		else
		{
			az->map->persox -= az->map->lastmovx;
			az->map->persoy -= az->map->lastmovy;
		}
	}
	collision4(az);
}

static void	collision2(t_acz *az)
{
	if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 3)
	{
		az->interface = 0;
		ft_putstr("You win\n");
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 8)
	{
		az->inv->health < 100 ? az->inv->health = 100 : 0;
		az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 9)
	{
		az->inv->shield < 100 ? az->inv->shield = 100 : 0;
		az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 1)
	{
		az->map->persox -= az->map->lastmovx;
		az->map->persoy -= az->map->lastmovy;
	}
	collision3(az);
}

void		collision(t_acz *az)
{
	if (az->map->persox > 60)
	{
		az->map->persox = 0.5;
		if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 1)
			az->map->persox = 59.5;
	}
	if (az->map->persoy > 60)
	{
		az->map->persoy = 0.5;
		if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 1)
			az->map->persoy = 59.5;
	}
	if (az->map->persox <= 0)
	{
		az->map->persox = 59.5;
		if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 1)
			az->map->persox = 0.5;
	}
	if (az->map->persoy <= 0)
	{
		az->map->persoy = 59.5;
		if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 1)
			az->map->persoy = 0.5;
	}
	collision2(az);
}

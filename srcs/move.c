/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 11:04:25 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 4)
	{
		az->inv->key += 1;
		az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 5)
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

void		rotate_perso(t_acz *az)
{
	int		current;
	double	ang;

	current = 0;
	while (current < XSCREEN)
	{
		ang = (current * 0.002) + az->info->angle;
		az->ray[current]->posx = (az->info->range * cos(ang))
			+ (az->info->range * -sin(ang)) + (az->map->persox);
		az->ray[current]->posy = (az->info->range * sin(ang))
			+ (az->info->range * cos(ang)) + (az->map->persoy);
		current++;
	}
}

void		mouvement(t_acz *az, int move)
{
	double tmp;

	if (move == 0 || move == 2)
	{
		az->map->lastmovx = 0;
		az->map->lastmovy = (move == 2 ? 0.1 : -0.1) * az->speed;
	}
	else
	{
		az->map->lastmovx = (move == 3 ? 0.1 : -0.1) * az->speed;
		az->map->lastmovy = 0;
	}
	tmp = (az->map->lastmovx * cos(az->info->angle))
		+ (az->map->lastmovy * -sin(az->info->angle));
	az->map->lastmovy = (az->map->lastmovx * sin(az->info->angle))
		+ (az->map->lastmovy * cos(az->info->angle));
	az->map->lastmovx = tmp;
	az->map->persox += az->map->lastmovx;
	az->map->persoy += az->map->lastmovy;
	collision(az);
}

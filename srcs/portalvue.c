/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portalvue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:04:33 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/27 18:57:31 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

double		rotpos(t_acz *az, int portal)
{
	if (portal == 6)
	{
		if (az->map->orange[0] - az->map->blue[0] == 0)
			return (180 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == 1)
			return (90 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == -1)
			return (-90 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == 2)
			return (0);
		else if (az->map->orange[0] - az->map->blue[0] == -2)
			return (0);
		else if (az->map->orange[0] - az->map->blue[0] == 3)
			return (270 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == -3)
			return (-270 * 0.017453);
	}
	else
	{
		if (az->map->orange[0] - az->map->blue[0] == 0)
			return (180 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == 1)
			return (-90 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == -1)
			return (90 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == 2)
			return (0);
		else if (az->map->orange[0] - az->map->blue[0] == -2)
			return (0);
		else if (az->map->orange[0] - az->map->blue[0] == 3)
			return (-270 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == -3)
			return (270 * 0.017453);
	}
	return(0);
}

float		offset(t_acz *az, t_dda *dda, int  portal, int coor)
{
	float value2;
	float value;

	value2 = (portal == 7 ? az->map->blue[coor] : az->map->orange[coor]);
	value = 0;
	if (portal == 6)
	{
		if (coor == 2)
		{
			value += (az->map->blue[0] == 6 ? -0.5 : 0);
			value += (az->map->blue[0] == 5 ? 0.5 : 0);
			value += (az->map->blue[0] == 8 ? 0.5 : 0);
			value += (az->map->blue[0] == 7 ? 1.5 : 0);
		}
		else
		{
			value += (az->map->blue[0] == 6 ? 0.5 : 0);
			value += (az->map->blue[0] == 5 ? -0.5 : 0);
			value += (az->map->blue[0] == 8 ? 1.5 : 0);
			value += (az->map->blue[0] == 7 ? 0.5 : 0);
		}
	}
	else
	{
		if (coor == 2)
		{
			value += (az->map->orange[0] == 6 ? -0.5 : 0);
			value += (az->map->orange[0] == 5 ? 0.5 : 0);
			value += (az->map->orange[0] == 8 ? 0.5 : 0);
			value += (az->map->orange[0] == 7 ? 1.5 : 0);
		}
		else
		{
			value += (az->map->orange[0] == 6 ? 0.5 : 0);
			value += (az->map->orange[0] == 5 ? -0.5 : 0);
			value += (az->map->orange[0] == 8 ? 1.5 : 0);
			value += (az->map->orange[0] == 7 ? 0.5 : 0);
		}
	}
	if (dda->i == 400)
		coor == 1 ? printf("Y == >%f\t", value) : printf("X == %f\n", value);
	value = (value * SBLOCK) + (value2 * SBLOCK);
	return (value);
}

void		wallpos(t_acz *az, t_dda *dda, int portal)
{
	float	tmp;

	if (az->side[dda->i] / SBLOCK == 7) //E S W N
    {
		if (az->map->orange[0] == 5)
            dda->y = SBLOCK - (az->side[dda->i] % SBLOCK);
		else if (az->map->orange[0] == 6)
            dda->x = SBLOCK - (az->side[dda->i] % SBLOCK);
		else if (az->map->orange[0] == 7)
            dda->y = SBLOCK - (az->side[dda->i] % SBLOCK);
		else
            dda->x = SBLOCK - (az->side[dda->i] % SBLOCK);
    }
    else
    {
        if (az->map->blue[0] == 5)
            dda->y = SBLOCK - (az->side[dda->i] % SBLOCK);
		else if (az->map->blue[0] == 6)
            dda->x = SBLOCK - (az->side[dda->i] % SBLOCK);
		else if (az->map->blue[0] == 7)
            dda->y = SBLOCK - (az->side[dda->i] % SBLOCK);
		else
            dda->x = SBLOCK - (az->side[dda->i] % SBLOCK);
    }
}

static float offblock(t_acz *az, t_dda *dda, int portal, int type)
{
	if (portal == 6)
		return(az->map->blue[type] - az->map->orange[type]);
	else
		return(az->map->orange[type] - az->map->blue[type]);
}

static float	portaloff2(t_acz *az, t_dda *dda, int portal)
{
	float value;

	value = 0;
	if (portal == 6)
	{
		value += az->map->blue[0] == 6 ? SBLOCK : 0 ;
		value += az->map->blue[0] == 5 ? dda->x % SBLOCK : 0 ;
		value += az->map->blue[0] == 7 ? SBLOCK - (dda->x % SBLOCK) : 0;
	}
	else
	{
		value += az->map->orange[0] == 6 ? SBLOCK : 0 ;
		value += az->map->orange[0] == 5 ? dda->x % SBLOCK : 0 ;
		value += az->map->orange[0] == 7 ? SBLOCK - (dda->x % SBLOCK) : 0;
	}
	return (value);
}

static float	portaloff1(t_acz *az, t_dda *dda, int portal)
{
	float value;

	value = 0;
	if (portal == 6)
	{
		value += az->map->blue[0] == 5 ? SBLOCK : 0 ;
		value += az->map->blue[0] == 8 ? dda->x % SBLOCK : 0 ;
		value += az->map->blue[0] == 6 ? SBLOCK - (dda->x % SBLOCK) : 0;
	}
	else
	{
		value += az->map->orange[0] == 5 ? SBLOCK : 0 ;
		value += az->map->orange[0] == 8 ? dda->x % SBLOCK : 0 ;
		value += az->map->orange[0] == 6 ? SBLOCK - (dda->x % SBLOCK) : 0;
	}
	return (value);
}

void		portalapply(t_acz *az, t_dda *dda, int portal) // portal == contact
{
	double	rot;
	double	tmp;
	double	offx;
	double	offy;

	rot = rotpos(az, portal) * (cos((dda->i - (XSCREEN / 2)) * 0.00144));
	offx = offblock(az, dda, portal, 2);
	offy = offblock(az, dda, portal, 1);
	dda->x -= dda->x % SBLOCK;
	dda->y -= dda->y % SBLOCK;
	dda->x += offblock(az, dda, portal, 2);
	dda->y += offblock(az, dda, portal, 1);
	dda->dstx = (az->ray[dda->i]->posx - az->map->persox);
	dda->dstx = (az->ray[dda->i]->posy - az->map->persoy);
	tmp = (dda->dstx * cos(rot)) + (dda->dsty * sin(rot));
	dda->dsty = (dda->dstx * cos(rot)) + (dda->dsty * sin(rot));
	dda->dstx = tmp;
	dda->dsty += offx;
	dda->dstx += offy;
	dda->dstx += portaloff1(az, dda, portal);
	dda->dsty += portaloff2(az, dda, portal);
	dds(az, dda, portal);
	//	x = offset(az, dda, portal, 2);
	//	y = offset(az, dda, portal, 1);
	//	wallpos(az, dda, portal);
	//	tmp = (cos(rot + az->info->angle) * (az->info->range)) + (sin(rot + az->info->angle) * (az->info->range)); 
	//	desty = (-sin(rot + az->info->angle) * (az->info->range)) + (cos(rot + az->info->angle) * (az->info->range)); 
	//	desty += (portal == 6 ? az->map->orange[1] : az->map->blue[1]);
	//	destx = tmp + (portal == 6 ? az->map->orange[2] : az->map->blue[2]);
	//	dda->x += x;
	//	dda->y += y;
	//	if (dda->i == 400)
	//	{
	//		printf("NEW => %d, %d\n", dda->x / 32, dda->y / 32);
	//	}
	//	dda->dstx = destx;
	//	dda->dsty = desty;
}

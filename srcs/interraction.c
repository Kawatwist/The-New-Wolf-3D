/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:43:08 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/25 17:19:00 by cbilga           ###   ########.fr       */
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
	double	newrot;

	i = -1;
	rotate = ((((az->map->orange[0]) - (az->map->blue[0])) * 90) * 0.017453);
	if (az->map->orange[0] - az->map->blue[0] == 0)
		newrot = 180 * 3.14159 / 180;
	else if (az->map->orange[0] - az->map->blue[0] == 1 ||
			az->map->orange[0] - az->map->blue[0] == -3)
		newrot = 90 * 3.14159 / 180;
	else if (az->map->orange[0] - az->map->blue[0] == 2 ||
			az->map->orange[0] - az->map->blue[0] == -2)
		newrot = 0;
	else if (az->map->orange[0] - az->map->blue[0] == 3 ||
			az->map->orange[0] - az->map->blue[0] == -1)
		newrot = 270 * 3.14159 / 180;
	az->info->angle += newrot;
	while (++i < XSCREEN)
		changeray2(az, portal, i);
}

void		setportal(t_acz *az, int y, int x, int portal)
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
/*
void		portalapply(t_acz *az, t_dda *current, int facediff, int portal)
{
	double	tmp;
	double	newrot;
	int		difportal;
	int		xoff;
	int		yoff;

	if (az->map->orange[0] - az->map->blue[0] == 0)
		newrot = 180 * 0.017453;
	else if (az->map->orange[0] - az->map->blue[0] == 1 ||
			az->map->orange[0] - az->map->blue[0] == -1)
		newrot = 90 * 0.017453;
	else if (az->map->orange[0] - az->map->blue[0] == 2 ||
			az->map->orange[0] - az->map->blue[0] == -2)
		newrot = 0;
	else
		newrot = 270 * 0.017453;
	if (portal == 6)
	{
		xoff = (portal == 6 ? az->map->blue[2] : az->map->orange[2]);
		yoff = (portal == 6 ? az->map->blue[1] : az->map->orange[1]);
	}
	tmp = (cos((newrot) + (xoff) + (sin(newrot) + (yoff))));
	current->dy = (-sin(newrot) + (xoff)) + (cos(newrot) + (yoff));
	current->dx = tmp;
	current->x = xoff;
	current->y = yoff;
	if (current->dx > current->dy)
	{
		current->pente = 1;
		current->e = current->dx;
	}
	else
		current->e = current->dy;
}
*/
void    portalapply(t_acz *az, t_dda *dda, int facediff, int portal)
{
    double  tmp;
    double  newrot;
    int     difportal;
    int     xoff;
    int     yoff;

//  rotation portal
    if (az->map->orange[0] - az->map->blue[0] == 0)
        newrot = 180 * 0.017453;
    else if (az->map->orange[0] - az->map->blue[0] == 1 || az->map->orange[0] - az->map->blue[0] == -1)
        newrot = 270 * 0.017453;
    else if (az->map->orange[0] - az->map->blue[0] == 2 || az->map->orange[0] - az->map->blue[0] == -2)
        newrot = 0;
    else
        newrot = 90 * 0.017453;
//si le portal dans lequel rentre les rays ets BLEU/ORANGE
    if (portal == 6)
    {
        //on initialise les nouveau x et y aux positions d portail oppose
        dda->x = az->map->orange[2] * SBLOCK;
        dda->y = az->map->orange[1] * SBLOCK;
//on calcule le destination du rayon par rapport a 0,0
        xoff = (int)(az->ray[dda->i]->posx) - (az->map->blue[2] * SBLOCK);
        yoff = (int)(az->ray[dda->i]->posy) - (az->map->blue[1] * SBLOCK);
        if (dda->i == 400)
        {
            printf("portal b %d %d \n",  dda->x, dda->y);
        }
//on fait la rotation
        tmp = (int)(cos(newrot) * xoff) + (sin(newrot) * yoff);
        yoff = (int)(-sin(newrot) * xoff) + (cos(newrot) * yoff);
//on decale la destination par rapport au nouveau portail
        xoff = tmp;
        xoff += az->map->orange[2] * SBLOCK;
        yoff += az->map->orange[1] * SBLOCK;
    }
    else
    {
        dda->x = az->map->blue[2] * SBLOCK;
        dda->y = az->map->blue[1] * SBLOCK;
        xoff = (int)(az->ray[dda->i]->posx) - (az->map->orange[2] * SBLOCK);
        yoff = (int)(az->ray[dda->i]->posy) - (az->map->orange[1] * SBLOCK);
        if (dda->i == 400)
            printf("portal o %d %d \n",  dda->x, dda->y);
        tmp = (int)(cos(newrot) * xoff) + (sin(newrot) * yoff);
        yoff = (int)(-sin(newrot) * xoff) + (cos(newrot) * yoff);
        xoff = tmp;
        xoff += az->map->blue[2] * SBLOCK;
        yoff += az->map->blue[1] * SBLOCK;
    }
    //on change l'origine des rayons dans le nouveau portail en fonctiond e leur entree
	if (az->side[dda->i] / SBLOCK == 6) //E S W N
    {
        if (az->map->orange[0] == 5)
        {
            dda->y += az->side[dda->i] % SBLOCK;
            //  dda->x -= 5;
        }
        if (az->map->orange[0] == 6)
        {
            dda->x += az->side[dda->i] % SBLOCK;
            //dda->y += (SBLOCK + 5);
        }
        if (az->map->orange[0] == 7)
        {
            dda->y += az->side[dda->i] % SBLOCK;
            //dda->x += (SBLOCK + 5);
        }
        if (az->map->orange[0] == 8)
        {
            dda->x += az->side[dda->i] % SBLOCK;
            //dda->y -= 5;
        }
    }
    else
    {
        if (az->map->blue[0] == 5)
        {
            dda->y += az->side[dda->i] % SBLOCK;
            //dda->x -= 5;
        }
        if (az->map->blue[0] == 6)
        {
            dda->x += az->side[dda->i] % SBLOCK;
            //dda->y += (SBLOCK + 5);
        }
        if (az->map->blue[0] == 7)
        {
            dda->y += az->side[dda->i] % SBLOCK;
            //dda->x += (SBLOCK + 5);
        }
        if (az->map->blue[0] == 8)
        {
            dda->x += az->side[dda->i] % SBLOCK;
            //dda->y -= 5;
        }
    }
    //on fait dds comme d'habitude
	dda->pasx = (dda->dx = ((int)(xoff)) - dda->x) < 0 ? -1 : 1;
    dda->pasy = (dda->dy = ((int)(yoff)) - dda->y) < 0 ? -1 : 1;
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
        /**if (dda->i == 400)
		   printf("DIST port while %d\n", (int)dda->dist);*/
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
            if ((az->map->map[dda->y / SBLOCK][dda->x / SBLOCK]) == 1 || az->map->map[dda->y / SBLOCK][dda->x / SBLOCK] == 5)
            {
                az->side[dda->i] = get_side(dda, az);
                az->shoot == 1 && dda->i == XSCREEN / 2 && tmp == 0 ? setportal(az, dda->y / SBLOCK, dda->x / SBLOCK, 6) : 0;
                az->shoot1 == 1 && dda->i == XSCREEN / 2 && tmp == 0 ? setportal(az, dda->y / SBLOCK, dda->x / SBLOCK, 7) : 0;
                az->shoot == 1 && dda->i == XSCREEN / 2 && tmp == 0 ? diffside(az, dda) : 0;
                az->shoot1 == 1 && dda->i == XSCREEN / 2 && tmp == 0? diffside(az, dda) : 0;
                dda->dist = (dda->dist * cos((dda->i - (XSCREEN / 2)) * 0.00144));
                dda->dist = (dda->dist != 0 ? (dda->dist) : 0);
                if (dda->i == 400)
                    printf("THYE TOUCHet y %d %d %d\n",  dda->x, dda->y, (dda->dist / (YSCREEN / 2)));
                az->ray[dda->i]->obs = (dda->dist / (YSCREEN / 2));
                break ;
            }
            if ((az->map->map[dda->y / SBLOCK][dda->x / SBLOCK]) == 6)
            {
                dda->i == XSCREEN / 2 ? tmp = 1 : 0;
                az->side[dda->i] = get_side(dda, az);
                //portalapply(az, dda, 1, 6);
            }
			else if(az->map->map[dda->y / SBLOCK][dda->x / SBLOCK] == 7)
            {
                dda->i == XSCREEN / 2 ? tmp = 1 : 0;
                az->side[dda->i] = get_side(dda, az);
                //portalapply(az, dda, 1, 7);
            }
        }
        //if (dda->i == 400)
		//printf("DIST port while fin %d %d\n", (int)dda->dist, az->info->range);
    }
    if (dda->dist == az->info->range)
    {
        //printf("MAXRANGE\n");
        az->ray[dda->i]->obs = dda->dist;
    }
//  printf("EXIT PORTAL \n");
}

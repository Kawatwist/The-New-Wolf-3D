/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:32:30 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/04 18:49:21 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		isvisible3(t_acz *az, t_sprite *tmp, int i)
{
	if ((((az->sdetect.sx < az->sdetect.dxf)
		&& (az->sdetect.sx >= az->sdetect.dxl))
		|| ((az->sdetect.sx >= az->sdetect.dxf)
		&& (az->sdetect.sx < az->sdetect.dxl)))
		&& (((az->sdetect.sy < az->sdetect.dyf)
		&& (az->sdetect.sy >= az->sdetect.dyl))
		|| ((az->sdetect.sy >= az->sdetect.dyf)
		&& (az->sdetect.sy < az->sdetect.dyl))))
	{
		if ((az->sdetect.sx / az->sdetect.sy - az->ray[i]->posx
			/ az->ray[i]->posy) > 0.01 || (az->sdetect.sx / az->sdetect.sy
			- az->ray[i]->posx / az->ray[i]->posy) < -0.01)
			return (0);
		return (1);
	}
	return (0);
}

int		isvisible2(t_acz *az, t_sprite *tmp, int i)
{
	if (az->sdetect.dyf < 0 && az->sdetect.dyl < 0)
	{
		if (az->sdetect.sy >= 0)
			return (0);
		if ((az->sdetect.sx / az->sdetect.sy - az->ray[i]->posx
			/ az->ray[i]->posy) > 0.01 || (az->sdetect.sx 
			/ az->sdetect.sy - az->ray[i]->posx / az->ray[i]->posy) < -0.01)
			return (0);
		if (az->sdetect.sx / az->sdetect.sy >= az->sdetect.dxl
			/ az->sdetect.dyl && az->sdetect.sx / az->sdetect.sy
			< az->sdetect.dxf / az->sdetect.dyf)
			return (1);
	}
	if (az->sdetect.dyf >= 0 && az->sdetect.dyl >= 0)
	{
		if (az->sdetect.sy < 0)
			return (0);
		if ((az->sdetect.sx / az->sdetect.sy - az->ray[i]->posx
			/ az->ray[i]->posy) > 0.01 || (az->sdetect.sx
			/ az->sdetect.sy - az->ray[i]->posx / az->ray[i]->posy) < -0.01)
			return (0);
		if (az->sdetect.sx / az->sdetect.sy >= az->sdetect.dxl
			/ az->sdetect.dyl && az->sdetect.sx / az->sdetect.sy
			< az->sdetect.dxf / az->sdetect.dyf)
			return (1);
	}
	return (isvisible3(az, tmp, i));
}

int		isvisible(t_acz *az, t_sprite *tmp, int i)
{
	az->sdetect.sx = (az->map->persox * SBLOCK) - (tmp->posx * SBLOCK);
    az->sdetect.sy = (az->map->persoy * SBLOCK) - (tmp->posy * SBLOCK);
	if (az->sdetect.dxf >= 0 && az->sdetect.dxl >= 0)
	{
		if (az->sdetect.sx < 0)
			return (0);
		if ((az->sdetect.sy / az->sdetect.sx - az->ray[i]->posy
			 / az->ray[i]->posx) > 0.01 || (az->sdetect.sy
			/ az->sdetect.sx - az->ray[i]->posy / az->ray[i]->posx) < -0.01)
			return (0);
		if (az->sdetect.sy / az->sdetect.sx < az->sdetect.dyl
			/ az->sdetect.dxl && az->sdetect.sy / az->sdetect.sx
			>= az->sdetect.dyf / az->sdetect.dxf)
			return (1);
	}
	if (az->sdetect.dxf < 0 && az->sdetect.dxl < 0)
	{
		if (az->sdetect.sx >= 0)
			return (0);
		if ((az->sdetect.sy / az->sdetect.sx - az->ray[i]->posy / az->ray[i]->posx) > 0.01
			|| (az->sdetect.sy / az->sdetect.sx - az->ray[i]->posy / az->ray[i]->posx) < -0.01)
			return (0);
		if (az->sdetect.sy / az->sdetect.sx < az->sdetect.dyl / az->sdetect.dxl
			&& az->sdetect.sy / az->sdetect.sx >= az->sdetect.dyf / az->sdetect.dxf)
			return (1);
	}
	return (isvisible2(az, tmp, i));
}

void initsurf(SDL_Rect *rect1, SDL_Rect *rect2, t_sprite *tmp, t_acz *az)
{
	//az->sdetect.sx = (az->map->persox * SBLOCK) - (tmp->posx * SBLOCK);
    //az->sdetect.sy = (az->map->persoy * SBLOCK) - (tmp->posy * SBLOCK);
	rect1->x = 0;
	rect1->y = 0;
	rect1->h = tmp->sizey;
	rect1->w = tmp->sizex;
	rect2->x = 0;
    rect2->y = (YSCREEN / 2);
    rect2->h = 30;
    rect2->w = 1;
}

void        draw_sprites(t_acz *az)
{
    t_sprite    *tmp;
    SDL_Rect    rect1;
    SDL_Rect    rect2;
    int         i;
    int         j;
	int			k;

    tmp = az->sprite;
	// printf("DRAW SPRITE\n");
    while (tmp != NULL)
    {
		i = 0;
		while (i < XSCREEN)
		{
            initsurf(&rect1, &rect2, tmp, az);
            rect1.x = 0;
            rect2.x = i;
            if (az->zbuffer[i] > tmp->dist)
            {
                rect2.h = YSCREEN / tmp->dist;
                rect2.w = XSCREEN / (tmp->dist * 2);
                rect2.x -= tmp->sizex / 2;
                rect2.y = ((YSCREEN - rect2.h) / 2) + (az->vue * 5/* * 680 / 90*/);
                if (isvisible(az, tmp, i))
                {
					/*j = -(tmp->sizex / 2);
					while (j < i + tmp->sizex / 2)
					{
						if (az->zbuffer[i + j] > tmp->dist)
							az->zbuffer[i + j] > tmp->dist;
						else
						{
							rect2.x = i + j;
							rect2.w = tmp->sizex;
							}*/
                    //A FAIRE calculer partie visible;
                    SDL_RenderCopy(az->main->rend, tmp->tex, &rect1, &rect2);
					az->zbuffer[i] = tmp->dist;
				}
			}
			i++;
		}
		tmp = tmp->next;
	}
}
/*
void		sprite_dist(t_acz *az)
{
	t_sprite *tmp;

	//printf("SPRITE DIST\n");
	tmp = az->sprite;
	while (tmp != NULL)
	{
		//tmp->dist = sqrt(pow(ft_abs((int)az->map->persox - (int)tmp->posx), 2) +  pow(ft_abs((int)az->map->persoy - (int)tmp->posy), 2)); //pythagore
		//	printf("%f %f %f %f\n", az->map->persox , tmp->posx ,  az->map->persoy , tmp->posy);
		tmp->dist = sqrt((az->map->persox - tmp->posx) * (az->map->persox - tmp->posx)
						  + (az->map->persoy - tmp->posy) * (az->map->persoy - tmp->posy));
		tmp = tmp->next;
	}
	az->sdetect.dxf = az->map->persox - az->ray[0]->posx;
	az->sdetect.dyf = az->map->persoy - az->ray[0]->posy;
	az->sdetect.dxl = az->map->persox - az->ray[XSCREEN - 1]->posx;
	az->sdetect.dyl = az->map->persoy - az->ray[XSCREEN - 1]->posy;
}
*/
/**
void		initsprite(t_sprite *sprite, int type, t_acz *az)
{
	if (type == 1)
	{
		sprite->sizex = 64;
		sprite->sizey = 64;
		sprite->tex = az->game->door;
	}
	if (type == 2)
    {
        sprite->sizex = 64;
        sprite->sizey = 64;
        sprite->tex = az->game->enemy;
    }
}

t_sprite	*create_sprite (double posx, double posy, int type, t_acz *az)
{
	t_sprite *new;

	//printf("CREATE SPRITE\n");
	if(!(new = (t_sprite*)malloc(sizeof(t_sprite))))
		return (NULL);
	new->posx = posx;
	new->posy = posy;
	new->next = NULL;
	initsprite(new, type, az);
	return (new);
}

void		add_sprite(t_sprite **list, t_sprite *new)
{
	t_sprite *tmp;

	//printf("ADD SPRITE\n");
	if (list == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	load_sprites(t_acz *az)
{
	int	i;
	int j;

	//printf("LOAD_SPRITES\n");
	az->sprite = NULL;
	i = 0;
	while (i < 60)
	{
		j = 0;
		while (j < 60)
		{
			if (az->map->map[i][j] == 20)
				add_sprite(&(az->sprite), (create_sprite(j + 0.5, i + 0.5, 1, az)));
			if (az->map->map[i][j] == 21)
				add_sprite(&(az->sprite), (create_sprite(j + 0.5, i + 0.5, 2, az)));
			j++;
		}
		i++;
	}
}
**/

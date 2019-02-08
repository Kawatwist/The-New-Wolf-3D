/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:54:30 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/06 19:15:17 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	interraction(t_win *wn)
{
	wn->map[(int)((wn->perso->posy) * wn->y / wn->yscreen)][(int)((wn->perso->posx) * wn->x / wn->xscreen)] == 4 ? wn->perso->inv->key += 1 : 0; 
	wn->map[(int)((wn->perso->posy) * wn->y / wn->yscreen)][(int)((wn->perso->posx) * wn->x / wn->xscreen)] == 4 ? wn->map[(int)((wn->perso->posy) * wn->y / wn->yscreen)][(int)((wn->perso->posx) * wn->x / wn->xscreen)] = 1 : 0; 
}

void	movement(t_win *wn, int flags)
{
	float	save;

	if (flags == SDLK_a || flags == SDLK_d)
	{
		wn->movex = flags == SDLK_d ? -2 : 2;
		wn->movey = 0;
	}
	else
	{
		wn->movex = 0;
		wn->movey = flags == SDLK_s ? -2 : 2;
	}
	save = (wn->movex * cos(wn->angx - (15 * 0.017433))) + (wn->movey * -sin(wn->angx - (15 * 0.017433)));
	wn->movey = (wn->movex * sin(wn->angx - (15 * 0.017433))) + (wn->movey * cos(wn->angx - (15 * 0.017433)));
	wn->movex = save;
	wn->perso->posx += wn->movex;
	wn->perso->posy += wn->movey;
	checkcollision(wn);
}

void	checkcollision(t_win *wn)
{
	int	into;
	int	x;
	int y;

	x = (int)(wn->perso->posx * wn->x / wn->xscreen);
	y = (int)(wn->perso->posy * wn->y / wn->yscreen);
	into = wn->map[y][x];
	if (into == BOX)
	{

		wn->perso->posx -= wn->movex * 2;
		wn->perso->posy -= wn->movey * 2;
	}
	else if (into == DOOR)
	{
		if (wn->perso->inv->key > 0)
		{
			wn->perso->inv->key -= 1;
			wn->map[y][x] = 1;
		}
		else
		{
			wn->perso->posx -= wn->movex;
			wn->perso->posy -= wn->movey;
		}
	}
	interraction(wn);
}

void	input(t_win *wn)
{
	static int	up = 0;
	static int	left = 0;
	static int	rotx = 0;

	int getx;
	int gety;
	if (wn->game->ev.key.keysym.sym == SDLK_TAB && wn->game->ev.type == SDL_KEYDOWN)
		wn->pause *= -1;
	if (wn->pause == 1)
	{
		SDL_SetRelativeMouseMode(wn->pause);
		SDL_GetMouseState(&getx, &gety);
		getx -= wn->xscreen / 2;
		wn->angx += getx * 0.00008;
	}
	(wn->game->ev.key.keysym.sym == SDLK_a && wn->game->ev.type == SDL_KEYDOWN ? left = 1 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_d && wn->game->ev.type == SDL_KEYDOWN ? left = -1 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_w && wn->game->ev.type == SDL_KEYDOWN ? up = 1 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_s && wn->game->ev.type == SDL_KEYDOWN ? up = -1 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_w && wn->game->ev.type == SDL_KEYUP ? up = 0 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_s && wn->game->ev.type == SDL_KEYUP ? up = 0 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_a && wn->game->ev.type == SDL_KEYUP ? left = 0 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_d && wn->game->ev.type == SDL_KEYUP ? left = 0 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_LEFT && wn->game->ev.type == SDL_KEYDOWN ? rotx = 1 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_RIGHT && wn->game->ev.type == SDL_KEYDOWN ? rotx = -1 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_LEFT && wn->game->ev.type == SDL_KEYUP ? rotx = 0 : 0);
	(wn->game->ev.key.keysym.sym == SDLK_RIGHT && wn->game->ev.type == SDL_KEYUP ? rotx = 0 : 0);
	if (wn->game->ev.type == SDL_KEYDOWN)
	{
		wn->game->last_input = wn->game->ev.key.keysym.sym;
		wn->game->ev.key.keysym.sym == SDLK_ESCAPE ? stop_exec("Esc\n") : 0;
		wn->game->ev.key.keysym.sym == SDLK_KP_PLUS ? wn->perso->range += 10 : 0;
		wn->game->ev.key.keysym.sym == SDLK_KP_MINUS ? wn->perso->range -= 10 : 0;
	}
	rotx == 1 ? wn->angx += -0.04 : 0;
	rotx == -1 ? wn->angx += 0.04 : 0;
	up == 1 ? movement(wn, SDLK_w) : 0;
	up == -1 ? movement(wn, SDLK_s) : 0;
	left == 1 ? movement(wn, SDLK_a) : 0;
	left == -1 ? movement(wn, SDLK_d) : 0;
//	if (wn->game->ev.key.keysym.sym == SDLK_RETURN)
//		initedit(&wn);
	if (wn->dbug == 1 && wn->debug->ev.type == SDL_KEYDOWN)
		wn->debug->ev.key.keysym.sym == SDLK_ESCAPE ? stop_exec("Esc\n") : 0;
//	wn->game->ev.key.keysym.sym == SDLK_e ? interraction(wn) : 0;
}

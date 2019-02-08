/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:16:52 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/06 19:09:46 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	initmenu(t_win *wn, t_menu *menu)
{
	menu->mode = 0;
	menu->surface = IMG_Load("./img/bg3.png");
	menu->surface == NULL ? stop_exec("bg not load\n") : 0;
	menu->bg = SDL_CreateTextureFromSurface(wn->game->rend, menu->surface);
	SDL_FreeSurface(wn->menu->surface);
	menu->surface = IMG_Load("./img/arrow.png");
	menu->surface == NULL ? stop_exec("arrow not load\n") : 0;
	menu->arrow = SDL_CreateTextureFromSurface(wn->game->rend, menu->surface);
	setuprect(&menu->pos, 0, wn);
	menu->info.x = 0;
	menu->info.y = 0;
	menu->info.w = 200;
	menu->info.h = 200;
}

void	initgame(t_win **wn)
{
	int i;

	(*wn)->perso->vuex = (*wn)->perso->posx + (*wn)->perso->range;
	(*wn)->perso->vuey = (*wn)->perso->posy + (*wn)->perso->range;
	(*wn)->perso->vuex > (*wn)->xscreen ? (*wn)->perso->vuex = (*wn)->xscreen : 0;
	(*wn)->perso->vuey > (*wn)->yscreen ? (*wn)->perso->vuey = (*wn)->yscreen : 0;
	(*wn)->game->win = SDL_GetWindowSurface((*wn)->game->wind);
	i = -1;
	while (++i < FOV)
		initvue((*wn), i);
}

void	initinv(t_inventory **inv)
{
	(*inv)->key = 0;
	(*inv)->ammo = 0;
	(*inv)->primary = 0;
	(*inv)->second = 0;
}

void	initwn(t_win **wn)
{
	if (!((*wn) = (t_win *)malloc(sizeof(t_win))))
		stop_exec("Init Wn\n");
	if (!((*wn)->game = (t_game *)malloc(sizeof(t_game))))
		stop_exec("Init game\n");
	if (!((*wn)->perso = (t_perso*)malloc(sizeof(t_perso))))
		stop_exec("Init perso\n");
	if (!((*wn)->perso->vue = (t_point*)malloc(sizeof(t_point) * FOV)))
		stop_exec("Init point\n");
	if (!((*wn)->perso->inv = (t_inventory*)malloc(sizeof(t_inventory))))
		stop_exec("Init inventory\n");
	if (!((*wn)->perso->collision = (t_mat*)malloc(sizeof(t_mat) * FOV)))
		stop_exec("Init mat collision\n");
	if (!((*wn)->matrice = (t_mat*)malloc(sizeof(t_mat))))
		stop_exec("Init mat\n");
	if (!((*wn)->edit = (t_editor*)malloc(sizeof(t_editor))))
		stop_exec("Init editor\n");
	if (!((*wn)->menu = (t_menu*)malloc(sizeof(t_menu))))
		stop_exec("Init menu\n");
	(*wn)->editor = 0;
	(*wn)->debug = 0;
	(*wn)->angx = 0;
	(*wn)->angy = 0;
	(*wn)->angz = 0;
	(*wn)->xscreen = 800;
	(*wn)->yscreen = 800;
	(*wn)->edit->xscreen = 800;
	(*wn)->edit->yscreen = 800;
	(*wn)->perso->range = 500;
	(*wn)->game->last_input = 0;
	(*wn)->pause = -1;
	initmatrice((*wn)->perso->collision);
	initinv(&(*wn)->perso->inv);
}

void	initedit(t_win **wn)
{
	int		actif;

	actif = 1;
	(*wn)->edit->wind = SDL_CreateWindow("Map Editor", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, (*wn)->edit->xscreen, (*wn)->edit->yscreen, SDL_WINDOW_SHOWN);
	(*wn)->edit->rend = SDL_CreateRenderer((*wn)->edit->wind, -1 , SDL_RENDERER_PRESENTVSYNC);
	setedit(*wn);
	while (actif)
	{	
		SDL_PollEvent(&(*wn)->edit->ev);
		if ((*wn)->edit->ev.key.keysym.sym == SDLK_SPACE)
			actif = 0;
		if ((*wn)->edit->ev.key.keysym.sym == SDLK_s)
			save(*wn);
		if ((*wn)->edit->ev.button.state == SDL_PRESSED)
			edit(*wn);
		SDL_UpdateWindowSurface((*wn)->edit->wind);
	}
	SDL_DestroyWindow((*wn)->edit->wind);
}

void	initsdl(t_win **wn)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	(*wn)->game->wind = SDL_CreateWindow("Wolf3D", (*wn)->xscreen,
			SDL_WINDOWPOS_CENTERED, (*wn)->xscreen, (*wn)->yscreen, SDL_WINDOW_SHOWN);
	(*wn)->game->rend = SDL_CreateRenderer((*wn)->game->wind,
			-1, SDL_RENDERER_PRESENTVSYNC);
	SDL_UpdateWindowSurface((*wn)->game->wind);
	if ((*wn)->dbug == 1)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		IMG_Init(IMG_INIT_PNG);
		(*wn)->debug->wind = SDL_CreateWindow("Wolf2D", 0,
				SDL_WINDOWPOS_CENTERED, (*wn)->xscreen, (*wn)->yscreen, SDL_WINDOW_SHOWN);
		(*wn)->debug->rend = SDL_CreateRenderer((*wn)->debug->wind,
				-1, SDL_RENDERER_PRESENTVSYNC);
		SDL_UpdateWindowSurface((*wn)->debug->wind);
	}
}

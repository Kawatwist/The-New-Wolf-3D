/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:14:27 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/06 20:05:54 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	stop_exec(void	*str)
{
	ft_putstr(str);
	exit(0);
}

void	menu(t_win *wn, t_menu *menu)
{
	int		run;

	run = 1;
	initmenu(wn, menu);
	while (run)
	{
		menu->info.w = 100;
		menu->info.h = 100;
		menu->mode == 1 || menu->mode == 3 ? menu->info.x = 350 : 0;
		menu->mode == 0 || menu->mode == 2 ? menu->info.x = 25 : 0;
		menu->mode == 0 || menu->mode == 1 ? menu->info.y = 330 : 0;
		menu->mode == 2 || menu->mode == 3 ? menu->info.y = 550 : 0;
		SDL_PollEvent(&menu->ev);
		menu->mode < 3 && menu->ev.key.keysym.sym == SDLK_UP && menu->ev.type == SDL_KEYDOWN? menu->mode += 1 : 0;
		menu->mode > 0 && menu->ev.key.keysym.sym == SDLK_DOWN && menu->ev.type == SDL_KEYDOWN? menu->mode -= 1 : 0;
		menu->ev.key.keysym.sym == SDLK_ESCAPE ? stop_exec("Esc\n") : 0;
		if (menu->ev.key.keysym.sym == SDLK_RETURN)
		{
			menu->mode == 0 ? run = 0 : 0;
			menu->mode == 2 ? initedit(&wn) : 0;
			menu->mode == 3 ? stop_exec("Starfoulla\n") : 0;
		}
		SDL_RenderCopy(wn->game->rend, menu->bg, NULL, &menu->pos);
		SDL_RenderCopy(wn->game->rend, menu->arrow, NULL, &menu->info);
		SDL_RenderPresent(wn->game->rend);
		SDL_UpdateWindowSurface(wn->game->wind);
		SDL_Delay(5000 / FPS);
	}
}

int 	main(int argc, char **argv)
{
	t_win	*wn;
	Uint32	tmp;
	int		i;
	int		Turn;

	i = 0;
	if (argc < 2 || argc > 3)
		stop_exec("Usage : ./wolf3d [source_file]\n");
	Turn = 1;
	initwn(&wn);
	if (argc == 3 && ft_strcmp(argv[2], "debug") == 0)
	{
		wn->dbug = 1;
		if (!(wn->debug = (t_debug *)malloc(sizeof(t_debug))))
			stop_exec("Init game\n");
	}
	parsemap(wn, argv[1]);
	initsdl(&wn);
	initgame(&wn);	
	menu(wn, wn->menu);
	while (Turn)
	{
		wn->time = SDL_GetTicks();
		SDL_PumpEvents();
		SDL_PollEvent(&wn->game->ev);
		input(wn);
		rotatematrice(wn);
		printscreen(wn);
		if (wn->map[(int)(wn->perso->posy) * wn->y / wn->yscreen][(int)(wn->perso->posx) * wn->x / wn->xscreen] == 2)
		{
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "YOU WIN\n", "AH BAH GG !\n", wn->game->wind);
			stop_exec("GG\n");
		}
		wn->time2 = SDL_GetTicks();
		tmp = wn->time2 - wn->time;
		if (tmp < 1000 / FPS)
		{	
			SDL_Delay((1000 / FPS) - tmp);
		}
	}
	return (0);
}

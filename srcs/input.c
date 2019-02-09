/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/09 16:39:00 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		collision(t_acz *az)
{
	if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 1)
	{
		az->map->persox -= az->map->lastmovx;
		az->map->persoy -= az->map->lastmovy;
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 4)
	{
		az->inv->key += 1;
		az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
	}
}

static void	input_menu(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_DOWN] && az->menu->mode < 3 ? az->menu->mode += 1 : 0;
	state[SDL_SCANCODE_UP] && az->menu->mode > 0 ? az->menu->mode -= 1 : 0;
	if (state[SDL_SCANCODE_RETURN])
	{
		Mix_PlayChannel(-1, az->main->effect, 0);
		az->menu->mode == 0 ? az->interface = 1 : 0;
		az->menu->mode == 1 ? az->interface = 2 : 0;
		az->menu->mode == 2 ? az->interface = 3 : 0;
		az->menu->mode == 3 ? stop_exec("Goodbye & see you later\n") : 0;
	}
	printf("Menu choice\n");
	state[SDL_SCANCODE_ESCAPE] ? stop_exec("Escape\n") : 0;
}

static void	rotate_perso(t_acz *az)
{
	int 	current;
	double	ang;

	current = 0;
	while (current < XSCREEN)
	{
		ang = (current * 0.00144) + az->info->angle;
		az->ray[current]->posx = (az->info->range * cos(ang)) + (az->info->range * -sin(ang)) + (az->map->persox);
		az->ray[current]->posy = (az->info->range * sin(ang)) + (az->info->range * cos(ang)) + (az->map->persoy);
		current++;
	}
}

static void	mouvement(t_acz *az, int move)
{
	double tmp;

	if (move == 0 || move == 2)
	{
		az->map->lastmovx = 0;
		az->map->lastmovy = (move == 2 ? 0.07 : -0.07);
	}
	else
	{
		az->map->lastmovx = (move == 3 ? 0.07 : -0.07);
		az->map->lastmovy = 0;
	}
	tmp = (az->map->lastmovx * cos(az->info->angle)) + (az->map->lastmovy * -sin(az->info->angle));
	az->map->lastmovy = (az->map->lastmovx * sin(az->info->angle)) + (az->map->lastmovy * cos(az->info->angle));
	az->map->lastmovx = tmp;
	az->map->persox += az->map->lastmovx;
	az->map->persoy += az->map->lastmovy;
	collision(az);
}

static void	input_game(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_A] ? mouvement(az, 3) : 0;
	state[SDL_SCANCODE_D] ? mouvement(az, 1) : 0;
	state[SDL_SCANCODE_W] ? mouvement(az, 2) : 0;
	state[SDL_SCANCODE_S] ? mouvement(az, 0) : 0;
	state[SDL_SCANCODE_LEFT] ? az->info->angle -= 0.07 : 0;
	state[SDL_SCANCODE_RIGHT] ? az->info->angle += 0.07 : 0;
	state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
	rotate_perso(az);
}

static void	input_option(Uint8 *state, t_acz *az)
{
	printf("Option\n");
	state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
}

static void	input_editor(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_UP] && !state[SDL_SCANCODE_DOWN]  && az->info->editx > 9 ? az->info->editx -= 10 : 0;
	state[SDL_SCANCODE_DOWN] && !state[SDL_SCANCODE_UP]  && az->info->editx < 590 ? az->info->editx += 10 : 0;
	state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT]  && az->info->edity > 9 ? az->info->edity -= 10 : 0;
	state[SDL_SCANCODE_RIGHT] && !state[SDL_SCANCODE_LEFT]  && az->info->edity < 590 ? az->info->edity += 10 : 0;
	state[SDL_SCANCODE_KP_0] ? az->info->editbrush = 0 : 0;
	state[SDL_SCANCODE_KP_1] ? az->info->editbrush = 1 : 0;
	state[SDL_SCANCODE_KP_2] ? az->info->editbrush = 2 : 0;
	state[SDL_SCANCODE_KP_3] ? az->info->editbrush = 3 : 0;
	state[SDL_SCANCODE_KP_4] ? az->info->editbrush = 4 : 0;
	state[SDL_SCANCODE_KP_5] ? az->info->editbrush = 5 : 0;
	if (state[SDL_SCANCODE_RETURN])
		az->info->editmap[az->info->edity / 10][az->info->editx / 10] = az->info->editbrush;
	state[SDL_SCANCODE_S] ? save_map(az) : 0;
}

void		input(t_acz *az)
{
	Uint8	*state;

	SDL_PollEvent(&az->ev);
	state = (Uint8*)SDL_GetKeyboardState(NULL);
	az->twodactif = (state[SDL_SCANCODE_M] ? 1 : 0);
	//az->twodactif = 1;
		if (az->interface == 0)
			input_menu(state, az);
		else if (az->interface == 1)
			input_game(state, az);
		else if (az->interface == 2)
			input_option(state, az);
		else
			input_editor(state, az);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 11:25:21 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
	state[SDL_SCANCODE_ESCAPE] ? stop_exec("Escape\n") : 0;
}

static void	input_option(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_H] ? az->interface = 4 : 0;
	state[SDL_SCANCODE_ESCAPE] ? SDL_Delay(500) : 0;
}

static void	input_control(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 2 : 0;
}

void		input(t_acz *az)
{
	Uint8	*state;

	SDL_PollEvent(&az->ev);
	state = (Uint8*)SDL_GetKeyboardState(NULL);
	az->twodactif = (state[SDL_SCANCODE_TAB] ? 1 : 0);
	state[SDL_SCANCODE_M] ? az->mute = 1 : 0;
	state[SDL_SCANCODE_H] ? az->mouse *= -1 : 0;
	mouseinput(az);
	if (az->interface == 0)
	{
		state[SDL_SCANCODE_L] ? loadeditoplay(az) : 0;
		input_menu(state, az);
	}
	else if (az->interface == 1)
		input_game(state, az);
	else if (az->interface == 2)
		input_option(state, az);
	else if (az->interface == 3)
		input_editor(state, az);
	else if (az->interface == 4)
		input_control(state, az);
}

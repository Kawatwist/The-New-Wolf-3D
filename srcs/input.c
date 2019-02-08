/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/08 17:08:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	collision(t_acz *az)
{

}

void	input(t_acz *az)
{
	Uint8	*state;

	SDL_PollEvent(&az->ev);
	state = (Uint8*)SDL_GetKeyboardState(NULL);
	state[SDL_SCANCODE_ESCAPE] ? stop_exec("Escape\n") : 0;
	az->twodactif = (state[SDL_SCANCODE_M] ? 1 : 0);
	if (az->interface == 0)
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
	}
	else if (az->interface == 1)
	{
		state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
		printf("Game running\n");
	}
	else if (az->interface == 2)
	{
		state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
		printf("Option\n");
	}
	else
	{
		state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
		printf("Editor\n");
	}
}

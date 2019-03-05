/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 12:56:16 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	editorinput(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? SDL_Delay(500) : 0;
	state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_UP] && !state[SDL_SCANCODE_DOWN]
		&& az->info->edity > 9 ? az->info->edity -= 10 : 0;
	state[SDL_SCANCODE_DOWN] && !state[SDL_SCANCODE_UP]
		&& az->info->edity < 590 ? az->info->edity += 10 : 0;
	state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT]
		&& az->info->editx > 9 ? az->info->editx -= 10 : 0;
	state[SDL_SCANCODE_RIGHT] && !state[SDL_SCANCODE_LEFT]
		&& az->info->editx < 590 ? az->info->editx += 10 : 0;
	state[SDL_SCANCODE_KP_0] ? az->info->editbrush = 0 : 0;
	state[SDL_SCANCODE_KP_1] ? az->info->editbrush = 1 : 0;
	state[SDL_SCANCODE_KP_2] ? az->info->editbrush = 2 : 0;
	state[SDL_SCANCODE_KP_3] ? az->info->editbrush = 3 : 0;
	state[SDL_SCANCODE_KP_4] ? az->info->editbrush = 4 : 0;
	state[SDL_SCANCODE_KP_5] ? az->info->editbrush = 5 : 0;
	state[SDL_SCANCODE_KP_6] ? az->info->editbrush = 8 : 0;
	state[SDL_SCANCODE_KP_7] ? az->info->editbrush = 9 : 0;
	state[SDL_SCANCODE_KP_8] ? az->info->editbrush = ENEMY : 0;
	state[SDL_SCANCODE_C] ? az->info->selectx =
		az->info->editx / 10 : 0;
}

void		input_editor(Uint8 *state, t_acz *az)
{
	editorinput(state, az);
	state[SDL_SCANCODE_V] ? parseselect(az) : 0;
	state[SDL_SCANCODE_L] ? loadplaytoedit(az) : 0;
	state[SDL_SCANCODE_R] ? loadedittoreset(az) : 0;
	state[SDL_SCANCODE_P] ? printselect(az) : 0;
	if (state[SDL_SCANCODE_RETURN])
		az->info->editmap[az->info->edity / 10][az->info->editx / 10] =
			az->info->editbrush;
	state[SDL_SCANCODE_S] ? save_map(az) : 0;
}

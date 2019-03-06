/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 11:08:38 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		game_touche(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_A] ? mouvement(az, 3) : 0;
	state[SDL_SCANCODE_D] ? mouvement(az, 1) : 0;
	state[SDL_SCANCODE_W] ? mouvement(az, 2) : 0;
	state[SDL_SCANCODE_S] ? mouvement(az, 0) : 0;
	state[SDL_SCANCODE_LEFT] ? az->info->angle -= 0.07 : 0;
	state[SDL_SCANCODE_RIGHT] ? az->info->angle += 0.07 : 0;
	state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? SDL_Delay(500) : 0;
	state[SDL_SCANCODE_1] ? az->inv->rifle = 0 : 0;
	state[SDL_SCANCODE_2] ? az->inv->rifle = 1 : 0;
	state[SDL_SCANCODE_3] ? az->inv->rifle = 2 : 0;
	state[SDL_SCANCODE_4] ? az->inv->rifle = 3 : 0;
	state[SDL_SCANCODE_5] ? az->inv->rifle = 4 : 0;
	state[SDL_SCANCODE_7] ? az->mode += 1 : 0;
	state[SDL_SCANCODE_9] ? az->mode -= 1 : 0;
	state[SDL_SCANCODE_O] ? az->vue += 1 : 0;
	state[SDL_SCANCODE_P] ? az->vue -= 1 : 0;
	state[SDL_SCANCODE_KP_PLUS] && az->fov < 0.003 ?
		az->fov += 0.0001 : 0;
	state[SDL_SCANCODE_KP_MINUS] && az->fov > 0.0005 ?
		az->fov -= 0.0001 : 0;
}

void		input_game(Uint8 *state, t_acz *az)
{
	game_touche(state, az);
	if (az->jump == 0 && !state[SDL_SCANCODE_LSHIFT])
	{
		state[SDL_SCANCODE_SPACE] ? az->jump += 1 : 0;
		state[SDL_SCANCODE_SPACE] ? az->acl = 35 : 0;
	}
	else if (az->jump != 0)
	{
		az->jump != 0 ? az->jump += 1 : 0;
		az->jump != 0 && az->mode > 0 ? az->jump = 0 : 0;
		az->mode > 0 ? az->acl = 0 : 0;
		az->mode > 0 ? az->mode = 0 : 0;
	}
	else
	{
		state[SDL_SCANCODE_LSHIFT] ? az->speed = 0.5 : 0;
		state[SDL_SCANCODE_LSHIFT] ? az->inv->rifle = 3 : 1;
		az->mode = state[SDL_SCANCODE_LSHIFT] ? (SBLOCK * 7) : 0;
		!state[SDL_SCANCODE_LSHIFT] ? az->speed = 2 : 0;
	}
	if (state[SDL_SCANCODE_1] || state[SDL_SCANCODE_2])
		az->inv->frame = 0;
	rotate_perso(az);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:23:49 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/17 18:07:32 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	running(t_acz **az)
{
	Uint8	difftime;

	(*az)->interface = 0;
	(*az)->menu->mode = 0;
	(*az)->twodactif = 0;
	(*az)->main->song = Mix_LoadMUS("texture/Dee.wav");
	Mix_PlayMusic((*az)->main->song, -1);
	while (TRUE)
	{
		(*az)->mute == 1 ? Mix_HaltMusic() : 0;
		(*az)->time = SDL_GetTicks();
		input(*az);
		(*az)->twodactif == 1 ? map(*az) : print(*az);
		(*az)->time2 = SDL_GetTicks();
		difftime = (*az)->time2 - (*az)->time;
		difftime < 1000 / 60 ? SDL_Delay((1000 / 60) - difftime) : 0;
	}
}

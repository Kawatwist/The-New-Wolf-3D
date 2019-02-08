/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:23:49 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/08 17:09:46 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	running(t_acz **az)
{
	Uint8	difftime;

	(*az)->interface = 0;
	(*az)->menu->mode = 0;
	(*az)->twodactif = 0;
	(*az)->main->song = Mix_LoadMUS("texture/song.wav");
	Mix_PlayMusic((*az)->main->song, -1);
	while (TRUE)
	{
		(*az)->time = SDL_GetTicks();
		input(*az);
		print(*az);
		(*az)->twodactif == 1 ? map(*az): 0;
		(*az)->time2 = SDL_GetTicks();
		difftime = (*az)->time2 - (*az)->time;
		if ((*az)->interface == 1)
			difftime < 1000 / 60 ? SDL_Delay((1000 / 60) - difftime) : 0;
		else
			difftime < 1000 / 10 ? SDL_Delay((1000 / 10) - difftime) : 0;
	}
}

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
}

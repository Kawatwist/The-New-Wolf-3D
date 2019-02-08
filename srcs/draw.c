/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:38:58 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/05 16:12:15 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	setrect(t_win **wn, int x, int y, int value)
{
	(*wn)->debug->obs.x = (x * (*wn)->xscreen) / (*wn)->x;
	(*wn)->debug->obs.y = (y * (*wn)->yscreen) / (*wn)->y;
	(*wn)->debug->obs.w = (*wn)->xscreen / (*wn)->x;
	(*wn)->debug->obs.h = (*wn)->yscreen / (*wn)->y;
	value == 0 ? SDL_SetRenderDrawColor((*wn)->debug->rend, 0, 0, 0, SDL_ALPHA_OPAQUE) : 0;
	value == 2 ? SDL_SetRenderDrawColor((*wn)->debug->rend, 120, 0, 120, SDL_ALPHA_OPAQUE) : 0;
	value == 4 ? SDL_SetRenderDrawColor((*wn)->debug->rend, 200, 200, 0, SDL_ALPHA_OPAQUE) : 0;
	value == 5 ? SDL_SetRenderDrawColor((*wn)->debug->rend, 0, 120, 0, SDL_ALPHA_OPAQUE) : 0;
	SDL_RenderFillRect((*wn)->debug->rend, &(*wn)->debug->obs);
}

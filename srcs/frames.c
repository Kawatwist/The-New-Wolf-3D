/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:40:18 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/25 16:11:50 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	akframe(t_acz *az)
{
	SDL_Rect	org;
	SDL_Rect	pos;

	org.x = ((az->inv->akframe % 8) * 800);
	org.y = ((az->inv->akframe / 8) * 600);
	org.w = 800;
	org.h = 600;
	pos.x = 0;
	pos.y = 0;
	pos.w = 800;
	pos.h = 600;
	SDL_RenderCopy(az->main->rend, az->game->ak, &org, &pos);
}

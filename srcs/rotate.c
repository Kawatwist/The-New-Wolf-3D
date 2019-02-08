/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:13:19 by lomasse           #+#    #+#             */
/*   Updated: 2019/01/27 17:00:02 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	rotatexy(t_win *wn, t_mat *b)
{
	b->mt[0][0] = cos(wn->angx);
	b->mt[0][1] = -sin(wn->angx);
	b->mt[1][0] = sin(wn->angx);
	b->mt[1][1] = cos(wn->angx);
}

void	rotatexz(t_win *wn, t_mat *b)
{
	b->mt[0][0] = cos(wn->angz);
	b->mt[0][2] = -sin(wn->angz);
	b->mt[2][0] = sin(wn->angz);
	b->mt[2][2] = cos(wn->angz);
}

void	rotateyz(t_win *wn, t_mat *b)
{
	b->mt[1][0] = cos(wn->angy);
	b->mt[1][1] = -sin(wn->angy);
	b->mt[2][0] = sin(wn->angy);
	b->mt[2][1] = cos(wn->angy);
}

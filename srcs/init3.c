/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:51:54 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 09:59:32 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	initmain(t_acz *az)
{
	az->main->window = NULL;
	az->main->rend = NULL;
	az->main->tbg = NULL;
	az->main->tother = NULL;
	az->main->sbg = NULL;
	az->main->sother = NULL;
	az->main->effect = NULL;
	az->main->portal1 = NULL;
	az->main->portal2 = NULL;
}

void	initmenu(t_acz *az)
{
	az->menu->background = NULL;
	az->menu->choices = NULL;
	az->menu->edit = NULL;
	az->menu->bg = NULL;
	az->menu->control = NULL;
	az->menu->editor = NULL;
	az->menu->select = NULL;
	az->menu->choice = NULL;
}

void	initoption(t_acz *az)
{
	az->option->background = NULL;
	az->option->choices = NULL;
	az->option->edit = NULL;
	az->option->bg = NULL;
	az->option->control = NULL;
	az->option->editor = NULL;
	az->option->select = NULL;
	az->option->choice = NULL;
}

void	initgame(t_acz *az)
{
	az->game->sky = NULL;
	az->game->ground = NULL;
	az->game->hud = NULL;
	az->game->compas = NULL;
	az->game->gun = NULL;
	az->game->ak = NULL;
	az->game->sword = NULL;
	az->game->portal1 = NULL;
	az->game->portal2 = NULL;
	az->game->health = NULL;
	az->game->shield = NULL;
	az->game->nwall = NULL;
	az->game->swall = NULL;
	az->game->ewall = NULL;
	az->game->wwall = NULL;
	az->game->door = NULL;
	az->game->filler = NULL;
	az->game->enemy = NULL;
	az->game->ssky = NULL;
	az->game->sground = NULL;
}

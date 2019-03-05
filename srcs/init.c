/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:40:44 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 20:16:38 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		call_init2(t_acz *az)
{
	az->mouse = 1;
	az->acl = 1;
	az->mode = 1;
	az->vue = 0;
	az->jump = 0;
	az->speed = 1;
	az->sensi = 0.0015;
	az->wheelup = 0;
	az->wheeldown = 0;
	az->map->nbenemy = 0;
	az->map->map = NULL;
	az->map->orange[0] = 0;
	az->map->blue[0] = 0;
	az->name_save = ft_strdup("./save/map0");
}

static void		setinit(t_acz *az)
{
	initmain(az);
	az->map->map = NULL;
	az->info->selmap = NULL;
	initmenu(az);
	initoption(az);
	initgame(az);
}

static void		call_init(t_acz *az)
{
	setinit(az);
	init_info(az->info);
	init_sdl(az);
	initeditmap(az->info->editmap);
	initray(az);
	initinv(az);
	loadmenu(az);
	loadoption(az);
	loadedit(az);
	loadgame(az);
	az->interface = 0;
	az->mute = -1;
	az->mouse = 1;
	az->fullscreen = -1;
	az->hud = 1;
	az->fx = -1;
	call_init2(az);
}

void			initialization(t_acz **az)
{
	int	i;

	((*az) = (t_acz *)malloc(sizeof(t_acz))) == NULL ?
		stop_exec("Dosnt malloc az struct\n", (*az)) : 0;
	((*az)->main = ft_memalloc(sizeof(t_window))) == NULL ?
		stop_exec("Dosnt malloc main window struct\n", (*az)) : 0;
	((*az)->map = ft_memalloc(sizeof(t_map))) == NULL ?
		stop_exec("Dosnt malloc map struct\n", (*az)) : 0;
	((*az)->inv = ft_memalloc(sizeof(t_inv))) == NULL ?
		stop_exec("Dosnt malloc inv struct\n", (*az)) : 0;
	i = -1;
	while (++i < 800)
		((*az)->ray[i] = (t_ray *)malloc(sizeof(t_ray))) == NULL ?
			stop_exec("Dosnt malloc ray struct\n", (*az)) : 0;
	((*az)->menu = (t_menu *)malloc(sizeof(t_menu))) == NULL ?
		stop_exec("Dosnt malloc menu struct\n", (*az)) : 0;
	((*az)->option = (t_menu *)malloc(sizeof(t_menu))) == NULL ?
		stop_exec("Dosnt malloc option struct\n", (*az)) : 0;
	((*az)->info = (t_info *)malloc(sizeof(t_info))) == NULL ?
		stop_exec("Dosnt malloc info struct\n", (*az)) : 0;
	((*az)->game = (t_game *)malloc(sizeof(t_game))) == NULL ?
		stop_exec("Dosnt malloc game struct\n", (*az)) : 0;
	call_init(*az);
}

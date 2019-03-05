/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:40:44 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 17:40:21 by lomasse          ###   ########.fr       */
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
	az->map->enemy = NULL;
	az->map->map = NULL;
	az->map->orange[0] = 0;
	az->map->blue[0] = 0;
	az->name_save = ft_strdup("./save/map0");
}

static void		call_init(t_acz *az)
{
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
		stop_exec("Dosnt malloc az struct\n") : 0;
	((*az)->main = (t_window *)malloc(sizeof(t_window))) == NULL ?
		stop_exec("Dosnt malloc main window struct\n") : 0;
	((*az)->map = (t_map *)malloc(sizeof(t_map))) == NULL ?
		stop_exec("Dosnt malloc map struct\n") : 0;
	((*az)->inv = (t_inv *)malloc(sizeof(t_inv))) == NULL ?
		stop_exec("Dosnt malloc inv struct\n") : 0;
	i = -1;
	while (++i < 800)
		((*az)->ray[i] = (t_ray *)malloc(sizeof(t_ray))) == NULL ?
			stop_exec("Dosnt malloc ray struct\n") : 0;
	((*az)->menu = (t_menu *)malloc(sizeof(t_menu))) == NULL ?
		stop_exec("Dosnt malloc menu struct\n") : 0;
	((*az)->option = (t_menu *)malloc(sizeof(t_menu))) == NULL ?
		stop_exec("Dosnt malloc option struct\n") : 0;
	((*az)->info = (t_info *)malloc(sizeof(t_info))) == NULL ?
		stop_exec("Dosnt malloc info struct\n") : 0;
	((*az)->game = (t_game *)malloc(sizeof(t_game))) == NULL ?
		stop_exec("Dosnt malloc game struct\n") : 0;
	call_init(*az);
}

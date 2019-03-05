/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadingedit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:31:38 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 18:38:11 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	parseloadedit(t_acz *az)
{
	int i;
	int j;

	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
		{
			az->map->map[j][i] = az->info->editmap[j][i];
			az->info->editmap[j][i] == 2 ? az->map->persox = i : 0;
			az->info->editmap[j][i] == 2 ? az->map->persoy = j : 0;
		}
	}
}

void	loadeditoplay(t_acz *az)
{
	int i;
	int j;

	j = -1;
	if (az->map->map != NULL)
	{
		while (++j < az->info->y)
			az->map->map[j] != NULL ? free(az->map->map[j]) : 0;
		free(az->map->map);
	}
	(az->map->map = (int **)malloc(sizeof(int*) * 60)) == NULL ?
		stop_exec("MALLLOC FAILED\n", az) : 0;
	j = -1;
	while (++j < az->info->y)
		(az->map->map[j] = (int *)malloc(sizeof(int) * 60)) == NULL ?
			stop_exec("MALLLOC FAILED\n", az) : 0;
	parseloadedit(az);
}

void	loadedittoreset(t_acz *az)
{
	int i;
	int j;

	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
			az->info->editmap[j][i] = 0;
	}
}

void	loadplaytoedit(t_acz *az)
{
	int i;
	int j;

	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
			az->info->editmap[j][i] = az->map->map[j][i];
	}
}

void	loadedit(t_acz *az)
{
	load_texture(az->main->rend, &az->menu->editor, "texture/editor.png");
	load_texture(az->main->rend, &az->menu->select, "texture/select.png");
}

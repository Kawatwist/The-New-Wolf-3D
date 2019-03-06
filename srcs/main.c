/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:36:05 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 11:52:38 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	stop_exec(void *msg, t_acz *az)
{
	ft_putstr(msg);
	if (az != NULL)
	{
		if (az->main != NULL)
			freemain(az);
		if (az->map != NULL)
			freemap(az);
		if (az->inv != NULL)
			free(az->inv);
		if (az->sprite != NULL)
			freesprite(az->sprite);
		if (az->info != NULL)
			freeinfo(az);
		if (az->menu != NULL)
			freemenu(az);
		if (az->option != NULL)
			freeoption(az);
		if (az->game != NULL)
			freegame(az);
		freeaz(az);
		free(az);
	}
	while (1)
		;
	exit(0);
}

int		main(int argc, char **argv)
{
	t_acz	*az;

	az = NULL;
	if (argc < 3 && argc > 3)
		stop_exec("Erreur du nombre d'argument\n", az);
	initialization(&az);
	map_parse(&az, argv[1]);
	running(&az);
	return (0);
}

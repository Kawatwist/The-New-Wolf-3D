/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:36:05 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/20 17:26:43 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	stop_exec(void *msg)
{
	ft_putstr(msg);
	//	free sdl
	exit(0);
}

int		main(int argc, char **argv)
{
	t_acz	*az;

	if (argc < 3 && argc > 3)
		stop_exec("Erreur du nombre d'argument\n");
	initialization(&az);
	map_parse(&az, argv[1]);
	running(&az);
	return (0);
}

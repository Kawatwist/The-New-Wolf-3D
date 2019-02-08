/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:40:44 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/08 15:40:04 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	initialization(t_acz *az)
{
	int	i;

	(az = (t_acz *)malloc(sizeof(t_acz))) == NULL ? stop_exec("Dosnt malloc az struct\n") : 0;
	(az->map = (t_map *)malloc(sizeof(t_map))) == NULL ? stop_exec("Dosnt malloc map struct\n") : 0;
	(az->inv = (t_inv *)malloc(sizeof(t_inv))) == NULL ? stop_exec("Dosnt malloc inv struct\n") : 0;
	i = -1;
	while (++i < 800)
		(az->ray[i] = (t_ray *)malloc(sizeof(t_ray))) == NULL ? stop_exec("Dosnt malloc ray struct\n") : 0;
	(az->menu = (t_menu *)malloc(sizeof(t_menu))) == NULL ? stop_exec("Dosnt malloc menu struct\n") : 0;
}

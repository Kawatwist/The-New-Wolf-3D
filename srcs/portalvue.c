/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portalvue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:04:33 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 17:12:38 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static double	rotpos2(t_acz *az, int portal)
{
	if (az->map->orange[0] - az->map->blue[0] == 0)
		return (180 * 0.017453);
	else if (az->map->orange[0] - az->map->blue[0] == 1)
		return (-90 * 0.017453);
	else if (az->map->orange[0] - az->map->blue[0] == -1)
		return (90 * 0.017453);
	else if (az->map->orange[0] - az->map->blue[0] == 2)
		return (0);
	else if (az->map->orange[0] - az->map->blue[0] == -2)
		return (0);
	else if (az->map->orange[0] - az->map->blue[0] == 3)
		return (-270 * 0.017453);
	else if (az->map->orange[0] - az->map->blue[0] == -3)
		return (270 * 0.017453);
	return (0);
}

double			rotpos(t_acz *az, int portal)
{
	if (portal == 6)
	{
		if (az->map->orange[0] - az->map->blue[0] == 0)
			return (180 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == 1)
			return (90 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == -1)
			return (-90 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == 2)
			return (0);
		else if (az->map->orange[0] - az->map->blue[0] == -2)
			return (0);
		else if (az->map->orange[0] - az->map->blue[0] == 3)
			return (270 * 0.017453);
		else if (az->map->orange[0] - az->map->blue[0] == -3)
			return (-270 * 0.017453);
	}
	return (rotpos2(az, portal));
}

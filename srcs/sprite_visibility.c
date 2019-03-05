/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_visibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:17:03 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 10:37:18 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	isvisible5(t_acz *az, t_sprite *tmp, int i)
{
	if ((((az->sdetect.sx < az->sdetect.dxf)
		&& (az->sdetect.sx >= az->sdetect.dxl))
		|| ((az->sdetect.sx >= az->sdetect.dxf)
		&& (az->sdetect.sx < az->sdetect.dxl)))
		&& (((az->sdetect.sy < az->sdetect.dyf)
		&& (az->sdetect.sy >= az->sdetect.dyl))
		|| ((az->sdetect.sy >= az->sdetect.dyf)
		&& (az->sdetect.sy < az->sdetect.dyl))))
	{
		if ((az->sdetect.sx / az->sdetect.sy - az->ray[i]->posx
		/ az->ray[i]->posy) > 0.01 || (az->sdetect.sx / az->sdetect.sy
		- az->ray[i]->posx / az->ray[i]->posy) < -0.01)
			return (0);
		return (1);
	}
	return (0);
}

static int	isvisible4(t_acz *az, t_sprite *tmp, int i)
{
	if (az->sdetect.dyf >= 0 && az->sdetect.dyl >= 0)
	{
		if (az->sdetect.sy < 0)
			return (0);
		if ((az->sdetect.sx / az->sdetect.sy - az->ray[i]->posx
			/ az->ray[i]->posy) > 0.01 || (az->sdetect.sx
			/ az->sdetect.sy - az->ray[i]->posx / az->ray[i]->posy) < -0.01)
			return (0);
		if (az->sdetect.sx / az->sdetect.sy >= az->sdetect.dxl
			/ az->sdetect.dyl && az->sdetect.sx / az->sdetect.sy
			< az->sdetect.dxf / az->sdetect.dyf)
			return (1);
	}
	return (isvisible5(az, tmp, i));
}

static int	isvisible3(t_acz *az, t_sprite *tmp, int i)
{
	if (az->sdetect.dyf < 0 && az->sdetect.dyl < 0)
	{
		if (az->sdetect.sy >= 0)
			return (0);
		if ((az->sdetect.sx / az->sdetect.sy - az->ray[i]->posx
			/ az->ray[i]->posy) > 0.01 || (az->sdetect.sx
			/ az->sdetect.sy - az->ray[i]->posx / az->ray[i]->posy) < -0.01)
			return (0);
		if (az->sdetect.sx / az->sdetect.sy >= az->sdetect.dxl
			/ az->sdetect.dyl && az->sdetect.sx / az->sdetect.sy
			< az->sdetect.dxf / az->sdetect.dyf)
			return (1);
	}
	return (isvisible4(az, tmp, i));
}

static int	isvisible2(t_acz *az, t_sprite *tmp, int i)
{
	if (az->sdetect.dxf < 0 && az->sdetect.dxl < 0)
	{
		if (az->sdetect.sx >= 0)
			return (0);
		if ((az->sdetect.sy / az->sdetect.sx - az->ray[i]->posy
			/ az->ray[i]->posx) > 0.01 || (az->sdetect.sy
			/ az->sdetect.sx - az->ray[i]->posy / az->ray[i]->posx) < -0.01)
			return (0);
		if (az->sdetect.sy / az->sdetect.sx < az->sdetect.dyl
			/ az->sdetect.dxl && az->sdetect.sy
			/ az->sdetect.sx >= az->sdetect.dyf / az->sdetect.dxf)
			return (1);
	}
	return (isvisible3(az, tmp, i));
}

int			isvisible(t_acz *az, t_sprite *tmp, int i)
{
	az->sdetect.sx = (az->map->persox * SBLOCK) - (tmp->posx * SBLOCK);
	az->sdetect.sy = (az->map->persoy * SBLOCK) - (tmp->posy * SBLOCK);
	if (az->sdetect.dxf >= 0 && az->sdetect.dxl >= 0)
	{
		if (az->sdetect.sx < 0)
			return (0);
		if ((az->sdetect.sy / az->sdetect.sx - az->ray[i]->posy
		/ az->ray[i]->posx) > 0.01 || (az->sdetect.sy
		/ az->sdetect.sx - az->ray[i]->posy / az->ray[i]->posx) < -0.01)
			return (0);
		if (az->sdetect.sy / az->sdetect.sx < az->sdetect.dyl
			/ az->sdetect.dxl && az->sdetect.sy / az->sdetect.sx
			>= az->sdetect.dyf / az->sdetect.dxf)
			return (1);
	}
	return (isvisible2(az, tmp, i));
}

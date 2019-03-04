/*
 stock ang beetween 2 portail orange<>blue  [3]
 distance xy + 1 pour front block			[4/5]

 x1 = dda->x
 x2 = dda->dstx
 x3 = new dda->dstx
*/
#include "../includes/wolf3d.h"

void		unlimitedmap(t_acz *az, t_dda *dda)
{
	if (dda->y <= 0)
		dda->y = 59 * SBLOCK;
	else if (dda->y > 59 * SBLOCK)
		dda->y = 1;
	else if (dda->x <= 0)
		dda->x = 59 * SBLOCK;
	else if (dda->x > 59 * SBLOCK)
		dda->x = 1;
}

void		newportail(t_acz *az, t_dda *dda, int portal)
{
	float	xdiff;
	float	ydiff;
	float	padding;
	float	tmp;

	padding = (dda->x % SBLOCK == 0 ? dda->y % SBLOCK : dda->x % SBLOCK);
	if (dda->i == XSCREEN / 2)
	{
		printf("portail = %f\t", az->map->orange[0]);
		printf("y1 = %f\t", az->map->orange[1]);
		printf("x1 = %f\t", az->map->orange[2]);
		printf("rot = %f\t", az->map->orange[3]);
		printf("x2 = %f\t", az->map->orange[4]);
		printf("y2 = %f\n", az->map->orange[5]);
	}
	if (portal == 6)
	{
		tmp = ((dda->dstx - dda->x) * cos(az->map->blue[3])) + ((dda->dsty - dda->y) * -sin(az->map->blue[3])) + dda->x;
		dda->dsty = ((dda->dstx - dda->x) * sin(az->map->blue[3])) + ((dda->dsty - dda->y) * cos(az->map->blue[3])) + dda->y;
		dda->dstx = tmp;
	}
	else
	{
		tmp = ((dda->x - dda->dstx) * cos(az->map->orange[3])) + ((dda->y - dda->dsty) * -sin(az->map->orange[3])) + dda->x;
		dda->dsty = ((dda->x - dda->dstx) * sin(az->map->orange[3])) + ((dda->y - dda->dsty) * cos(az->map->orange[3])) + dda->y;
		dda->dstx = tmp;
	}
	xdiff = dda->x - dda->dstx;
	ydiff = dda->y - dda->dsty;
	if (portal == 6)
	{
		dda->x = az->map->orange[2] + ((int)az->map->orange[2] % 64 != 0 ? padding : 0);
		dda->y = az->map->orange[1] + ((int)az->map->orange[1] % 64 != 0 ? padding : 0);
		dda->dstx += xdiff + ((int)az->map->orange[2] % 64 != 0 ? padding : 0);
		dda->dsty += ydiff + ((int)az->map->orange[1] % 64 != 0 ? padding : 0);
	}
	else
	{
		dda->x = az->map->blue[2] + ((int)az->map->blue[2] % 64 != 0 ? padding : 0);
		dda->y = az->map->blue[1] + ((int)az->map->blue[1] % 64 != 0 ? padding : 0);
		dda->dstx += xdiff + ((int)az->map->blue[2] % 64 != 0 ? padding : 0);
		dda->dsty += ydiff + ((int)az->map->blue[1] % 64 != 0 ? padding : 0);
	}
}

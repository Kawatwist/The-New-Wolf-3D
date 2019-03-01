/*

NEED TO DO

 stock ang beetween 2 portail orange<>blue  [3]
 distance xy + 1 pour front block			[4/5]

 x1 = dda->x
 x2 = dda->dstx
 x3 = new dda->dstx

*/

void		newportail(t_acz *az, t_dda *dda, int portail)
{
	float	xdiff;
	float	ydiff;
	float	padding;
	float	tmp;

	padding = (dda->x % SBLOCK == 0 ? dda->y % SBLOCK : (dda->x % SBLOCK) + 100);
	if (portal == 6)
	{
		tmp = ((dda->dstx - dda->x) * cos(az->map->blue[3])) + ((dda->dsty - dda->y) * sin(az->map->blue[ang])) + dda->x;
		dda->dsty = ((dda->dstx - dda->x) * -sin(az->map->blue[3])) + ((dda->dsty - dda->y) * cos(az->map->blue[ang])) + dda->y;
		dda->dstx = tmp;
	}
	else
	{
		tmp = ((dda->dstx - dda->x) * cos(az->map->blue[3])) + ((dda->dsty - dda->y) * sin(az->map->blue[ang])) + dda->x;
		dda->dsty = ((dda->dstx - dda->x) * -sin(az->map->blue[3])) + ((dda->dsty - dda->y) * cos(az->map->blue[ang])) + dda->y;
		dda->dstx = tmp;
	}
	xdiff = dda->x - dda->dstx;
	ydiff = dda->y - dda->dsty;
	if (portal == 6)
	{
		dda->x = az->map->blue[4] + (padding > 100 ? padding : 0);
		ddy->x = az->map->blue[5] + (padding < 100 ? padding : 0);
	}
	else
	{
		dda->x = az->map->orange[4] + (padding > 100 ? padding : 0);
		ddy->x = az->map->orange[5] + (padding < 100 ? padding : 0);
	}
	dda->dstx +=  xdiff;
	dda->dxty += ydiff;
}

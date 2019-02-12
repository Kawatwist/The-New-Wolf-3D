#include "../includes/wolf3d.h"

int	diffside(t_acz *az, t_dda *dda)
{
	int	value1;
	int	value2;
	int	portal;

	value1 = dda->x / SBLOCK;
	value2 = dda->y / SBLOCK;
	portal = az->map->map[value2][value1];
	if ((((az->map->map[(dda->y - 1) / SBLOCK][value1]) == 6) && ((az->map->map[(dda->y + 1) / SBLOCK][value1]) == 6)) || (((az->map->map[(dda->y - 1) / SBLOCK][value1]) == 7) && ((az->map->map[(dda->y + 1) / SBLOCK][value1]) == 7)))
        {
                if (dda->pasx == -1)
                        return (portal == az->map->blue ? az->map->orange - 3 : az->map->blue - 3);
                return (portal == az->map->blue ? az->map->orange - 4 : az->map->blue - 4);
        }
        if ((((az->map->map[value2][(dda->x - 1) / SBLOCK]) == 6) && ((az->map->map[value2][(dda->x + 1) / SBLOCK]) == 6)) || (((az->map->map[value2][(dda->x - 1) / SBLOCK]) == 7) && ((az->map->map[value2][(dda->x + 1) / SBLOCK]) == 7)))
        {
                if (dda->pasy == -1)
                	return (portal == az->map->blue ? az->map->orange - 1 : az->map->blue - 1);
            	return (portal == az->map->blue ? az->map->orange - 2 : az->map->blue - 2);
        }
	return (0);
}

void	portalapply(t_dda *current, int facediff, int x, int y)
{
	double	tmp;

	facediff *= 90;
	tmp = ((current->dx - x) * cos(facediff)) + ((current->dy - y) * sin(facediff));
	current->dy = ((current->dx - x) * -sin(facediff)) + ((current->dy - y) * cos(facediff));
	current->dx = tmp;
}

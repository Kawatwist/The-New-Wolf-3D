#include "../includes/wolf3d.h"

void	setportal(t_acz *az, int y, int x, int portal)
{
	int i;
	int	j;

	j = -1;
	printf("Yo\n");
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
			az->map->map[j][i] == portal ? az->map->map[j][i] = 1 : 0;
	}
	az->map->map[y][x] = portal;
}

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
                        return ((portal == az->map->blue[0] ? az->map->orange[0] - 3 : az->map->blue[0] - 3));
                return ((portal == az->map->blue[0] ? az->map->orange[0] - 4 : az->map->blue[0] - 4));
        }
        if ((((az->map->map[value2][(dda->x - 1) / SBLOCK]) == 6) && ((az->map->map[value2][(dda->x + 1) / SBLOCK]) == 6)) || (((az->map->map[value2][(dda->x - 1) / SBLOCK]) == 7) && ((az->map->map[value2][(dda->x + 1) / SBLOCK]) == 7)))
        {
                if (dda->pasy == -1)
                	return ((portal == az->map->blue[0] ? az->map->orange[0] - 1 : az->map->blue[0] - 1));
            	return ((portal == az->map->blue[0] ? az->map->orange[0] - 2 : az->map->blue[0] - 2));
        }
	return (0);
}

void	portalapply(t_dda *current, int facediff, int x, int y)
{
	double	tmp;

	facediff *= 90;
	tmp = ((current->dx - x) * cos((facediff * 90) * 0.017453) + (1)) + ((current->dy - y) * sin((facediff * 90) * 0.017453) + (1));
	current->dy = ((current->dx - x) * -sin((facediff * 90) * 0.017453) + (1)) + ((current->dy - y) * cos((facediff * 90) * 0.017453) + (1));
	current->dx = tmp;
}

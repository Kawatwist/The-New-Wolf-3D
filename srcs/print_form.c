#include "../includes/wolf3d.h"

void			printselect(t_acz *az)
{
	int x;
	int y;

	if (az->info->selmap == NULL)
		return ;
	y = 0;
	while (y < az->info->selsizey)
	{
		x = 0;
		while (x < az->info->selsizex)
		{
			if ((y + az->info->edity / 10) > 60 || (x + az->info->editx / 10) > 60)
				break ;
			az->info->editmap[y + (az->info->edity / 10)][x + (az->info->editx / 10)] = az->info->selmap[y][x];
			x++;
		}
		y++;
	}
}

void			printline(t_acz *az)
{
	int		i;
	double	value;

	i = 0;
	raycast(az);
	while (i < XSCREEN)
	{
		value = az->info->range / az->ray[i]->obs;
		value < 0 ? value *= -1 : 0;
		value = value / 200;
		az->side[i] / SBLOCK == 1 ? SDL_SetRenderDrawColor(az->main->rend, 200, 0, az->side[i] % SBLOCK, 0) : 0;
		az->side[i] / SBLOCK == 2 ? SDL_SetRenderDrawColor(az->main->rend, az->side[i] % SBLOCK, 200, 0, 0) : 0;
		az->side[i] / SBLOCK == 3 ? SDL_SetRenderDrawColor(az->main->rend, 0, az->side[i] % SBLOCK, 200, 0) : 0;
		az->side[i] / SBLOCK == 4 ? SDL_SetRenderDrawColor(az->main->rend, 180, az->side[i] % SBLOCK, 180, 0) : 0;
		SDL_RenderDrawLine(az->main->rend, i, (YSCREEN / 2) - (value), i, (YSCREEN / 2) + (value));
		i++;
	}
}

static void		printgrill2(t_acz *az)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 60)
	{
		x = -1;
		while (++x < 60)
			if (az->info->editmap[y][x] == 0)
			{	SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
				SDL_RenderDrawLine(az->main->rend, y * 10, 0, y * 10, 600);
				SDL_RenderDrawLine(az->main->rend, 0, y * 10, 600, y * 10);
			}
	}

}

void			printgrill(t_acz *az)
{
	int		j;
	int		i;
	SDL_Rect	square;

	square.w = 10;
	square.h = 10;
	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
		{
			if (az->info->editmap[j][i] != 0)
			{
				square.x = j * 10;
				square.y = i * 10;
				az->info->editmap[j][i] == 1 ? SDL_SetRenderDrawColor(az->main->rend, 255, 255, 255, 0) : 0;
				az->info->editmap[j][i] == 2 ? SDL_SetRenderDrawColor(az->main->rend, 255, 0, 255, 0) : 0;
				az->info->editmap[j][i] == 3 ? SDL_SetRenderDrawColor(az->main->rend, 255, 0, 0, 0) : 0;
				az->info->editmap[j][i] == 4 ? SDL_SetRenderDrawColor(az->main->rend, 255, 150, 0, 0) : 0;
				az->info->editmap[j][i] == 5 ? SDL_SetRenderDrawColor(az->main->rend, 50, 100, 50, 0) : 0;
				SDL_RenderFillRect(az->main->rend, &square);
			}
		}
	}
	printgrill2(az);
}

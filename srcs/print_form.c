#include "../includes/wolf3d.h"

void	printgrill(t_acz *az)
{
	int		j;
	int		i;
	SDL_Rect	square;

	square.w = 10;
	square.h = 10;
	j = 0;
	while (j < 60)
	{
		i = 0;
		while (i < 60)
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
			if (i == 0)
			{
				SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
				SDL_RenderDrawLine(az->main->rend, j * 10, 0, j * 10, 600);
				SDL_RenderDrawLine(az->main->rend, 0, j * 10, 600, j * 10);
			}
			i += 1;
		}
		j += 1;
	}
}

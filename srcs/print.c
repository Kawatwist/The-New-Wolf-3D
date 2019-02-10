#include "../includes/wolf3d.h"

static void	printedit(t_acz *az)
{
	SDL_SetRenderDrawColor(az->main->rend, 30, 30, 30, 0);
	SDL_RenderClear(az->main->rend);
	SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
	printgrill(az);
	SDL_SetRenderDrawColor(az->main->rend, 250, 120, 0, 0);
	SDL_RenderDrawLine(az->main->rend, 0, az->info->editx, YSCREEN, az->info->editx);
	SDL_RenderDrawLine(az->main->rend, az->info->edity, 0,  az->info->edity, 600);
	rectpos(az);
	SDL_RenderCopy(az->main->rend, az->menu->editor, NULL, &az->menu->redit);
	SDL_RenderCopy(az->main->rend, az->menu->select, NULL, &az->menu->rselect);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

static void	printoption(t_acz *az)
{
	SDL_SetRenderDrawColor(az->main->rend, 100, 100, 100, 0);
	SDL_RenderClear(az->main->rend);
	SDL_RenderCopy(az->main->rend, az->option->bg, NULL, NULL);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

static void	printgame(t_acz *az)
{
	SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
	SDL_RenderClear(az->main->rend);
	showsky(az);
	SDL_RenderCopy(az->main->rend, az->game->sky, &az->game->rsky2, &az->game->rsky);
	SDL_RenderCopy(az->main->rend, az->game->ground, NULL, &az->game->rground);
	printline(az);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

static void	printmenu(t_acz *az)
{
	az->menu->rchoice.x = (az->menu->mode == 0 || az->menu->mode == 2 ? 35 : 350);
	az->menu->rchoice.y = (az->menu->mode == 0 || az->menu->mode == 1 ? 230 : 415);
	az->menu->rchoice.w = 75;
	az->menu->rchoice.h = 75;
	SDL_RenderCopy(az->main->rend, az->menu->bg, NULL, NULL);
	SDL_RenderCopy(az->main->rend, az->menu->choice, NULL, &az->menu->rchoice);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

void		print(t_acz *az)
{
	az->interface == 0 ? printmenu(az) : 0;
	az->interface == 1 ? printgame(az) : 0;
	az->interface == 2 ? printoption(az) : 0;
	az->interface == 3 ? printedit(az) : 0;
}

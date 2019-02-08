#include "../includes/wolf3d.h"

void	setuprect(SDL_Rect *rect, int load, t_win *wn)
{
	rect->w = wn->xscreen;
	rect->h = wn->yscreen;
	if (load == 1)
	{
		rect->x = wn->xscreen / 2;
		rect->y = wn->yscreen / 2;
	}
	else
	{
		rect->x = 0;
		rect->y = 0;
	}
}

void	loadpng(SDL_Surface *surface, char *path)
{
	surface = IMG_Load(path);
	if (surface == NULL)
		stop_exec("Surface not load\n");
}

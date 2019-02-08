#include "../includes/wolf3d.h"

void		save(t_win *wn)
{
}

SDL_Rect	*editrect(int x, int y)
{
	SDL_Rect *rect;

	rect->x = x;
	rect->y = y;
	rect->w = 50;
	rect->h = 50;

	return (rect);
}

void		edit(t_win *wn)
{
	if (wn->edit->ev.button.state == SDL_PRESSED)
	{
		SDL_SetRenderDrawColor(wn->edit->rend, 120,0,0,100);
		SDL_RenderFillRect(wn->edit->rend, editrect(wn->edit->ev.button.x, wn->edit->ev.button.y));
		SDL_RenderPresent(wn->edit->rend);
	}
}

void		setedit(t_win *wn)
{
	SDL_SetRenderDrawColor(wn->edit->rend, 120,120,120,0);
	SDL_RenderClear(wn->edit->rend);
	SDL_RenderPresent(wn->edit->rend);
	SDL_UpdateWindowSurface(wn->edit->wind);
	wn->x = 0;
	wn->y = 0;
}

#include "../includes/wolf3d.h"

void	load_texture(SDL_Renderer *render, SDL_Texture **texture, char *path)
{
	SDL_Surface	*surface;

	surface = IMG_Load(path);
	surface == NULL ? stop_exec("cant load surface\n") : 0;
	*texture = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
}

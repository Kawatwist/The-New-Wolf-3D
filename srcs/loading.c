#include "../includes/wolf3d.h"

void	loadoption(t_acz *az)
{
	load_texture(az->main->rend, &az->option->bg, "texture/option.png");
}

void	loadmenu(t_acz *az)
{
	load_texture(az->main->rend, &az->menu->bg, "texture/bg.png");
	load_texture(az->main->rend, &az->menu->choice, "texture/arrow.png");
}

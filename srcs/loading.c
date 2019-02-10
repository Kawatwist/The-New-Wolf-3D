#include "../includes/wolf3d.h"

void	rectpos(t_acz *az)
{
	az->menu->rselect.x = 629;
	az->menu->rselect.y = 24 + (az->info->editbrush * 41);
	az->menu->rselect.w = 26;
	az->menu->rselect.h = 26;
	az->menu->redit.x = 600;
	az->menu->redit.y = 0;
	az->menu->redit.w = 200;
	az->menu->redit.h = 600;
}

void	loadgame(t_acz *az)
{
	load_texture(az->main->rend, &az->game->sky, "texture/sky.png");
	load_texture(az->main->rend, &az->game->ground, "texture/ground.png");
}

void	loadedit(t_acz *az)
{
	load_texture(az->main->rend, &az->menu->editor, "texture/editor.png");
	load_texture(az->main->rend, &az->menu->select, "texture/select.png");
}

void	loadoption(t_acz *az)
{
	load_texture(az->main->rend, &az->option->bg, "texture/option.png");
}

void	loadmenu(t_acz *az)
{
	az->main->effect = Mix_LoadWAV("texture/Gun.wav");
	load_texture(az->main->rend, &az->menu->bg, "texture/bg.png");
	load_texture(az->main->rend, &az->menu->choice, "texture/arrow.png");
}

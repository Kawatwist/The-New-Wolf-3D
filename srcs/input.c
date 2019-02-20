/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/20 19:47:56 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		textbox(t_acz *az, Uint8 *state)
{
	(state[SDL_SCANCODE_A] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("A"), 2) : 0);
	(state[SDL_SCANCODE_B] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("B"), 2) : 0);
	(state[SDL_SCANCODE_C] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("C"), 2) : 0);
	(state[SDL_SCANCODE_D] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("D"), 2) : 0);
	(state[SDL_SCANCODE_E] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("E"), 2) : 0);
	(state[SDL_SCANCODE_F] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("F"), 2) : 0);
	(state[SDL_SCANCODE_G] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("G"), 2) : 0);
	(state[SDL_SCANCODE_H] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("H"), 2) : 0);
	(state[SDL_SCANCODE_I] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("I"), 2) : 0);
	(state[SDL_SCANCODE_J] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("J"), 2) : 0);
	(state[SDL_SCANCODE_K] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("K"), 2) : 0);
	(state[SDL_SCANCODE_L] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("L"), 2) : 0);
	(state[SDL_SCANCODE_M] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("M"), 2) : 0);
	(state[SDL_SCANCODE_N] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("N"), 2) : 0);
	(state[SDL_SCANCODE_O] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("O"), 2) : 0);
	(state[SDL_SCANCODE_P] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("P"), 2) : 0);
	(state[SDL_SCANCODE_Q] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("Q"), 2) : 0);
	(state[SDL_SCANCODE_R] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("R"), 2) : 0);
	(state[SDL_SCANCODE_S] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("S"), 2) : 0);
	(state[SDL_SCANCODE_T] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("T"), 2) : 0);
	(state[SDL_SCANCODE_U] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("U"), 2) : 0);
	(state[SDL_SCANCODE_V] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("V"), 2) : 0);
	(state[SDL_SCANCODE_W] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("W"), 2) : 0);
	(state[SDL_SCANCODE_X] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("X"), 2) : 0);
	(state[SDL_SCANCODE_Y] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("Y"), 2) : 0);
	(state[SDL_SCANCODE_Z] ? az->name_save =
	ft_strjoinfree(az->name_save, ft_strdup("Z"), 2) : 0);
	(state[SDL_SCANCODE_DELETE] ?
	ft_bzero(az->name_save, ft_strlen(az->name_save)) : 0);
}

void		collision(t_acz *az)
{
	if (az->map->persox > 60)
		az->map->persox = 0.5;
	if (az->map->persoy > 60)
		az->map->persoy = 0.5;
	if (az->map->persox <= 0)
		az->map->persox = 59.5;
	if (az->map->persoy <= 0)
		az->map->persoy = 59.5;
	if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 3)
	{
		az->interface = 0;
		ft_putstr("You win\n");
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 8)
	{
		az->inv->health < 100 ? az->inv->health = 100 : 0;
		az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 9)
	{
		az->inv->shield < 100 ? az->inv->shield = 100 : 0;
		az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 1)
	{
		az->map->persox -= az->map->lastmovx;
		az->map->persoy -= az->map->lastmovy;
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 4)
	{
		az->inv->key += 1;
		az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 5)
	{
		if (az->inv->key > 0)
		{
			az->inv->key -= 1;
			az->map->map[(int)az->map->persoy][(int)az->map->persox] = 0;
		}
		else
		{
			az->map->persox -= az->map->lastmovx;
			az->map->persoy -= az->map->lastmovy;
		}
	}
	if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 6 &&
			az->map->orange[0] != 0)
	{
		az->map->persoy = az->map->orange[1];
		az->map->persox = az->map->orange[2];
		az->map->persoy += (az->map->orange[0] == 8 ? 1 : 0);
		az->map->persoy += (az->map->orange[0] == 6 ? -1 : 0);
		az->map->persox += (az->map->orange[0] == 7 ? 1 : 0);
		az->map->persox += (az->map->orange[0] == 5 ? -1 : 0);
		changeray(az, 6);
	}
	else if (az->map->map[(int)az->map->persoy][(int)az->map->persox] == 7 &&
			az->map->blue[0] != 0)
	{
		az->map->persoy = az->map->blue[1];
		az->map->persox = az->map->blue[2];
		az->map->persoy += (az->map->blue[0] == 8 ? 1 : 0);
		az->map->persoy += (az->map->blue[0] == 6 ? -1 : 0);
		az->map->persox += (az->map->blue[0] == 7 ? 1 : 0);
		az->map->persox += (az->map->blue[0] == 5 ? -1 : 0);
		changeray(az, 7);
	}
}

static void	mousegame(Uint16 mouse, t_acz *az, int x, int y)
{
	SDL_ShowCursor(az->interface != 1 ? SDL_ENABLE : SDL_DISABLE);
	SDL_CaptureMouse(az->interface == 1 ? 1 : 0);
	az->interface == 1 ? SDL_WarpMouseInWindow(az->main->window, XSCREEN / 2, YSCREEN /2) : 0;
	az->info->angle += (x - 400) * az->sensi;
	az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
	if (az->inv->rifle == 0)
	{
		az->shoot = (mouse & SDL_BUTTON_LMASK) == 1 ? 1 : 0;
		if (az->fx == 1)
			az->shoot == 1 ? Mix_PlayChannel(-1, az->main->portal1, 0) : 0;
		az->shoot1 = (mouse & SDL_BUTTON_RMASK) == 4 ? 1 : 0;
		if (az->fx == 1)
			az->shoot1 == 1 ? Mix_PlayChannel(-1, az->main->portal2, 0) : 0;
		az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
		if (mouse & SDL_BUTTON_LMASK)
			load_texture(az->main->rend, &az->game->gun, "texture/portalshoot1.png");
		else if (mouse & SDL_BUTTON_RMASK)
			load_texture(az->main->rend, &az->game->gun, "texture/portalshoot2.png");
		else
			load_texture(az->main->rend, &az->game->gun, "texture/portalgun.png");
	}
	else if (az->inv->rifle == 1)
	{
		if (mouse & SDL_BUTTON_LMASK || mouse & SDL_BUTTON_RMASK)
			load_texture(az->main->rend, &az->game->gun, "texture/sword2.png");
		else
			load_texture(az->main->rend, &az->game->gun, "texture/sword.png");
	}
	else if (az->inv->rifle == 2)
	{
		if (mouse & SDL_BUTTON_LMASK || mouse & SDL_BUTTON_RMASK)
			load_texture(az->main->rend, &az->game->gun, "texture/P2.png");
		else
			load_texture(az->main->rend, &az->game->gun, "texture/P1.png");
	}
}

static void	mouseoption(Uint16 mouse, t_acz *az, int x, int y)
{
	x = x * 1600 / XSCREEN;
	y = y * 1200 / YSCREEN;
	if ((x >= 216 && x <= 256) && (y >= 571 && y <= 610))
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->fullscreen *= -1 : 0;
	else if ((x >= 216 && x <= 256) && (y >= 689 && y <= 729))
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->mute *= -1 : 0;
	else if ((x >= 216 && x <= 256) && (y >= 807 && y <= 847))
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->fx *= -1 : 0;
	else if ((x >= 216 && x <= 256) && (y >= 925 && y <= 965))
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->hud *= -1 : 0;
	if (y >= 342 && y <= 366 && x >= 820 && x <= 1375)
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->sensi = 0.0015 + ((x - 820) * 0.000002) : 0;
}

static void	mouseedit(Uint16 mouse, t_acz *az, int x, int y)
{
	if (az->mouse == 1)
	{
		az->info->editx = y;
		az->info->edity = x;
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->info->editmap[az->info->edity / 10][az->info->editx / 10] = az->info->editbrush : 0;
	}
}

static void	mouseinput(t_acz *az)
{
	Uint16			mouse;
	int				x;
	int				y;

	mouse = SDL_GetMouseState(&x, &y);
	az->interface == 1 ? mousegame(mouse, az, x, y) : 0;
	az->interface == 2 ? mouseoption(mouse, az, x, y) : 0;
	az->interface == 3 ? mouseedit(mouse, az, x, y) : 0;
}

static void	input_menu(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_DOWN] && az->menu->mode < 3 ? az->menu->mode += 1 : 0;
	state[SDL_SCANCODE_UP] && az->menu->mode > 0 ? az->menu->mode -= 1 : 0;
	if (state[SDL_SCANCODE_RETURN])
	{
		Mix_PlayChannel(-1, az->main->effect, 0);
		az->menu->mode == 0 ? az->interface = 1 : 0;
		az->menu->mode == 1 ? az->interface = 2 : 0;
		az->menu->mode == 2 ? az->interface = 3 : 0;
		az->menu->mode == 3 ? stop_exec("Goodbye & see you later\n") : 0;
	}
	state[SDL_SCANCODE_ESCAPE] ? stop_exec("Escape\n") : 0;
}

static void	rotate_perso(t_acz *az)
{
	int 	current;
	double	ang;

	current = 0;
	while (current < XSCREEN)
	{
		ang = (current * 0.002) + az->info->angle;
		az->ray[current]->posx = (az->info->range * cos(ang)) + (az->info->range * -sin(ang)) + (az->map->persox);
		az->ray[current]->posy = (az->info->range * sin(ang)) + (az->info->range * cos(ang)) + (az->map->persoy);
		current++;
	}
}

static void	mouvement(t_acz *az, int move)
{
	double tmp;

	if (move == 0 || move == 2)
	{
		az->map->lastmovx = 0;
		az->map->lastmovy = (move == 2 ? 0.1 : -0.1);
	}
	else
	{
		az->map->lastmovx = (move == 3 ? 0.1 : -0.1);
		az->map->lastmovy = 0;
	}
	tmp = (az->map->lastmovx * cos(az->info->angle)) + (az->map->lastmovy * -sin(az->info->angle));
	az->map->lastmovy = (az->map->lastmovx * sin(az->info->angle)) + (az->map->lastmovy * cos(az->info->angle));
	az->map->lastmovx = tmp;
	az->map->persox += az->map->lastmovx;
	az->map->persoy += az->map->lastmovy;
	collision(az);
}

static void	input_game(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_A] ? mouvement(az, 3) : 0;
	state[SDL_SCANCODE_D] ? mouvement(az, 1) : 0;
	state[SDL_SCANCODE_W] ? mouvement(az, 2) : 0;
	state[SDL_SCANCODE_S] ? mouvement(az, 0) : 0;
	state[SDL_SCANCODE_LEFT] ? az->info->angle -= 0.07 : 0;
	state[SDL_SCANCODE_RIGHT] ? az->info->angle += 0.07 : 0;
	state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? SDL_Delay(500) : 0;
	state[SDL_SCANCODE_1] ? az->inv->rifle = 0 : 0;
	state[SDL_SCANCODE_2] ? az->inv->rifle = 1 : 0;
	state[SDL_SCANCODE_3] ? az->inv->rifle = 2 : 0;
	if (state[SDL_SCANCODE_1] || state[SDL_SCANCODE_2])
		az->inv->frame = 0;
	rotate_perso(az);
}

static void	input_option(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
	state[SDL_SCANCODE_H] ? az->interface = 4 : 0;
	state[SDL_SCANCODE_ESCAPE] ? SDL_Delay(500) : 0;
}

static void	input_editor(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_F5] ? az->textbox *= -1 : 0;
	if (az->textbox == -1)
	{
		state[SDL_SCANCODE_ESCAPE] ? az->interface = 0 : 0;
		state[SDL_SCANCODE_ESCAPE] ? SDL_Delay(500) : 0;
		state[SDL_SCANCODE_F1] ? az->interface = 0 : 0;
		state[SDL_SCANCODE_UP] && !state[SDL_SCANCODE_DOWN]  && az->info->editx > 9 ? az->info->editx -= 10 : 0;
		state[SDL_SCANCODE_DOWN] && !state[SDL_SCANCODE_UP]  && az->info->editx < 590 ? az->info->editx += 10 : 0;
		state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT]  && az->info->edity > 9 ? az->info->edity -= 10 : 0;
		state[SDL_SCANCODE_RIGHT] && !state[SDL_SCANCODE_LEFT]  && az->info->edity < 590 ? az->info->edity += 10 : 0;
		state[SDL_SCANCODE_KP_0] ? az->info->editbrush = 0 : 0;
		state[SDL_SCANCODE_KP_1] ? az->info->editbrush = 1 : 0;
		state[SDL_SCANCODE_KP_2] ? az->info->editbrush = 2 : 0;
		state[SDL_SCANCODE_KP_3] ? az->info->editbrush = 3 : 0;
		state[SDL_SCANCODE_KP_4] ? az->info->editbrush = 4 : 0;
		state[SDL_SCANCODE_KP_5] ? az->info->editbrush = 5 : 0;
		state[SDL_SCANCODE_KP_6] ? az->info->editbrush = 8 : 0;
		state[SDL_SCANCODE_KP_7] ? az->info->editbrush = 9 : 0;
		state[SDL_SCANCODE_KP_8] ? az->info->editbrush = ENEMY : 0;
		state[SDL_SCANCODE_C] ? az->info->selectx = az->info->editx / 10 : 0;
		state[SDL_SCANCODE_C] ? az->info->selecty = az->info->edity / 10 : 0;
		state[SDL_SCANCODE_V] ? parseselect(az) : 0;
		state[SDL_SCANCODE_P] ? printselect(az) : 0;
		if (state[SDL_SCANCODE_RETURN])
			az->info->editmap[az->info->edity / 10][az->info->editx / 10] = az->info->editbrush;
		state[SDL_SCANCODE_S] ? save_map(az) : 0;
	}
	else
	{
		textbox(az, state);
		ft_putstr("textbox on\n");
	}
}

static void	input_control(Uint8 *state, t_acz *az)
{
	state[SDL_SCANCODE_ESCAPE] ? az->interface = 2 : 0;
}

void		input(t_acz *az)
{
	Uint8	*state;

	SDL_PollEvent(&az->ev);
	state = (Uint8*)SDL_GetKeyboardState(NULL);
	az->twodactif = (state[SDL_SCANCODE_TAB] ? 1 : 0);
	state[SDL_SCANCODE_M] ? az->mute = 1 : 0;
	state[SDL_SCANCODE_H] ? az->mouse *= -1 : 0;
	mouseinput(az);
	if (az->interface == 0)
	{
		state[SDL_SCANCODE_L] ? loadeditoplay(az) : 0;
		state[SDL_SCANCODE_L] ? getenemypos(az) : 0;
		input_menu(state, az);
	}
	else if (az->interface == 1)
		input_game(state, az);
	else if (az->interface == 2)
		input_option(state, az);
	else if (az->interface == 3)
		input_editor(state, az);
	else if (az->interface == 4)
		input_control(state, az);
}

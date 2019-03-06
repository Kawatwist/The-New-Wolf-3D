/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:45:54 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 10:58:33 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <math.h>
# include "../libui/SDL2/SDL.h"
# include "../libui/SDL2/SDL_mixer.h"
# include "../libui/SDL2/SDL_image.h"

# define TRUE 1
# define FALSE 0
# define XSCREEN 800
# define YSCREEN 600
# define DEG2RAD 0.0174532778
# define SPAWN 2
# define ENEMY 9
# define SBLOCK 64

typedef struct			s_sdetect
{
	double				dxl;
	double				dyl;
	double				dxf;
	double				dyf;
	double				dx;
	double				dy;
	double				sx;
	double				sy;
}						t_sdetect;

typedef struct			s_sprite
{
	struct s_sprite		*next;
	double				posx;
	double				posy;
	double				dist;
	int					sizex;
	int					sizey;
	SDL_Texture			*tex;
}						t_sprite;

typedef struct			s_dda
{
	int					i;
	int					x;
	int					y;
	int					pasx;
	int					pasy;
	int					distx;
	int					disty;
	double				dist;
	double				convdist;
	int					side;
	int					dx;
	int					dy;
	int					e;
	int					pente;
	double				dstx;
	double				dsty;
	int					tmp;
}						t_dda;

typedef struct			s_info
{
	int					range;
	double				angle;
	int					x;
	int					y;
	int					editx;
	int					edity;
	int					selectx;
	int					selecty;
	int					selsizex;
	int					selsizey;
	int					**selmap;
	int					editmap[60][60];
	int					editbrush;
}						t_info;

typedef struct			s_ray
{
	double				posy;
	double				posx;
	double				obs;
	double				obsother;
	int					other;
	int					facex;
	int					facey;
}						t_ray;

typedef struct			s_inv
{
	int					akframe;
	int					frame;
	int					framesens;
	int					rifle;
	int					key;
	int					health;
	int					shield;
}						t_inv;

typedef struct			s_map
{
	int					**map;
	int					nbenemy;
	float				orange[6];
	float				blue[6];
	double				persox;
	double				persoy;
	double				lastmovx;
	double				lastmovy;
}						t_map;

typedef struct			s_menu
{
	SDL_Surface			*background;
	SDL_Surface			*choices;
	SDL_Surface			*edit;
	SDL_Texture			*bg;
	SDL_Texture			*control;
	SDL_Texture			*editor;
	SDL_Texture			*select;
	SDL_Texture			*choice;
	SDL_Rect			rchoice;
	SDL_Rect			redit;
	SDL_Rect			rselect;
	int					mode;
	int					difficulty;
}						t_menu;

typedef struct			s_game
{
	SDL_Texture			*sky;
	SDL_Texture			*ground;
	SDL_Texture			*hud;
	SDL_Texture			*compas;
	SDL_Texture			*gun;
	SDL_Texture			*ak;
	SDL_Texture			*sword;
	SDL_Texture			*portal1;
	SDL_Texture			*portal2;
	SDL_Texture			*health;
	SDL_Texture			*shield;
	SDL_Texture			*nwall;
	SDL_Texture			*swall;
	SDL_Texture			*ewall;
	SDL_Texture			*wwall;
	SDL_Texture			*door;
	SDL_Texture			*filler;
	SDL_Texture			*enemy;
	SDL_Surface			*ssky;
	SDL_Surface			*sground;
	SDL_Rect			rsky;
	SDL_Rect			rsky2;
	SDL_Rect			rground;
}						t_game;

typedef struct			s_window
{
	SDL_Window			*window;
	SDL_Renderer		*rend;
	SDL_Texture			*tbg;
	SDL_Texture			*tother;
	SDL_Surface			*sbg;
	SDL_Surface			*sother;
	SDL_Rect			rbg;
	SDL_Rect			rother;
	Mix_Music			*song;
	Mix_Chunk			*effect;
	Mix_Chunk			*portal1;
	Mix_Chunk			*portal2;
}						t_window;

typedef struct			s_acz
{
	t_window			*main;
	t_map				*map;
	t_inv				*inv;
	t_sprite			*sprite;
	t_ray				*ray[XSCREEN];
	int					side[XSCREEN];
	double				zbuffer[XSCREEN];
	t_sdetect			sdetect;
	t_info				*info;
	t_menu				*menu;
	t_menu				*option;
	t_game				*game;
	SDL_Event			ev;
	int					interface;
	Uint8				time;
	Uint8				time2;
	int					twodactif;
	int					shoot;
	int					shoot1;
	char				*name_save;
	int					fullscreen;
	int					mute;
	int					hud;
	int					fx;
	int					pack;
	int					mouse;
	int					wheelup;
	int					wheeldown;
	float				speed;
	double				mode;
	double				acl;
	double				vue;
	double				jump;
	double				sensi;
	SDL_Rect			dst;
	SDL_Rect			src;
	double				fov;
}						t_acz;

void					freeaz(t_acz *az);
void					freemain(t_acz *az);
void					freemap(t_acz *az);
void					freesprite(t_sprite *sprite);
void					freeinfo(t_acz *az);
void					freemenu(t_acz *az);
void					freeoption(t_acz *az);
void					freegame(t_acz *az);
void					printedit(t_acz *az);
void					showslider(t_acz *az);
void					showvalide(t_acz *az);
void					showhp(t_acz *az);
void					showhud(t_acz *az);
void					initdda(t_dda *dda, t_acz *az);
int						isvisible(t_acz *az, t_sprite *tmp, int i);
int						frontblock(t_acz *az, int type, int portal);
void					sort_sprite(t_sprite **sprite);
void					unlimitedmap(t_dda *dda);
double					rotpos(t_acz *az, int portal);
void					map_stock(t_acz *az, t_map *map, int fd);
void					newportail(t_acz *az, t_dda *dda, int portal);
void					sprite_dist(t_acz *az);
void					load_sprites(t_acz *az);
void					draw_sprites(t_acz *az);
void					akframe(t_acz *az);
void					getenemypos(t_acz *az);
void					loadcompas(t_acz *az);
void					loadedittoreset(t_acz *az);
void					loadplaytoedit(t_acz *az);
void					loadeditoplay(t_acz *az);
SDL_Texture				*pick_texture(t_acz *az, int i);
void					changeray(t_acz *az, int portal);
void					setportal(t_acz *az, t_dda dda, int portal);
int						diffside(t_acz *az, t_dda *dda);
void					portalapply(t_acz *az, t_dda *dda, int portal);
void					printselect(t_acz *az);
int						ft_abs(int n);
void					parseselect(t_acz *az);
void					rectpos(t_acz *az);
void					printline(t_acz *az);
void					raycast(t_acz *az);
void					save_map(t_acz *az);
void					printgrill(t_acz *az);
void					map(t_acz *az);
void					showsky(t_acz *az);
void					loadgame(t_acz *az);
void					loadedit(t_acz *az);
void					loadmenu(t_acz *az);
void					loadoption(t_acz *az);
void					load_texture(SDL_Renderer *render,
		SDL_Texture **texture, char *path, t_acz *az);
void					print(t_acz *az);
void					mouvement(t_acz *az, int move);
void					rotate_perso(t_acz *az);
void					collision(t_acz *az);
void					input_game(Uint8 *state, t_acz *az);
void					input_editor(Uint8 *state, t_acz *az);
void					textbox3(t_acz *az, Uint8 *state);
void					textbox2(t_acz *az, Uint8 *state);
void					rifle0(Uint16 mouse, t_acz *az);
void					rifle1(Uint16 mouse, t_acz *az);
void					rifle2(Uint16 mouse, t_acz *az);
void					rifle3(Uint16 mouse, t_acz *az);
void					rifle4(Uint16 mouse, t_acz *az);
void					mouseinput(t_acz *az);
void					input(t_acz *az);
void					running(t_acz **az);
void					map_parse(t_acz **az, char *name);
void					initmain(t_acz *az);
void					initmenu(t_acz *az);
void					initoption(t_acz *az);
void					initgame(t_acz *az);
void					init_info(t_info *info);
void					init_sdl(t_acz *az);
void					initray(t_acz *az);
void					initinv(t_acz *az);
void					initeditmap(int map[60][60]);
void					initialization(t_acz **az);
void					stop_exec(void	*msg, t_acz *az);
int						main(int argc, char **argv);
int						get_side(t_dda *dda, t_acz *az);

#endif

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

# define	TRUE	1
# define	FALSE	0
# define	XSCREEN	800
# define	YSCREEN	600
# define	DEG2RAD	0.0174532778
# define	SPAWN	2
# define	SBLOCK 	64

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
	int					**rifle;
	int					key;
	int					health;
	int					shield;
}						t_inv;

typedef struct			s_map
{
	int					**map;
	int					orange[3];
	int					blue[3];
	double				persox;
	double				persoy;
	double				lastmovx;
	double				lastmovy;
}						t_map;

typedef struct			s_menu
{
	SDL_Surface			*background;
	SDL_Surface			*choices;
	SDL_Surface			*font;
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
    SDL_Texture         *hud;
    SDL_Texture         *compas;
    SDL_Texture         *portal1;
    SDL_Texture         *portal2;
    SDL_Texture         *health;
    SDL_Texture         *shield;
    SDL_Texture         *Nwall;
    SDL_Texture         *Swall;
    SDL_Texture         *Ewall;
    SDL_Texture         *Wwall;
    SDL_Texture         *door;
    SDL_Texture         *Filler;
	SDL_Surface			*ssky;
	SDL_Surface			*sground;
	SDL_Rect			rsky;
	SDL_Rect			rsky2;
	SDL_Rect			rground;
}						t_game;

typedef struct			s_window
{
	SDL_Window			*window;
	SDL_Renderer			*rend;
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

typedef struct			s_acz	// ARCZURE
{
	t_window			*main;
	t_map				*map;
	t_inv				*inv;
	t_ray				*ray[XSCREEN];
	int					side[XSCREEN];
	t_info				*info;
	t_menu				*menu;
	t_menu				*option;
	t_game				*game;
	SDL_Event			ev;
	int					interface;
	Uint8				time;
	Uint8				time2;
	int					textbox;
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
	double				sensi;
	SDL_Rect            dst;
    SDL_Rect            src;
}						t_acz;

# include "prototype.h"

#endif

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <math.h>
# include "../libui/SDL2/SDL.h"
# include "../libui/SDL2/SDL_image.h"

# define	OBS		wn->perso->vue
# define	FOV		800
# define	FPS		60
# define	TRUE	1
# define	FALSE	0
# define	BOX		0
# define	GROUND	1
# define	END		2
# define	SPAWN	3
# define	KEY		4
# define	DOOR	5
# define	DOOR2	6

typedef struct		s_sprite
{
	int	w;
	int h;
	SDL_Texture *tex;
	int posx;
	int posy;
	double	dist;
}					t_sprite;

typedef struct		s_ray
{
	int i;
	int x;
	int y;
	int pasx;
	int pasy;
	int distx;
	int disty;
	double dist;
	double convdist;
	int side;
	int dx;
	int dy;
	int e;
	int pente;
}					t_ray;

typedef struct		s_mat
{
	double			mt[3][3];
}					t_mat;

typedef struct		s_point
{
	double			x;
	double			y;
	double			obs;
	double			obsother;
	double			other;
	double			facex;
	double			facey;
	double			ang;
	double			diff;
}					t_point;

typedef struct		s_inventory
{
	int				key;
	int				ammo;
	int				primary;
	int				second;
}					t_inventory;

typedef struct		s_perso
{
	int				range;
	double			posx;
	double			posy;
	double			vuex;
	double			vuey;
	t_inventory		*inv;
	t_point			*vue;
	t_mat			*collision;
}					t_perso;

typedef struct		s_debug
{
	SDL_Window		*wind;
	SDL_Surface		*surface;
	SDL_Event		ev;
	SDL_Renderer	*rend;
	SDL_Rect		obs;
}					t_debug;

typedef struct		s_editor
{
	SDL_Window		*wind;
	SDL_Surface		*surface;
	SDL_Event		ev;
	SDL_Renderer	*rend;
	SDL_Rect		block;
	int				xscreen;
	int				yscreen;
	int				x;
	int				y;
}					t_editor;

typedef struct		s_game
{
	SDL_Window		*wind;
	SDL_Surface		*win;
	SDL_Surface		*wall;
	SDL_Surface		*key;
	SDL_Event		ev;
	SDL_Renderer	*rend;
	SDL_Renderer	*Menu;
	SDL_Rect		obs;
	SDL_Rect		keys;
	SDL_Rect		screen;
	int				last_input;
}					t_game;

typedef struct		s_menu
{
	SDL_Surface		*surface;
	SDL_Texture		*bg;
	SDL_Texture		*arrow;
	SDL_Rect		info;
	SDL_Rect		pos;
	SDL_Event		ev;
	int				mode;
	int				difficulty;
}					t_menu;

typedef struct		s_win
{
	Uint32			time;
	Uint32			time2;
	t_debug			*debug;
	t_game			*game;
	t_mat			*matrice;
	t_perso			*perso;
	t_editor		*edit;
	t_menu			*menu;
	double			angx;
	double			angy;
	double			angz;
	int				editor;
	int				x;
	int				y;
	int				current;
	int				**map;
	int				xscreen;
	int				yscreen;
	int				dbug;
	float			movex;
	float			movey;
	int				pause;

	double			zbuf[FOV];
}					t_win;

void				initmenu(t_win *wn, t_menu *menu);
void				checkcollision(t_win *wn);
void				loadpng(SDL_Surface * surface, char *path);
void				save(t_win *wn);
SDL_Rect			*editrect(int x, int y);
void				edit(t_win *wn);
void				setedit(t_win *wn);
void				initedit(t_win **wn);
void				link1octant(t_win *wn);
void				linkredirect(t_win *wn);
void				setvue(t_win *wn, int current);
void				initvue(t_win *wn, int current);
void				stop_exec(void *str);
void				setuprect(SDL_Rect *rect, int load, t_win *wn);
void				setrect(t_win **wn, int x, int y, int value);
void				printscreen(t_win *wn);
void				parsemap(t_win *wn, void * path);
void				rotatexy(t_win *wn, t_mat *b);
void				rotatexz(t_win *wn, t_mat *b);
void				rotateyz(t_win *wn, t_mat *b);
void				initmatrice(t_mat *matrice);
void				calcmatrice(t_mat *m, t_mat *b);
void				rotatematrice(t_win *wn);
void				input(t_win *wn);
void				initinv(t_inventory **inv);
void				initgame(t_win **wn);
void				initwn(t_win **wn);
void				initsdl(t_win **wn);
int					game(t_win *wn);
int					main(int argc, char **argv);
void				raycast(t_win *wn);

#endif
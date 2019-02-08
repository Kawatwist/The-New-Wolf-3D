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

# define	TRUE	1
# define	FALSE	0
# define	XSCREEN	800
# define	YSCREEN	600
# define	DEG2RAD	0.0174532778

typedef struct			s_ray
{
	double				dst;
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
	double				persox;
	double				persoy;
}						t_map;

typedef struct			s_menu
{
	SDL_Surface			*background;
	SDL_Surface			*choices;
	SDL_Texture			*bg;
	SDL_Texture			*choice;
	int					mode;
	int					difficulty;
}						t_menu;

typedef struct			s_window
{
	SDL_Window			*window;
	SDL_Renderer		*rend;
	SDL_Surface			*background;
	SDL_Surface			*more;
	SDL_Rect			bgpos;
	SDL_Rect			morepos;
}						t_window;

typedef struct			s_acz	// ARCZURE
{
	t_window			*main;
	t_window			*twod;
	t_map				*map;
	t_inv				*inv;
	t_ray				*ray[XSCREEN];
	t_menu				*menu;
	int					twodactif;
}						t_acz;

# include "prototype.h"

#endif

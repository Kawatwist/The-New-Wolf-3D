#ifndef _PROTOTYPE_H
# define _PROTOTYPE_H

void		sort_sprite(t_sprite **sprite);
void		unlimitedmap(t_acz *az, t_dda *dda);
double		rotpos(t_acz *az, int portal);
void		newportail(t_acz *az, t_dda *dda, int portal);
void		dds(t_acz *az, t_dda *dda, int portal);
void		sprite_dist(t_acz *az);
void		load_sprites(t_acz *az);
void        draw_sprites(t_acz *az);
void		akframe(t_acz *az);
void		getenemypos(t_acz *az);
void		loadcompas(t_acz *az);
void		loadedittoreset(t_acz *az);
void		loadplaytoedit(t_acz *az);
void		loadeditoplay(t_acz *az);
SDL_Texture	*pick_texture(t_acz *az, int i);
void		changeray(t_acz *az, int portal);
void		setportal(t_acz *az, t_dda dda, int portal);
int			diffside(t_acz *az, t_dda *dda);
void		portalapply(t_acz *az, t_dda *dda, int portal);
void		printselect(t_acz *az);
int			ft_abs(int n);
void		parseselect(t_acz *az);
void		rectpos(t_acz *az);
void		printline(t_acz *az);
void		raycast(t_acz *az);
void		save_map(t_acz *az);
void		printgrill(t_acz *az);
void		map(t_acz *az);
void		showsky(t_acz *az);
void		loadgame(t_acz *az);
void		loadedit(t_acz *az);
void		loadmenu(t_acz *az);
void		loadoption(t_acz *az);
void		load_texture(SDL_Renderer *render, SDL_Texture **texture, char *path);
void		print(t_acz *az);
void		collision(t_acz* az);
void		input(t_acz *az);
void		running(t_acz **az);
void		map_parse(t_acz **az, char *name);
void		initialization(t_acz **az);
void		stop_exec(void	*msg);
int			main(int argc, char **argv);
int			get_side(t_dda *dda, t_acz *az);

#endif

#ifndef _PROTOTYPE_H
# define _PROTOTYPE_H

int		diffside(t_acz *az, t_dda *dda);
void		portalapply(t_dda *dda, int facediff, int x, int y);
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

#endif

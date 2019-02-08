#ifndef _PROTOTYPE_H
# define _PROTOTYPE_H

void		collision(t_acz* az);
void		input(t_acz *az);
void		running(t_acz **az);
void		map_parse(t_acz **az, char *name);
void		initialization(t_acz **az);
void		stop_exec(void	*msg);
int			main(int argc, char **argv);

#endif

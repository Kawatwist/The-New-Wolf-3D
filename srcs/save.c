#include "../includes/wolf3d.h"

static int		check_map(t_acz *az)
{
	int x;
	int y;

	y = -1;
	while (++y < 60)
	{
		x = -1;
		while (++x < 60)
			if (az->info->editmap[y][x] == 2)
				return (1);
	}
	return (0);
}

static char		*dupmapline(t_acz *az, int y)
{
	char *str;
	int		x;

	(str = (char *)malloc(sizeof(char) * 120)) == NULL ? stop_exec("str dont load\n") : 0;
	x = 0;
	while (x < 120)
	{
		str[x] = az->info->editmap[x / 2][y] + '0';
		str[x + 1] = ' ';
		x += 2;
	}
	str[x] = '\n';
	return (str);
}

void			save_map(t_acz *az)
{
	int		savefd;
	int		y;
	char	*str;

	if (!check_map(az))
	{
		ft_putstr("Map invalid\n");
		return ;
	}
	az->name_save = ft_strdup("mapsave\0");
	savefd = creat(az->name_save, O_CREAT | S_IRWXU | S_IRWXG | S_IRWXO | O_TRUNC);
	savefd < 0 ? stop_exec("Save failed\n") : 0;
	y = -1;
	while (++y < 60)
	{
		str = dupmapline(az, y);
		write(savefd, str, 120);
		write(savefd, "\n", 1);
		free(str);
	}
	printf("Map saved\n");
	close(savefd);
}

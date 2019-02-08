#include "libft.h"

char		*ft_strdupfree(char **str, char c)
{
	char *new;

	new = ft_strdup(ft_strchr(*str, c) + 1);
	if (new)
		free(*str);
	return (new);
}

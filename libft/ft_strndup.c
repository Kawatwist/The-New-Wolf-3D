#include "libft.h"

char	*ft_strndup(char *str, size_t len)
{
	char *ret;

	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = '\0';
	ft_strncpy(ret, str, len);
	return (ret);
}

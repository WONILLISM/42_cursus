#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ret;

	if (!s)
		return (0);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	len_s = ft_strlen(s);
	i = 0;
	while (i < len && start + i < len_s)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
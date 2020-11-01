#include "ft_printf.h"

t_container	init_container(void)
{
	t_container *container;

	container = (t_container *)malloc(sizeof(t_container));
	container->precision = NULL;
	container->width = NULL;
	return (container);
}

char		*set_container(int size, char padding_info)
{
	char	*container;

	if (!(*container = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(container, padding_info, size);
	container[size] = '\0';
	return (container);
}

void		free_container(t_container *c)
{
	if (c->precision)
		free(c->precision);
	if (c->width)
		free(c->width);
	free(c);
}
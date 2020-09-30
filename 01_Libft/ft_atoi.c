#include "libft.h"

long	ft_atoi(const char *str)
{
	long	sign;
	long	res;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	res = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}
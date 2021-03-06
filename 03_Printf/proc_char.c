/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:20:43 by wopark            #+#    #+#             */
/*   Updated: 2020/11/06 17:08:09 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_info *info, char *c_width)
{
	info->width--;
	if (info->width < 0)
		return ("");
	if (!(c_width = set_container(info->width, info->padding)))
		return (NULL);
	return (c_width);
}

static int	print_char(t_info *info, char c)
{
	t_container	*container;
	char		*res;

	if (info->precision > 0)
		return (_ERROR);
	container = init_container();
	if (!(res = process_width(info, container->width)))
	{
		free(container);
		return (_ERROR);
	}
	if (info->left == 1)
		info->n += ft_putchar(c) + ft_putstr(res);
	else
		info->n += ft_putstr(res) + ft_putchar(c);
	return (0);
}

int			process_char(va_list ap, t_info *info)
{
	char	c;

	c = (char)va_arg(ap, int);
	return (print_char(info, c));
}
/*
** %c는 정밀도 체크를 하지 않지만, '.'뒤에 아무것도 오지 않았을 때는 무시하여 처리한다.
*/

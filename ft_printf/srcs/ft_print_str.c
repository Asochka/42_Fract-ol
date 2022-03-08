/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:35:04 by smana             #+#    #+#             */
/*   Updated: 2021/11/12 17:35:06 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		ret++;
		s++;
	}
	return (ret);
}

int	ft_print_str(t_print *tab)
{
	char	*s;

	s = va_arg(tab->args, char *);
	return (ft_putstr(s));
}

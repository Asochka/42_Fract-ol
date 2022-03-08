/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:34:00 by smana             #+#    #+#             */
/*   Updated: 2021/11/12 17:34:02 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_char(t_print *tab)
{
	char	a;
	int		ret;

	ret = 0;
	a = va_arg(tab->args, int);
	ret = write(1, &a, 1);
	return (ret);
}

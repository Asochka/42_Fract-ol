/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:34:21 by smana             #+#    #+#             */
/*   Updated: 2021/11/12 17:34:23 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_int(t_print *tab)
{
	int	a;
	int	ret;

	ret = 0;
	a = va_arg(tab->args, int);
	ft_putnbr(a, &ret);
	return (ret);
}

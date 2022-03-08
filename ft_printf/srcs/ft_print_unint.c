/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:35:18 by smana             #+#    #+#             */
/*   Updated: 2021/11/12 17:35:20 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_unint(t_print *tab)
{
	unsigned int	a;
	int				ret;

	ret = 0;
	a = va_arg(tab->args, unsigned int);
	ft_putnbr_un(a, &ret);
	return (ret);
}

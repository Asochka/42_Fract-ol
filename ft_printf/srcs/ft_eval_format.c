/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:32:59 by smana             #+#    #+#             */
/*   Updated: 2021/11/12 17:33:01 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_eval_format(t_print *tab, const char *format, int i)
{
	int	ret;

	ret = 0;
	if (format[i] == 'c')
		ret = ft_print_char(tab);
	if (format[i] == 'd' || format[i] == 'i')
		ret = ft_print_int(tab);
	if (format[i] == 's')
		ret = ft_print_str(tab);
	if (format[i] == 'p')
		ret = ft_print_point(tab);
	if (format[i] == 'u')
		ret = ft_print_unint(tab);
	if (format[i] == 'x')
		ret = ft_print_lowhex(tab);
	if (format[i] == 'X')
		ret = ft_print_upphex(tab);
	if (format[i] == '%')
		ret = write(1, "%", 1);
	return (ret);
}

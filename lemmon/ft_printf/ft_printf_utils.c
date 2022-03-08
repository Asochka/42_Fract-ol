/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:49:29 by lemmon            #+#    #+#             */
/*   Updated: 2021/12/01 17:49:32 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(t_syntax *list, int f, char c)
{
	if (f == 1)
	{
		p_hex(va_arg(list->argc, unsigned long int), list);
	}
	else
	{
		h_hex(va_arg(list->argc, unsigned int), list, c);
	}
}

void	ft_print_int(t_syntax *list, int f)
{
	unsigned int	b;
	int				a;

	a = va_arg(list->argc, int);
	b = (unsigned int)a;
	if (f == 1)
		ft_putnbr(a, list);
	else
		ft_putnbr(b, list);
}

void	ft_print_str(t_syntax *list)
{
	char	*c;
	int		i;

	i = -1;
	c = va_arg(list->argc, void *);
	if (c)
	{
		while (*(c + ++i))
		{
			list->len += 1;
			ft_putchar(*(c + i));
		}
	}
	else
	{
		write(1, "(null)", 6);
		list->len += 6;
	}
}

void	ft_print_char(t_syntax *list)
{
	char	n;

	n = va_arg(list->argc, int);
	list->len += ft_putchar(n);
}

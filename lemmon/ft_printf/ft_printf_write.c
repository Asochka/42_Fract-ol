/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:07:04 by lemmon            #+#    #+#             */
/*   Updated: 2021/12/07 16:07:07 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	h_hex(unsigned long int b, t_syntax *list, char c)
{
	unsigned long int	tmp;

	tmp = b;
	if (tmp > 15)
	{
		h_hex(tmp / 16, list, c);
		h_hex(tmp % 16, list, c);
	}
	else
	{
		if (tmp <= 9)
		{
			ft_putchar(tmp + 48);
			list->len++;
		}
		else
		{
			if (c == 'x')
				ft_putchar(tmp - 10 + 'a');
			else
				ft_putchar(tmp - 10 + 'A');
			list-> len++;
		}
	}
}

void	p_hex(unsigned long int b, t_syntax *list)
{
	unsigned long int	tmp;

	tmp = b;
	if (tmp > 15)
	{
		p_hex(tmp / 16, list);
		p_hex(tmp % 16, list);
	}
	else
	{
		if (tmp <= 9)
		{
			ft_putchar(tmp + 48);
			list->len++;
		}
		else
		{
			ft_putchar(tmp - 10 + 'a');
			list-> len++;
		}
	}
}

void	ft_putnbr(long int a, t_syntax *list)
{
	long long int	tmp;

	tmp = a;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp = -tmp;
		list->len++;
	}
	if (tmp >= 0 && tmp <= 9)
	{
		ft_putchar(tmp + 48);
		list->len++;
	}
	else
	{
		ft_putnbr(tmp / 10, list);
		ft_putnbr(tmp % 10, list);
	}
}

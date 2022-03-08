/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:55:00 by lemmon            #+#    #+#             */
/*   Updated: 2021/11/30 11:56:11 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_conv(const char *str, t_syntax *list, int i)
{
	if (*(str + i) == 'c')
		ft_print_char(list);
	else if (*(str + i) == 's')
		ft_print_str(list);
	else if (*(str + i) == 'p')
	{
		write(1, "0x", 2);
		ft_print_hex(list, 1, str[i]);
		list->len += 2;
	}
	else if ((*(str + i) == 'd') || (*(str + i) == 'i'))
		ft_print_int(list, 1);
	else if (*(str + i) == 'u')
		ft_print_int(list, 0);
	else if (((*(str + i) == 'x')) || ((*(str + i) == 'X')))
		ft_print_hex(list, 0, str[i]);
	else if (*(str + i) == '%')
	{
		ft_putchar(*(str + i));
		list->len++;
	}
	return (list->len);
}

int	ft_eval_persant(t_syntax *list, const char *str)
{
	int	i;

	i = -1;
	while (*(str + ++i))
	{
		if ((*(str + i)) != '%')
		{
			write(1, &(*(str + i)), 1);
			list->len++;
		}
		else
		{
			i++;
			ft_eval_conv(str, list, i);
		}
	}
	return (list->len);
}

void	zerostruct(t_syntax *list)
{
	list->len = 0;
}

int	ft_printf(const char *str, ...)
{
	t_syntax	*list;
	int			counter;

	if (str == NULL)
		return (0);
	list = (t_syntax *)malloc(sizeof(t_syntax));
	if (!list)
		return (-1);
	zerostruct(list);
	va_start(list->argc, str);
	counter = ft_eval_persant(list, str);
	va_end(list->argc);
	free(list);
	return (counter);
}

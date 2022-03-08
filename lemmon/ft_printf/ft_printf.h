/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:55:52 by lemmon            #+#    #+#             */
/*   Updated: 2021/11/30 12:06:59 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>

typedef struct s_syntax
{
	va_list	argc;
	int		len;
}			t_syntax;

int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_eval_persant(t_syntax *list, const char *str);
int		ft_eval_conv(const char *str, t_syntax *list, int i);

void	ft_print_char(t_syntax *list);
void	ft_print_str(t_syntax *list);
void	ft_putnbr(long int a, t_syntax *va_list);
void	ft_print_int(t_syntax *list, int f);

void	ft_print_hex(t_syntax *list, int f, char c);
void	p_hex(unsigned long int b, t_syntax *list);
void	h_hex(unsigned long int b, t_syntax *list, char c);
void	zerostruct(t_syntax *list);

#endif
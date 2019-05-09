/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:31:54 by thallot           #+#    #+#             */
/*   Updated: 2019/05/09 12:09:24 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_print_string(va_list list, t_arg *arg)
{
	char *str;

	(void)arg;
	str = va_arg(list, char *);
	ft_putstr(str);
}

void	ft_print_char(va_list list, t_arg *arg)
{
	char c;

	(void)arg;
	c = va_arg(list, int);
	ft_putchar(c);
}

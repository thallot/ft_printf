/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:27:34 by thallot           #+#    #+#             */
/*   Updated: 2019/05/29 11:27:36 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_put_all(char c, int *n, int *i)
{
	while ((*n)-- > 0)
	{
		ft_putchar(c);
		(*i)++;
	}
}

int			ft_put(char c, int i)
{
	ft_putchar(c);
	i++;
	return (i);
}

int			ft_putter(char *c, int i)
{
	ft_putstr(c);
	i += ft_strlen(c);
	return (i);
}

int			set_exception(t_arg *arg, int n, int *p)
{
	exception_d(arg, &n, p);
	exception_u(arg, &n, p);
	if (arg->type == TYPE_O)
	{
		exception_o(arg, &n, p);
		if (arg->len - arg->precision == -1 && !arg->width && arg->nbr)
			*p = *p - 1;
		if (arg->width && arg->precision && arg->sharp
				&& *p > 0 && !arg->conv && arg->nbr)
		{
			*p = *p - 1;
			n = n + 1;
		}
		if (arg->width && arg->sharp && arg->nbr == 0
			&& !arg->flag_preci && !arg->minus && !arg->zero)
			n = n + 1;
	}
	exception_x(arg, &n, p);
	exception_f(arg, &n, p);
	if (arg->nbr == 0 && arg->zero && arg->width && !arg->plus)
		n--;
	return (n);
}

int			set_offset(int *len, t_arg *arg, intmax_t nb, int *p)
{
	int n;

	n = 0;
	if (arg->type == TYPE_D || arg->type == TYPE_I)
		*len -= (nb < 0) ? 1 : 0;
	*p = (arg->precision > *len) ? arg->precision - *len : 0;
	*len = (nb == 0 && arg->precision == 0) ? 0 : *len;
	n += arg->width - *len - *p;
	n = set_exception(arg, n, p);
	return (n);
}

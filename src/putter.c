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
	(i)++;
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
	if ((arg->type == TYPE_D || arg->type == TYPE_I)
			&& (arg->plus || arg->space || arg->minus)
			&& arg->zero && arg->nbr == 0)
		n--;
	if (arg->type == TYPE_U && (arg->plus || arg->space) && !arg->minus)
		n++;
	if (arg->type == TYPE_O && (arg->plus || arg->space))
		n++;
	if (arg->type == TYPE_O && arg->sharp && arg->nbr != 0)
		n--;
	if (arg->type == TYPE_O && arg->sharp && arg->precision > 0)
		n--;
	if (arg->type == TYPE_X && arg->sharp == 1 && arg->nbr != 0)
		n = n - 2;
	if (arg->type == TYPE_X && (arg->plus || arg->space))
		n++;
	if (arg->type == TYPE_XX && arg->sharp == 1 && arg->nbr != 0)
		n = n - 2;
	if (arg->type == TYPE_XX && (arg->plus || arg->space))
		n++;
	if (arg->nbr == 0 && arg->zero && arg->width && !arg->plus)
		n--;
	if (arg->sharp && arg->flag_preci && arg->type == TYPE_O)
		*p = *p - 1;
	return (n);
}

int			set_offset(int *len, t_arg *arg, intmax_t nb, int *p)
{
	int n;

	if (arg->type == TYPE_D || arg->type == TYPE_I)
		*len -= (nb < 0) ? 1 : 0;
	*p = (arg->precision > *len) ? arg->precision - *len : 0;
	*len = (nb == 0 && arg->precision == 0) ? 0 : *len;
	n = arg->width - *len - *p;
	n -= (arg->plus || arg->space || nb < 0) ? 1 : 0;
	n = set_exception(arg, n, p);
	return (n);
}

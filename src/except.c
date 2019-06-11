/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:53:39 by thallot           #+#    #+#             */
/*   Updated: 2019/06/11 14:13:17 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	exception_d(t_arg *arg, int *n, int *p)
{
	if (arg->type != TYPE_D && arg->type != TYPE_I)
		return ;
	*n -= (arg->plus || arg->space || arg->nbr < 0) ? 1 : 0;
	if (arg->plus && arg->zero && arg->nbr == 0)
		*n = *n - 1;
	if (arg->len == arg->width && !arg->flag_preci)
		*n = *n - 1;
	if (arg->len == 1 && arg->width > 1 && !arg->zero)
		*n = *n - 1;
	if (arg->width > 1 && arg->flag_preci && arg->nbr == 0)
		*n = *n + 1;
	if (arg->type == TYPE_I)
	{
		if (arg->len == 1 && arg->flag_preci && arg->width == 1
				&& arg->width > 1 && !arg->plus)
			*n = *n - 1;
		if (arg->len == 1 && arg->flag_preci && arg->width > 1
				&& arg->width > 1 && !arg->plus && arg->zero)
			*n = *n - 1;
	}
	if (arg->zero && arg->flag_preci)
		arg->zero = 0;
	if (arg->width && arg->len == 1 && arg->nbr != 0)
		(*n)++;
	(void)*p;
}

void	exception_u(t_arg *arg, int *n, int *p)
{
	if (arg->type != TYPE_U)
		return ;
	if (arg->len == arg->width)
		*n = *n - 1;
	if (arg->len == 1 && arg->width == 1 && arg->flag_preci && !arg->precision)
		*n = *n + 1;
	if (arg->len == 1 && arg->width > 1 && !arg->flag_preci)
		*n = *n - 1;
	if (arg->len == 1 && arg->width > 1 && !arg->flag_preci && arg->zero)
		*n = *n + 1;
	if (arg->plus && arg->minus && arg->width)
		*n = *n - 1;
	(void)*p;
}

void	exception_o(t_arg *arg, int *n, int *p)
{
	if ((arg->len == arg->width) || (arg->sharp && arg->nbr != 0))
		*n = *n - 1;
	if (arg->len == 1 && arg->width == 1 && arg->flag_preci && !arg->precision)
		*n = *n + 1;
	if (arg->len == 1 && arg->width > 1 && !arg->flag_preci)
		*n = *n - 1;
	if (arg->len == 1 && arg->width > 1 && !arg->flag_preci && arg->zero)
		*n = *n + 1;
	if (arg->sharp && arg->flag_preci && arg->len == 1 && !arg->precision)
		arg->sign = 1;
	if (arg->sharp && arg->len == 1 && arg->width)
	{
		*n = *n - 1;
		if ((arg->precision > 0 && arg->flag_preci && arg->len < arg->width)
				|| (arg->minus && !arg->flag_preci)
				|| (arg->zero && !arg->flag_preci))
			*n = *n + 1;
	}
	if (arg->sharp && arg->width && arg->precision && arg->conv == MODIFIER_HH)
		*n = *n + 1;
	if (arg->sharp && arg->precision && arg->conv)
		*p = *p - 1;
	if (arg->len - arg->precision == -1 && !arg->width && arg->nbr)
		*p = *p - 1;
}

void	exception_x(t_arg *arg, int *n, int *p)
{
	if (arg->type != TYPE_X && arg->type != TYPE_XX)
		return ;
	if (arg->sharp == 1 && arg->nbr != 0)
		*n = *n - 2;
	if (arg->len == arg->width)
		*n = *n - 1;
	if (arg->len == 1 && arg->width == 1 && arg->flag_preci && !arg->precision)
		*n = *n + 1;
	if (arg->len == 1 && arg->width > 1 && !arg->flag_preci)
		*n = *n - 1;
	if (arg->len == 1 && arg->width > 1 && !arg->flag_preci && arg->zero)
		*n = *n + 1;
	(void)*p;
}

void	exception_f(t_arg *arg, int *n, int *p)
{
	if (arg->type != TYPE_F)
		return ;
	if (arg->space && arg->nbr == 0)
		*n = *n + 1;
	if (arg->plus && arg->nbr == 0)
		*n = *n - 1;
	(void)*p;
}

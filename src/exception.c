/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:56:08 by thallot           #+#    #+#             */
/*   Updated: 2019/06/11 13:11:55 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		exep_oct(t_arg *arg)
{
	if ((uintmax_t)arg->nbr == ULONG_MAX)
	{
		arg->value = ft_strdup("1777777777777777777777");
		arg->len = 22;
		return (arg->len);
	}
	return (0);
}

int		exep_hex(t_arg *arg)
{
	if ((uintmax_t)arg->nbr == ULLONG_MAX)
	{
		arg->value = ft_strdup("ffffffffffffffff");
		arg->len = 16;
		return (arg->len);
	}
	return (0);
}

int		exep_hexx(t_arg *arg)
{
	if ((uintmax_t)arg->nbr == ULLONG_MAX)
	{
		arg->value = ft_strdup("FFFFFFFFFFFFFFFF");
		arg->len = 16;
		return (arg->len);
	}
	return (0);
}

int		exep_int(t_arg *arg)
{
	if (arg->nbr == LONG_MIN)
	{
		arg->value = ft_strdup("9223372036854775808");
		arg->len = 17;
		return (arg->len);
	}
	return (0);
}

void	exception_o2(t_arg *arg, int *n, int *p)
{
	if (!arg->flag && arg->width > 1 && arg->nbr
			&& arg->len == 1 && !arg->flag_preci)
		*n = *n + 1;
	*p -= (arg->sharp && arg->precision && arg->conv) ? 1 : 0;
	if (arg->sharp && arg->width && arg->precision && arg->conv == MODIFIER_HH)
		*n = *n + 1;
	if (arg->sharp && arg->width && arg->precision && arg->conv && !arg->nbr)
		*p = *p + 1;
	if (arg->sharp && arg->width && arg->precision && arg->conv && !arg->nbr)
		*p = *p + 1;
	if (arg->sharp && arg->precision && !arg->width && arg->nbr && !arg->conv)
		*p = *p - 1;
	*p -= (arg->sharp && arg->width && arg->plus && arg->minus) ? 1 : 0;
	*n += (arg->plus && arg->minus && arg->nbr && arg->len == 1) ? 1 : 0;
	*p += (arg->precision && !arg->nbr && !arg->width && arg->conv) ? 1 : 0;
	if (arg->precision && !arg->nbr && !arg->width && arg->conv && !arg->flag)
		*p = *p - 1;
	if (arg->precision && !arg->nbr && arg->sharp && arg->conv && arg->width)
	{
		*p = *p - 1;
		*n = *n - 1;
	}
	if (arg->width > 1 && arg->zero
			&& !arg->nbr && arg->width > 1 && arg->plus)
		*n = *n - 1;
}

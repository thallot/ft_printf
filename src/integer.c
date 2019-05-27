/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:41:10 by thallot           #+#    #+#             */
/*   Updated: 2019/05/21 11:36:23 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_flag_int(t_arg *arg)
{
	int len;
	int max;
	int p;
	int i;

	i = 0;
	len = arg->len;
	max = set_offset(&len, arg, arg->nbr, &p);
	if (!arg->minus && (arg->precision || !arg->zero))
		ft_put_all(' ', &max, &i);
	if (arg->nbr < 0)
		i = ft_put('-', i);
	else if (arg->plus)
		i = ft_put('+', i);
	else if (arg->space)
		i = ft_put(' ', i);
	if (arg->precision)
		ft_put_all('0', &p, &i);
	else if (!arg->minus && arg->zero)
		ft_put_all('0', &max, &i);
	if (!(arg->nbr == 0 && arg->flag_preci == 1 && arg->precision == 0))
		ft_putnbr_max(arg->nbr);
	else
		i--;
	ft_put_all(' ', &max, &i);
	arg->len = len == 0 ? i + 1 : i + len;
}

void	set_flag_uint(t_arg *arg)
{
	int len;
	int max;
	int p;
	int i;

	i = 0;
	len = arg->len;
	max = set_offset(&len, arg, arg->nbr, &p);
	if (!arg->minus && (arg->precision || !arg->zero))
		ft_put_all(' ', &max, &i);
	if (arg->precision)
		ft_put_all('0', &p, &i);
	else if (!arg->minus && arg->zero)
		ft_put_all('0', &max, &i);
	if (!(arg->nbr == 0 && arg->flag_preci == 1 && arg->precision == 0))
		ft_putnbr_max(arg->nbr);
	else
		i--;
	ft_put_all(' ', &max, &i);
	len == 0 ? len = 1 : len;
	arg->len = i + len;
}

void	set_flag_oct(t_arg *arg)
{
	int len;
	int max;
	int p;
	int i;

	i = 0;
	len = arg->len;
	max = set_offset(&len, arg, arg->nbr, &p);
	if (!arg->minus && (arg->precision || !arg->zero))
		ft_put_all(' ', &max, &i);
	if (arg->sharp == 1)
		i = ft_put('0', i);
	else if (arg->plus)
		i = ft_put('+', i);
	else if (arg->space)
		i = ft_put(' ', i);
	if (arg->precision)
		ft_put_all('0', &p, &i);
	else if (!arg->minus && arg->zero)
		ft_put_all('0', &max, &i);
	if (!(arg->nbr == 0 && arg->flag_preci == 1 && arg->precision == 0))
		ft_putstr(arg->value);
	else
		i--;
	ft_put_all(' ', &max, &i);
	arg->len = len == 0 ? i + 1 : i + len;
}

void	set_flag_hex(t_arg *arg)
{
	int len;
	int max;
	int p;
	int i;

	i = 0;
	len = arg->len;
	max = set_offset(&len, arg, arg->nbr, &p);
	if (!arg->minus && (arg->precision || !arg->zero))
		ft_put_all(' ', &max, &i);
	if (arg->sharp == 1 && arg->nbr != 0)
	{
		i = ft_put('0', i);
		i = ft_put('x', i);
	}
	else if (arg->plus)
		i = ft_put('+', i);
	else if (arg->space)
		i = ft_put(' ', i);
	if (arg->precision)
		ft_put_all('0', &p, &i);
	else if (!arg->minus && arg->zero)
		ft_put_all('0', &max, &i);
	if (!(arg->nbr == 0 && arg->flag_preci == 1 && arg->precision == 0))
	{
		ft_putstr(arg->value);
	}
	else
		i--;
	ft_put_all(' ', &max, &i);
	len == 0 ? len = 1 : len;
	arg->len = i + len;
	ft_memdel((void **)&(arg)->value);
}

void	set_flag_hexx(t_arg *arg)
{
	int len;
	int max;
	int p;
	int i;

	i = 0;
	len = arg->len;
	max = set_offset(&len, arg, arg->nbr, &p);
	if (!arg->minus && (arg->precision || !arg->zero))
		ft_put_all(' ', &max, &i);
	if (arg->sharp == 1 && arg->nbr != 0)
	{
		i = ft_put('0', i);
		i = ft_put('X', i);
	}
	else if (arg->plus)
		i = ft_put('+', i);
	else if (arg->space)
		i = ft_put(' ', i);
	if (arg->precision)
		ft_put_all('0', &p, &i);
	else if (!arg->minus && arg->zero)
		ft_put_all('0', &max, &i);
	if (!(arg->nbr == 0 && arg->flag_preci == 1 && arg->precision == 0))
	{
		ft_putstr(arg->value);
	}
	else
		i--;
	ft_put_all(' ', &max, &i);
	len == 0 ? len = 1 : len;
	arg->len = i + len;
	ft_memdel((void **)&(arg)->value);
}

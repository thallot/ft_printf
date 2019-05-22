/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:37:16 by thallot           #+#    #+#             */
/*   Updated: 2019/05/21 11:27:25 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_len_int(intmax_t nb)
{
	int len;
	intmax_t n;

	len = 1;
	if (nb == LLONG_MIN)
		return (20);
	if (nb == LLONG_MAX)
		return (19);
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		n = -nb;
	}
	else
		n = nb;
	while (n > 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_max(long long int nb)
{
	uintmax_t z;

	if (nb == LLONG_MIN)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (nb == LLONG_MAX)
	{
		ft_putstr("9223372036854775807");
		return ;
	}
	if (nb < 0)
		z = -nb;
	else
		z = nb;
	if (z >= 10)
		ft_putnbr(z / 10);
	ft_putchar((z % 10) + 48);
}

void		ft_put_all(char c, int *n, int *i)
{
	while ((*n)-- > 0)
	{
		ft_putchar(c);
		(*i)++;
	}
}

int		ft_put(char c, int i)
{
	ft_putchar(c);
	(i)++;
	return (i);
}

int		set_offset(int *len, t_arg *arg, intmax_t num, int *p)
{
	int n;

	*len -= (num < 0) ? 1 : 0;
	*p = (arg->precision - *len > 0) ? arg->precision - *len : 0;
	*len = (num == 0 && arg->precision == 0) ? 0 : *len;
	n = arg->width - *len - *p;
	n -= (arg->plus || arg->space ||num < 0) ? 1 : 0;
	if (arg->type == TYPE_O && arg->sharp == 1)
		n--;
	if (arg->type == TYPE_X && arg->sharp == 1)
		n = n - 2;
	if (arg->type == TYPE_XX && arg->sharp == 1)
		n = n - 2;
	return (n);
}

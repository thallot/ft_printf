/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:37:16 by thallot           #+#    #+#             */
/*   Updated: 2019/05/29 11:14:03 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			get_len_int(intmax_t nb)
{
	int			len;
	intmax_t	n;

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
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void		ft_putnbr_max(long long int nb)
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

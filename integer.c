/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:41:10 by thallot           #+#    #+#             */
/*   Updated: 2019/05/09 13:17:51 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		get_len_int(int nb)
{
	int len;
	unsigned int n;

	len = 1;
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

void	ft_print_int(va_list list, t_arg *arg)
{
	int nb;
	int	len;
	int	len_arg;

	len = arg->precision;
	nb = va_arg(list, int);
	len_arg = get_len_int(nb);
	len_arg > arg->precision ? arg->precision = len_arg : arg->precision;
	if (arg->plus == 1 && arg->type == TYPE_D)
	{
		len++;
		nb < 0 ? ft_putchar('-') : ft_putchar('+');
	}
	if (arg->plus != 1 && arg->space == 1 && arg->type == TYPE_D && nb > 0)
	{
		len++;
		ft_putchar(' ');
	}
	while (len-- > len_arg)
		arg->zero == 0 ? ft_putchar(' ') : ft_putchar('0');
	ft_putnbr(nb);
}

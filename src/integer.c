/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:41:10 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 14:03:03 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_len_int(intmax_t nb)
{
	int len;
	intmax_t n;

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

t_arg	*set_flag_int(t_arg *arg, intmax_t nb)
{
	int len;

	len = ft_strlen(arg->value);
	while (arg->precision > len++)
		arg->value = ft_cjoin('0', arg->value);
	len = ft_strlen(arg->value);
	arg->plus == 1 ? len++ : len;
	if (arg->width > 0)
	{
		while (len++ < arg->width)
		{
			if (arg->minus == 1)
				arg->value = ft_joinc(arg->value, ' ');
			else if (arg->zero == 1 && arg->minus == 0 && nb > 0)
				arg->value = ft_cjoin('0', arg->value);
			else
				arg->value = ft_cjoin(' ', arg->value);
			if (len  == arg->width && arg->plus == 1)
			{
				arg->value = ft_cjoin('+', arg->value);
				len++;
			}
		}
	}
	else
	{
		if (arg->plus == 1 && arg->type == TYPE_D && nb >= 0)
			arg->value = ft_cjoin('+', arg->value);
		if (arg->plus != 1 && arg->space == 1 && arg->type == TYPE_D && nb > 0)
			arg->value = ft_cjoin(' ', arg->value);
	}
	return (arg);
}

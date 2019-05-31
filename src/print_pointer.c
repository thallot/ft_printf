/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:25:42 by thallot           #+#    #+#             */
/*   Updated: 2019/05/29 12:02:15 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_pointer(va_list list, t_arg *arg)
{
	arg->nbr = va_arg(list, uintmax_t);
	if (arg->nbr != 0 || arg->width > 0 || arg->precision)
	{
		ft_itoa_base_unsll(16, arg);
		arg->len = ft_strlen(arg->value) + 2;
		set_flag_point(arg, arg->len);
		ft_memdel((void **)&(arg)->value);
	}
	else if (arg->flag_preci == 1)
	{
		ft_putstr("0x");
		arg->len = 2;
	}
	else
	{
		ft_putstr("0x0");
		arg->len = 3;
	}
	return (arg->len);
}

void	set_flag_point(t_arg *arg, int len)
{
	int i;

	i = 0;
	while (i < arg->width - len && arg->minus == 0)
	{
		ft_putchar(' ');
		i++;
	}
	if (!(arg->nbr == 0 && arg->flag_preci == 1 && arg->precision == 0))
	{
		ft_putstr("0x");
		while (i < arg->precision - len + 2)
		{
			ft_putchar('0');
			i++;
		}
		ft_putstr(arg->value);
	}
	while (i < arg->width - len && arg->minus == 1)
	{
		ft_putchar(' ');
		i++;
	}
	arg->len = len == 0 ? i + 1 : i + len;
}

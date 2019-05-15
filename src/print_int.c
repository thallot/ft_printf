/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:55:14 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 15:29:30 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_int(va_list list, t_arg *arg)
{
	arg->nbr = convert_arg(arg, list);
	arg = caster_int(arg);
	arg->value = ft_itoa(arg->nbr);
	arg = set_flag_int(arg, arg->nbr);
	return (0);
}

int		ft_print_hex(va_list list, t_arg *arg)
{
	int				nb;
	char			*nbr;

	nb = convert_arg(arg, list);
	arg->nbr = nb;
	arg = caster_int(arg);
	nbr = ft_itoa_base_x(arg->nbr, 16);
	arg->value = nbr;
	if (arg->sharp == 1 && nb > 0)
	{
		arg->value = ft_strjoin("0x", arg->value);
	}
	return(0);
}

int		ft_print_hexx(va_list list, t_arg *arg)
{
	int				nb;
	char			*nbr;

	nb = convert_arg(arg, list);
	nbr = ft_itoa_base_xx(nb, 16);
	arg->value = nbr;
	if (arg->sharp == 1 && nb > 0)
	{
		arg->value = ft_strjoin("0X", arg->value);
	}
	return(0);
}

int		ft_print_oct(va_list list, t_arg *arg)
{
	arg->nbr = convert_arg(arg, list);
	arg = caster_int(arg);
	arg->value = ft_itoa_base_x(arg->nbr, 8);
	arg = set_flag_int(arg, arg->nbr);
	return(0);
}

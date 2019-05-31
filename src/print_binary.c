/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:24:48 by thallot           #+#    #+#             */
/*   Updated: 2019/05/30 16:24:49 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_binary(va_list list, t_arg *arg)
{
	arg->nbr = convert_arg(arg, list);
	arg = caster_int(arg);
	if (!exep_oct(arg))
	{
		if (arg->conv == MODIFIER_LL)
			ft_itoa_base_unsll(2, arg);
		else if (arg->conv == MODIFIER_L)
			ft_itoa_base_unsl(2, arg);
		else
			ft_itoa_base_uns(2, arg);
	}
	set_flag_oct(arg, arg->len);
	ft_memdel((void**)&(arg)->value);
	return (arg->len);
}

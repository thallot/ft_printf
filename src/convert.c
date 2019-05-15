/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:07:35 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 14:59:03 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	convert_arg(t_arg *arg, va_list list)
{
	intmax_t	nb;

	if (arg->conv == MODIFIER_L)
		nb = (long)va_arg(list, long);
	else if (arg->conv == MODIFIER_LL)
		nb = (long long)va_arg(list, long long);
	else if (arg->conv == MODIFIER_HH)
		nb = (char)va_arg(list, int);
	else if (arg->conv == MODIFIER_H)
		nb = (short)va_arg(list, int);
	else
		nb = va_arg(list, int);
	return (nb);
}

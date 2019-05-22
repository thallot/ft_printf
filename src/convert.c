/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:07:35 by thallot           #+#    #+#             */
/*   Updated: 2019/05/17 10:44:14 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	convert_arg(t_arg *arg, va_list list)
{
	intmax_t	nb;

	if (arg->type == TYPE_O || arg->type == TYPE_U || arg->type == TYPE_X
			|| arg->type == TYPE_XX)
	{
		if (arg->conv == MODIFIER_L)
			nb = (unsigned long int)va_arg(list, unsigned long int);
		else if (arg->conv == MODIFIER_LL)
			nb = (uintmax_t)va_arg(list, uint64_t);
		else if (arg->conv == MODIFIER_HH)
			nb = (unsigned char)va_arg(list, int);
		else if (arg->conv == MODIFIER_H)
			nb = (unsigned short int)va_arg(list, int);
		else
			nb = va_arg(list, unsigned int);
	}
	else
	{
		if (arg->conv == MODIFIER_L)
			nb = (long int)va_arg(list, long int);
		else if (arg->conv == MODIFIER_LL)
			nb = (long long int)va_arg(list, long long int);
		else if (arg->conv == MODIFIER_HH)
			nb = (char)va_arg(list, int);
		else if (arg->conv == MODIFIER_H)
			nb = (short int)va_arg(list, int);
		else
			nb = va_arg(list, int);
	}
	return (nb);
}

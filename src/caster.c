/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:51:58 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 14:58:44 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_arg	*caster_int(t_arg *arg)
{
	arg->conv == MODIFIER_H ? arg->nbr = (short)arg->nbr : arg->nbr;
	arg->conv == MODIFIER_HH ? arg->nbr = (char)arg->nbr : arg->nbr;
	arg->conv == MODIFIER_L ? arg->nbr = (long)arg->nbr : arg->nbr;
	arg->conv == MODIFIER_LL ? arg->nbr = (long long)arg->nbr : arg->nbr;
	return (arg);
}

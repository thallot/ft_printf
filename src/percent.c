/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:55:57 by thallot           #+#    #+#             */
/*   Updated: 2019/05/13 14:40:26 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_percent(va_list list, t_arg *arg)
{
	int		i;

	i = 0;
	va_arg(list, char *);
	arg->value = ft_strdup("%");
	if (arg->width > 0)
	{
		while (i++ < arg->width - 1)
		{
			if (arg->minus == 1)
				arg->value = ft_joinc(arg->value, ' ');
			else
				arg->value = ft_cjoin(' ', arg->value);
		}
	}
	return (0);
}

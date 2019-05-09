/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:37:48 by thallot           #+#    #+#             */
/*   Updated: 2019/05/09 12:31:31 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_print(char *str, va_list list)
{
	int		i;
	int		len;
	t_arg	*arg;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = 0;
			ft_putnstr(str, i);
			arg = get_arg(&str[i], &len);
			printf("--Type : %d, Sh/z/p/m/s : %d/%d/%d/%d/%d len : %d Precision : %d --\n ", 
			arg->type, arg->sharp, arg->zero, arg->plus, arg->minus, arg->space,
			len, arg->precision);
			ft_print_value(list, arg);
			str = str + len + i + 1;
			i = 0;
		}
		i++;
	}
	ft_putstr(str);
}

void	ft_print_value(va_list list, t_arg *arg)
{
	unsigned int	uns_int;

	if (arg->type == TYPE_D)
		ft_print_int(list, arg);
	else if (arg->type == TYPE_S)
		ft_print_string(list, arg);
	else if (arg->type == TYPE_C)
		ft_print_char(list, arg);
	else if (arg->type == TYPE_O)
	{

	}
	else if (arg->type == TYPE_U)
	{
		uns_int = va_arg(list, unsigned int);
		ft_putnbr(uns_int);
	}
	else if (arg->type == TYPE_X)
	{

	}
	else if (arg->type == TYPE_XX)
	{
	}
	else if (arg->type == TYPE_F)
	{
	}
	else if (arg->type == TYPE_PERCENT)
	{
	}
}

int		ft_get_nb_arg(char *str)
{
	int		i;
	int		count;
	t_arg	*arg;
	int		len;

	len = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i++] == '%')
		{
			if ((arg = get_arg(str, &len)) != NULL)
				count++;
		}
	}
	return (count);
}


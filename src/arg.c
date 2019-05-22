/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:37:48 by thallot           #+#    #+#             */
/*   Updated: 2019/05/17 14:22:38 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print(char *str, va_list list)
{
	int		i;
	int		count;
	int		len;
	t_arg	*arg;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = 1;
			arg = get_arg(&str[i], &len);
			if (arg->type != -1)
			{
				arg->len = 0;
				count += ft_print_value(list, arg);
				str = str + len + i;
				i = 0;
			}
			else
				i = i + arg->len - 1;
			/*printf("--Type : %d, W : %lld Sh/z/p/m/s : %d/%d/%d/%d/%d len : %d (%d) Precision : %lld conv %d --\n",
			arg->type, arg->width, arg->sharp, arg->zero, arg->plus, arg->minus, arg->space,
			len, arg->flag_preci,  arg->precision, arg->conv);*/
			free_arg(arg);
		}
		else
		{
			i = ft_put(str[i], i);
			count++;
		}
	}
	return (count);
}

int		ft_print_value(va_list list, t_arg *arg)
{
	int				ret;

	ret = 0;
	if (arg->type == TYPE_D)
		ret = ft_print_int(list, arg);
	else if (arg->type == TYPE_S)
		ret = ft_print_string(list, arg);
	else if (arg->type == TYPE_C)
		ret = ft_print_char(list, arg);
	else if (arg->type == TYPE_O)
		ret = ft_print_oct(list, arg);
	else if (arg->type == TYPE_U)
		ret = ft_print_unsigned(list, arg);
	else if (arg->type == TYPE_X)
		ret = ft_print_hex(list, arg);
	else if (arg->type == TYPE_XX)
		ret = ft_print_hexx(list, arg);
	else if (arg->type == TYPE_F)
	{
	}
	else if (arg->type == TYPE_PERCENT)
		ret = ft_print_percent(arg);
	else if (arg->type == -1)
		return (0);
	return (ret);
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

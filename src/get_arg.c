/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:27:42 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 10:10:28 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_arg	*get_arg(char *str, int *len)
{
	t_arg	*arg;

	if (!(arg = (t_arg *)ft_memalloc(sizeof(t_arg))))
		return (NULL);
	arg = get_width(str, arg);
	arg = get_flag(str, arg, len);
	arg = get_precision(str, arg);
	arg = get_type(str, arg, len);
	arg->len = *len;
	return (arg);
}

t_arg	*get_width(char *str, t_arg *arg)
{
	int i;

	i = 1;
	while ((ft_isdigit(str[i]) != 1 && is_valid_type(str[i]) == 0) 
			|| (str[i] == '0'))
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		arg->width = arg->width * 10 + (str[i] - '0');
		i++;
	}
	return (arg);
}

t_arg	*get_flag(char *str, t_arg *arg, int *i)
{
	while (is_valid_type(str[*i]) == 0 && str[*i] != '\0')
	{
		str[*i] == '-' ? arg->minus = 1 : arg->minus;
		str[*i] == '+' ? arg->plus = 1 : arg->plus;
		str[*i] == '#' ? arg->sharp = 1 : arg->sharp;
		if (str[*i] == '0' && ft_isdigit(str[*i - 1]) == 0)
			arg->zero = 1;
		str[*i] == ' ' ? arg->space = 1 : arg->space;
		str[*i] == '.' ? arg->flag_preci = 1 : arg->flag_preci;
		if (is_valid_lh(str[*i], str[*i + 1]))
		{
			str[*i] == 'h' ? arg->conv = MODIFIER_HH : arg->conv;
			str[*i] == 'l' ? arg->conv = MODIFIER_LL : arg->conv;
		}
		if (arg->conv == 0)
		{
			str[*i] == 'h' ? arg->conv = MODIFIER_H : arg->conv;
			str[*i] == 'l' ? arg->conv = MODIFIER_L : arg->conv;
		}
		if (is_valid(str[*i]) == 0)
			arg->error = 1;
		*i = *i + 1;
	}
	return (arg);
}

t_arg	*get_type(char *str, t_arg *arg, int *i)
{
	str[*i] == 'd' ? arg->type = TYPE_D : arg->type;
	str[*i] == 'i' ? arg->type = TYPE_D : arg->type;
	str[*i] == 'o' ? arg->type = TYPE_O : arg->type;
	str[*i] == 'u' ? arg->type = TYPE_U : arg->type;
	str[*i] == 'x' ? arg->type = TYPE_X : arg->type;
	str[*i] == 'X' ? arg->type = TYPE_XX : arg->type;
	str[*i] == 'c' ? arg->type = TYPE_C : arg->type;
	str[*i] == 's' ? arg->type = TYPE_S : arg->type;
	str[*i] == 'p' ? arg->type = TYPE_P : arg->type;
	str[*i] == '%' ? arg->type = TYPE_PERCENT : arg->type;
	*i = *i + 1;
	return (arg);
}

t_arg	*get_precision(char *str, t_arg *arg)
{
	int i;

	i = 1;
	while (is_valid_type(str[i]) == 0 && str[i] != '\0')
	{
		if(str[i] == '.')
		{
			i++;
			while (ft_isdigit(str[i]))
			{
				arg->precision = arg->precision * 10 + (str[i] - '0');
				i++;
			}
		}
		i++;
	}
	return (arg);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:31:54 by thallot           #+#    #+#             */
/*   Updated: 2019/05/14 13:08:09 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_string(va_list list, t_arg *arg)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = va_arg(list, char *);
	arg->value = str;
	if (arg->value == NULL)
	{
		arg->value = ft_strdup("(null)");
		return (0);
	}
	len = ft_strlen(str);
	if (arg->precision > 0 && arg->precision < len && arg->value[0] != '\0')
	{
		arg->value = ft_strsub(arg->value, 0 , arg->precision);
		len = ft_strlen(arg->value);
	}
	if (arg->width > 0)
	{
		while (len++ < arg->width)
		{
			if (arg->minus == 1)
				arg->value = ft_joinc(arg->value, ' ');
			else
				arg->value = ft_cjoin(' ', arg->value);
		}
	}
	return (0);
}

int		ft_print_char(va_list list, t_arg *arg)
{
	char 	c;
	char	*str;
	int		i;

	i = 0;
	c = va_arg(list, int);
	str = ft_memalloc(sizeof(char) * 2);
	str[0] = c;
	arg->value = str;
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
	return (1);
}

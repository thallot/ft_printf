/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:57:11 by thallot           #+#    #+#             */
/*   Updated: 2019/05/30 16:19:56 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		set_flag_float(t_arg *arg, int preci, char *intp, char *decip)
{
	int len;
	int i;
	int x;

	i = 0;
	x = 0;
	len = ft_strlen(intp) + ft_strlen(decip) + 1;
	if (arg->plus || arg->sign)
		i = arg->sign == 1 ? ft_put('-', i) : ft_put('+', i);
	ft_putstr(intp);
	if (preci || arg->sharp)
		ft_putchar('.');
	if (preci != 0)
		ft_putstr(decip);
	while (arg->width - len > x++ + 1)
		i = arg->zero || intp[0] == '0' ? ft_put('0', i) : ft_put(' ', i);
	return (len + i);
}

int		ft_print_float(va_list list, t_arg *arg)
{
	long double					nbr;
	int							i;
	int							k;
	char						*intp;
	char						*floatp;

	k = 1;
	arg->precision = arg->flag_preci == 1 ? arg->precision : 6;
	nbr = va_arg(list, double);
	if (nbr < 0)
	{
		arg->sign = 1;
		nbr *= -1;
	}
	if (arg->precision == 0 && (nbr - (signed long int)nbr) >= 0.5)
		nbr += 1;
	intp = ft_itoa((signed long int)nbr);
	nbr -= (signed long int)nbr;
	i = arg->precision;
	while (i--)
		k *= 10;
	nbr *= k;
	floatp = ft_itoa((signed long int)(nbr + 0.5));
	while (ft_strlen(floatp) < (size_t)arg->precision)
		floatp = ft_joinc(floatp, '0');
	arg->len = set_flag_float(arg, arg->precision, intp, floatp);
	ft_memdel((void**)&intp);
	ft_memdel((void**)&floatp);
	ft_memdel((void**)&(arg)->value);
	return (arg->len);
}

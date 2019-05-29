/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:57:11 by thallot           #+#    #+#             */
/*   Updated: 2019/05/29 11:33:31 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	reverse(char *str, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int		ft_itoa_float(int x, char str[], int d)
{
	int i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

void	ftoa(float n, char *res, int preci)
{
	int		ipart;
	float	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (float)ipart;
	i = ft_itoa_float(ipart, res, 0);
	if (preci != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_pow(10, preci);
		ft_itoa_float((int)fpart, res + i + 1, preci);
	}
}

int		get_len_float(float nb)
{
	int len;

	len = 1;
	if (nb == 0)
		return (len);
	while (nb > 10)
	{
		len++;
		nb = nb / 10;
		if (len > 300)
			break ;
	}
	return (len);
}

int		ft_print_float(va_list list, t_arg *arg)
{
	float	nbr;
	char	tab[308];
	int		len;
	int		preci;

	nbr = (float)va_arg(list, double);
	if (nbr < 0)
	{
		nbr = -nbr;
		arg->sign = 1;
		ft_putchar('-');
	}
	len = get_len_float(nbr);
	preci = arg->flag_preci == 1 ? arg->precision : 6;
	ftoa(nbr, tab, preci);
	ft_putstr(tab);
	return (0);
}

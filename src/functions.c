/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:37:16 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 15:22:28 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

intmax_t	ft_pow(intmax_t nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base_x(intmax_t value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)ft_memalloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

char	*ft_itoa_base_xx(intmax_t value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)ft_memalloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

char	*ft_cjoin(char c, char *str)
{
	char	*s;
	int		i;

	if (!str || !c)
		return (NULL);
	i = 1;
	if (!(s = ft_memalloc(sizeof(char *) * ft_strlen(str) + 1)))
		return (NULL);
	s[0] = c;
	while (str[i-1] != '\0')
	{
		s[i] = str[i - 1];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_joinc(char *str, char c)
{
	char	*s;
	int		i;


	if (!str || !c)
		return (NULL);
	if (!(s = ft_memalloc(sizeof(char *) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = c;
	s[i + 1] = '\0';
	return (s);
}

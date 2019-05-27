/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:54:56 by thallot           #+#    #+#             */
/*   Updated: 2019/05/17 14:20:47 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base(int nb, int base)
{
	int				i;
	int				count;
	char			*nbr;

	i = 1;
	while ((int)ft_pow(base, i) - 1 < nb)
		i++;
	count = i;
	nbr = (char*)ft_memalloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb = nb / base;
	}
	return (nbr);
}

int		ft_itoa_base_uns(int base, t_arg *arg)
{
	unsigned int	value;
	int				i;
	int				count;
	char			*nbr;
	char			letters;

	value = arg->nbr;
	letters = arg->type == TYPE_XX ? 'A' : 'a';
	i = 1;
	while (ft_pow(base, i) - 1 < value)
		i++;
	count = i;
	nbr = (char*)ft_memalloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? letters - 10 : '0');
		value = value / base;
	}
	arg->len += count;
	arg->value = nbr;
	return (count);
}

int		ft_itoa_base_unsl(int base, t_arg *arg)
{
	unsigned long int	value;
	int								i;
	int								count;
	char							*nbr;
	char							letters;

	value = arg->nbr;
	letters = arg->type == TYPE_XX ? 'A' : 'a';
	i = 1;
	while (ft_powll(base, i) - 1 < value)
		i++;
	count = i;
	nbr = (char*)ft_memalloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? letters - 10 : '0');
		value = value / base;
	}
	arg->len += count;
	arg->value = nbr;
	return (count);
}

int		ft_itoa_base_unsll(int base, t_arg *arg)
{
	uintmax_t			value;
	int						i;
	int						count;
	char					*nbr;
	char					letters;

	value = arg->nbr;
	letters = arg->type == TYPE_XX ? 'A' : 'a';
	count = 16;
	i = 16;
	nbr = (char*)ft_memalloc(sizeof(nbr) * 16);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? letters - 10 : '0');
		value = value / base;
	}
	i = 0;
	while (nbr[i] == '0')
		i++;
	arg->len += count - i;
	arg->value = ft_strsub(nbr, i, 16 - i);
	ft_memdel((void**)&nbr);
	return (count);
}

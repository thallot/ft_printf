/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:47:59 by thallot           #+#    #+#             */
/*   Updated: 2019/05/17 15:14:02 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int		main(void)
{
	int id;
	int ret;
	char *login = "thallot";
	char var = 'f';
	unsigned int k = 123;
	int	v = 12;
	int vv;
	long long tt = -9223372036854775808;
	double		nb;

	nb = -12547.58;
	id = printf("%lu", -42);
	printf("ret : %d\n", id);
	id = ft_printf("%lu", -42);

	return (0);
}

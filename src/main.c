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
	id = 830;

	//ft_printf("%#llx\n", 9223372036854775807);
	//ft_printf("%#llx\n", 6854775807);
	//ft_printf("%15.2s %c %x", "salut", 51, 42);
	id = ft_printf("FT :% ");
	//ft_printf("%o \n", 42);
	//ft_printf("salut %s - id : %lld\n", login, 4294967296);
	//ft_printf("%lx\n", 4294967296);
	return 0;
}

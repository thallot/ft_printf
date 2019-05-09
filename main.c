/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:47:59 by thallot           #+#    #+#             */
/*   Updated: 2019/05/09 13:18:05 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_printf(char *format, ...)
{
	va_list list;

	va_start(list, format);
	ft_print(format, list);
	va_end(list);
}

int		main(void)
{
	int id;
	//char *login = "thallot";
	//char var = 'f';
	//unsigned int k = 123;

	id = 830;
	//ft_printf("bonjour %s tu as l'id %+030d (%c) %u \n", login, id, var, k);


	ft_printf("ft_printf : d %5d\n", id);
	printf("printf : d %5d\n", id);
	/*
	ft_printf(" ft_printf : 1d %1d\n", id);
	printf(" printf : 1d %1d\n", id);
	ft_printf(" ft_printf : d %d\n", id);
	printf(" printf : +3d %+3d\n", id);
	ft_printf(" ft_printf : ' '3d % d\n", id);
	printf(" printf : ' '3d % 3d\n", id);*/
	return 0;
}

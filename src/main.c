/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:47:59 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 15:24:40 by thallot          ###   ########.fr       */
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
	long long tt = 214736474898;
	id = 830;

	ft_printf("-- %llx --", 4294967296);

	//ft_printf("%lld oct : % 51o hex ; %llx HEX : %X hello %- ls je suis %llc  jai %# -3.12d, en char %c %-5% \n"
	return 0;
}

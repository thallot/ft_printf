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

	double		nb;



		nb = -12547.58;
		id = printf("{%0-3d}\n", 0);
		printf("ret : %d\n", id);
		id = ft_printf("{%0-3d}\n", 0);
		printf("ret : %d\n", id);
		printf("\n\n\n\ntest : %f|\n", nb);

		ft_printf("MON F EST FAIT:%.50f|\n", nb);
		printf("MON F EST FAIT:%.50f|\n", nb);
		ft_printf("my test basique:\n");
		ft_printf("my space:% f|\n", nb);
		printf("cl space:% f|\n", nb);
		ft_printf("my plus:%+f|\n", nb);
		printf("cl plus:%+f|\n", nb);
		ft_printf("my hash:%#f|\n", nb);
		printf("cl hash:%#f|\n", nb);
		ft_printf("my precision:%.2f|\n", nb);
		printf("cl precision:%.2f|\n", nb);




	//id = ft_printf("1 : %f\n", 3.12);
	/*ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
  ft_printf("%\n");
  ft_printf("%U\n", 4294967295);
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%s\n", NULL);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
  ft_printf("%C\n", 15000);*/
	//ft_printf("%#llx\n", 9223372036854775807);
	//ft_printf("%#llx\n", 6854775807);
	//ft_printf("%15.2s %c %x", "salut", 51, 42);
	//ft_printf("%o \n", 42);
	//ft_printf("salut %s - id : %lld\n", login, 4294967296);
	//ft_printf("%lx\n", 4294967296);
	return 0;
}

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

typedef unsigned long long		ull;
typedef long long				ll;
typedef unsigned long			ul;

typedef enum		e_modifier
{
	NONE,
	HH,
	H,
	L,
	LL,
	J,
	T,
	Z
};

void	ft_print_result(int mr, int or, int line)
{
	static int c = 0;
	printf("\033[33m[%d]\033[0m MINE = %i - ORIG = %i", c, mr, or);
	if (mr == or)
		printf("\t\033[32m✔\033[0m");
	else
		printf("\t\033[31m✘ - (failed between lines %i and %i)\033[0m",
				 line - 3, line);
	printf("\n---------------\n");
	c++;
}

int		main(void)
{


		int	or, mr;
		char	**test;

		test = malloc(sizeof(char*));
		or = 0;
		mr = 0;
		printf("\033[1;37m======== %%d ========\033[0m\n");

		mr = ft_printf("MINE>\t[%d]\n", 650);
		or = printf("ORIG>\t[%d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%d]\n", -650);
		or = printf("ORIG>\t[%d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+d]\n", 650);
		or = printf("ORIG>\t[%+d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+1d]\n", 650);
		or = printf("ORIG>\t[%+1d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+10d]\n", 650);
		or = printf("ORIG>\t[%+10d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+10d]\n", -650);
		or = printf("ORIG>\t[%+10d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10d]\n", 650);
		or = printf("ORIG>\t[%10d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-10d]\n", 650);
		or = printf("ORIG>\t[%-10d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5d]\n", 650);
		or = printf("ORIG>\t[%-5d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% d]\n", 650);
		or = printf("ORIG>\t[% d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 5d]\n", 650);
		or = printf("ORIG>\t[% 5d]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% d]\n", -650);
		or = printf("ORIG>\t[% d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 5d]\n", -650);
		or = printf("ORIG>\t[% 5d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%05d]\n", -650);
		or = printf("ORIG>\t[%05d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+05d]\n", -650);
		or = printf("ORIG>\t[%+05d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-05d]\n", -650);
		or = printf("ORIG>\t[%-05d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-05d]\n", -650);
		or = printf("ORIG>\t[%+-05d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-09d]\n", -650);
		or = printf("ORIG>\t[%+-09d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+09d]\n", -650);
		or = printf("ORIG>\t[%+09d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-1d]\n", -650);
		or = printf("ORIG>\t[%+-1d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+01d]\n", -650);
		or = printf("ORIG>\t[%+01d]\n", -650);
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m======== end %%d =====\033[0m\n\n");

		printf("\033[1;37m======== %%u ========\033[0m\n");

		mr = ft_printf("MINE>\t[%u]\n", 650);
		or = printf("ORIG>\t[%u]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%u]\n", 4000000000);
		or = printf("ORIG>\t[%u]\n", 4000000000);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%u]\n", -650);
		or = printf("ORIG>\t[%u]\n", -650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>[\t%+-10u]\n", 12345);
		or = printf(   "ORIG>[\t%+-10u]\n", 12345);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>[\t%+10u]\n", 12345);
		or = printf(   "ORIG>[\t%+10u]\n", 12345);
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m======== end %%u =====\033[0m\n\n");


		printf("\033[1;37m======== %%s ========\033[0m\n");

		mr = ft_printf("MINE>\t[%s]\n", "");
		or = printf("ORIG>\t[%s]\n", "");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10s]\n", "");
		or = printf("ORIG>\t[%10s]\n", "");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%s]\n", NULL);
		or = printf("ORIG>\t[%s]\n", NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%s]\n", "Coconut");
		or = printf("ORIG>\t[%s]\n", "Coconut");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% s]\n", "Coconut");
		or = printf("ORIG>\t[% s]\n", "Coconut");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 2s]\n", "Coconut");
		or = printf("ORIG>\t[% 2s]\n", "Coconut");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-4s]\n", "Coconut");
		or = printf("ORIG>\t[%-4s]\n", "Coconut");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+8s]\n", "Coconut");
		or = printf("ORIG>\t[%+8s]\n", "Coconut");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+15s]\n", "Coconut");
		or = printf("ORIG>\t[%+15s]\n", "Coconut");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-15s]\n", "Coconut");
		or = printf("ORIG>\t[%-15s]\n", "Coconut");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%15s]\n", "Coconut");
		or = printf("ORIG>\t[%15s]\n", "Coconut");
		ft_print_result(mr, or, __LINE__);


		printf("\033[1;37m======== end %%s =====\033[0m\n\n");


		printf("\033[1;37m======== %%c ========\033[0m\n");

		mr = ft_printf("MINE>\t[%c]\n", '"');
		or = printf("ORIG>\t[%c]\n", '"');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+10c]\n", 'r');
		or = printf("ORIG>\t[%+10c]\n", 'r');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-10c]\n", 'r');
		or = printf("ORIG>\t[%-10c]\n", 'r');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%010c]\n", 'r');
		or = printf("ORIG>\t[%010c]\n", 'r');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-10c]\n", 'r');
		or = printf("ORIG>\t[%+-10c]\n", 'r');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0+10c]\n", 'r');
		or = printf("ORIG>\t[%0+10c]\n", 'r');
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m======== end %%c =====\033[0m\n\n");


		printf("\033[1;37m======== %%o ========\033[0m\n");

		mr = ft_printf("MINE>\t[%o]\n", 2048);
		or = printf("ORIG>\t[%o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% o]\n", 777);
		or = printf("ORIG>\t[% o]\n", 777);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+o]\n", 128);
		or = printf("ORIG>\t[%+o]\n", 128);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-o]\n", 48);
		or = printf("ORIG>\t[%-o]\n", 48);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+5o]\n", 10);
		or = printf("ORIG>\t[%+5o]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5o]\n", 2048);
		or = printf("ORIG>\t[%-5o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+10o]\n", 2048);
		or = printf("ORIG>\t[%+10o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%010o]\n", 2048);
		or = printf("ORIG>\t[%010o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-+10o]\n", 2048);
		or = printf("ORIG>\t[%-+10o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
		or = printf("ORIG>\t[%-0+10o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#o]\n", 48);
		or = printf("ORIG>\t[%#o]\n", 48);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+10o]\n", 2048);
		or = printf("ORIG>\t[%#+10o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
		or = printf("ORIG>\t[%-0+10o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
		or = printf("ORIG>\t[%-0+10o]\n", 2048);
		ft_print_result(mr, or, __LINE__);


		mr = ft_printf("MINE>\t[%#-0+10o]\n", 2048);
		or = printf("ORIG>\t[%#-0+10o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-0#+3o]\n", 2048);
		or = printf("ORIG>\t[%-0#+3o]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%o]\n", 02047);
		or = printf("ORIG>\t[%o]\n", 02047);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%o]\n", 02047);
		or = printf("ORIG>\t[%o]\n", 02047);
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m======== end %%o =====\033[0m\n\n");

		printf("\033[1;37m======== %%x and %%X ========\033[0m\n");

		mr = ft_printf("MINE>\t[%x]\n", 16);
		or = printf("ORIG>\t[%x]\n", 16);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%x]\n", 2048);
		or = printf("ORIG>\t[%x]\n", 2048);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%x]\n", 16777215);
		or = printf("ORIG>\t[%x]\n", 16777215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%X]\n", 6777215);
		or = printf("ORIG>\t[%X]\n", 6777215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#x]\n", 1677215);
		or = printf("ORIG>\t[%#x]\n", 1677215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#X]\n", 1677725);
		or = printf("ORIG>\t[%#X]\n", 1677725);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+x]\n", 1777215);
		or = printf("ORIG>\t[%#+x]\n", 1777215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#-X]\n", 16215);
		or = printf("ORIG>\t[%#-X]\n", 16215);
		ft_print_result(mr, or, __LINE__);

		printf("\n\033[1;37m=[HARD]= %%x and %%X ========\033[0m\n\n");

		mr = ft_printf("MINE>\t[%#+9x]\n", 177215);
		or = printf("ORIG>\t[%#+9x]\n", 177215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#-15X]\n", 167715);
		or = printf(   "ORIG>\t[%#-15X]\n", 167715);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%# +9x]\n", 17215);
		or = printf(   "ORIG>\t[%# +9x]\n", 17215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%020x]\n", 1254789652);
		or = printf(   "ORIG>\t[%020x]\n", 1254789652);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#020x]\n", 1254789652);
		or = printf(   "ORIG>\t[%#020x]\n", 1254789652);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020x]\n", 1254789652);
		or = printf(   "ORIG>\t[%#+020x]\n", 1254789652);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+20x]\n", 1254789652);
		or = printf(   "ORIG>\t[%#+20x]\n", 1254789652);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+20x]\n", 0xffffff);
		or = printf(   "ORIG>\t[%#+20x]\n", 0xffffff);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+20x]\n", 0xffffff);
		or = printf(   "ORIG>\t[%#+20x]\n", 0xffffff);
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m======== end %%x and %%X ====\033[0m\n\n");

		printf("\033[1;37m======== %%p ========\033[0m\n");

		mr = ft_printf("MINE>\t[%p]\n", &mr);
		or = printf(   "ORIG>\t[%p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%p]\n", &or);
		or = printf(   "ORIG>\t[%p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10p]\n", &mr);
		or = printf(   "ORIG>\t[%10p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+10p]\n", &or);
		or = printf(   "ORIG>\t[%+10p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-10p]\n", &mr);
		or = printf(   "ORIG>\t[%-10p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+14p]\n", &or);
		or = printf(   "ORIG>\t[%+14p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+017p]\n", &or);
		or = printf(   "ORIG>\t[%+017p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-017p]\n", &or);
		or = printf(   "ORIG>\t[%+-017p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-017p]\n", &or);
		or = printf(   "ORIG>\t[%+#-017p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-20p]\n", &or);
		or = printf(   "ORIG>\t[%+-20p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020p]\n", &or);
		or = printf(   "ORIG>\t[%#+-020p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-020p]\n", &or);
		or = printf(   "ORIG>\t[% #+-020p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020p]\n", &or);
		or = printf(   "ORIG>\t[%#+020p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		free(test);
		test = 4587;

		printf("\033[1;37m==== %%p + modifiers ===\033[0m\n");

		mr = ft_printf("MINE>\t[%hhp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%hhp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%hp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%hp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%lp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%llp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%llp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%jp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%jp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%zp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%zp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lld]\n", 9223372036854775807);
		or = printf(   "ORIG>\t[%lld]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lli]\n", 9223372036854775807);
		or = printf(   "ORIG>\t[%lli]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%llu]\n", 18446744073709551615);
		or = printf(   "ORIG>\t[%llu]\n", 18446744073709551615);
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m==== %%p + double attr ===\033[0m\n");

		mr = ft_printf("MINE>\t[%-20+p]\n", &or);
		or = printf(   "ORIG>\t[%-20+p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-20+lp]\n", &or);
		or = printf(   "ORIG>\t[%-20+lp]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-20+-p]\n", &or);
		or = printf(   "ORIG>\t[%-20+-p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m======== end %%p ====\033[0m\n\n");


		printf("\033[1;37m==== Crashtest zone ===\033[0m\n");

		mr = ft_printf("MINE>\t[]\n", 25, 16215);
		or = printf("ORIG>\t[]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[-10+d s : {%+-10d} {%s}]\n", 12345, "argl");
		or = printf(   "ORIG>\t[-10+d s : {%+-10d} {%s}]\n", 12345, "argl");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%]\n", 25, 16215);
		or = printf("ORIG>\t[%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%%]\n", 25, 16215);
		or = printf("ORIG>\t[%%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%%%]\n", 25, 16215);
		or = printf("ORIG>\t[%%%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[30%%]\n", 25, 16215);
		or = printf("ORIG>\t[30%%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30%]\n", 25, 16215);
		or = printf("ORIG>\t[%30%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%%%%]\n", 25, 16215);
		or = printf("ORIG>\t[%%%%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%{after]\n", 25, 16215);
		or = printf("ORIG>\t[%{after]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m== End Crashtest zone ==\033[0m\n\n");


		printf("\033[1;37m==== %%d + modifiers ===\033[0m\n");

		mr = ft_printf("MINE>\t[%hhd]\n", 123456789);
		or = printf(   "ORIG>\t[%hhd]\n", 123456789);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%hd]\n", 123456789);
		or = printf(   "ORIG>\t[%hd]\n", 123456789);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lld]\n", 123456789);
		or = printf(   "ORIG>\t[%lld]\n", 123456789);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%ld]\n", 123456789);
		or = printf(   "ORIG>\t[%ld]\n", 123456789);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%jd]\n", 123456789);
		or = printf(   "ORIG>\t[%jd]\n", 123456789);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%zd]\n", 123456789);
		or = printf(   "ORIG>\t[%zd]\n", 123456789);
		ft_print_result(mr, or, __LINE__);

		printf("\033[1;37m== End %%d + modifiers ==\033[0m\n\n");


		printf("\033[1;37m==== precision modifiers ===\033[0m\n");


		mr = ft_printf("MINE>\t[%.4d]\n", 10);
		or = printf(   "ORIG>\t[%.4d]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-.4d]\n", 10000);
		or = printf(   "ORIG>\t[%-.4d]\n", 10000);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.1d]\n", 10000);
		or = printf(   "ORIG>\t[%.1d]\n", 10000);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-.0d]\n", 10000);
		or = printf(   "ORIG>\t[%-.0d]\n", 10000);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.4d]\n", 10);
		or = printf(   "ORIG>\t[%5.4d]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-8.4d]\n", 10);
		or = printf(   "ORIG>\t[%-8.4d]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5.4d]\n", 10);
		or = printf(   "ORIG>\t[%-5.4d]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-+8.4d]\n", 10);
		or = printf(   "ORIG>\t[%-+8.4d]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%2.4d]\n", 10000);
		or = printf(   "ORIG>\t[%2.4d]\n", 10000);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10.1d]\n", 10000);
		or = printf(   "ORIG>\t[%10.1d]\n", 10000);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%4.0d]\n", 10000);
		or = printf(   "ORIG>\t[%4.0d]\n", 10000);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5.4i]\n", 10);
		or = printf(   "ORIG>\t[%-5.4i]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%8.4i]\n", 10);
		or = printf(   "ORIG>\t[%8.4i]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.4u]\n", 10);
		or = printf(   "ORIG>\t[%5.4u]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-8.4u]\n", 10);
		or = printf(   "ORIG>\t[%-8.4u]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.4o]\n", 10);
		or = printf(   "ORIG>\t[%5.4o]\n", 10);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-8.6o]\n", 0456);
		or = printf(   "ORIG>\t[%-8.6o]\n", 0456);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%18.12o]\n", 0777777777);
		or = printf(   "ORIG>\t[%18.12o]\n", 0777777777);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.4p]\n", 0xfaf);
		or = printf(   "ORIG>\t[%5.4p]\n", 0xfaf);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%8.4p]\n", NULL);
		or = printf(   "ORIG>\t[%8.4p]\n", NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5.4p]\n", 0xfaf);
		or = printf(   "ORIG>\t[%-5.4p]\n", 0xfaf);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-8.4p]\n", NULL);
		or = printf(   "ORIG>\t[%-8.4p]\n", NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.4x]\n", 0xfaf);
		or = printf(   "ORIG>\t[%5.4x]\n", 0xfaf);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.4X]\n", 0xfaf);
		or = printf(   "ORIG>\t[%5.4X]\n", 0xfaf);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5.4X]\n", 0xfaf);
		or = printf(   "ORIG>\t[%-5.4X]\n", 0xfaf);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.4c]\n", 'k');
		or = printf(   "ORIG>\t[%5.4c]\n", 'k');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5.4c]\n", 'k');
		or = printf(   "ORIG>\t[%-5.4c]\n", 'k');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.4s]\n", "ok");
		or = printf(   "ORIG>\t[%5.4s]\n", "ok");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5.4s]\n", "ok");
		or = printf(   "ORIG>\t[%-5.4s]\n", "ok");
		ft_print_result(mr, or, __LINE__);


		mr = ft_printf("MINE>\t[%lx]\n", 30000001245258745);
		or = printf(   "ORIG>\t[%lx]\n", 30000001245258745);
		ft_print_result(mr, or, __LINE__);


		mr = ft_printf("MINE>\t[%lx]\n", (unsigned long)-178965423);
		or = printf(   "ORIG>\t[%lx]\n", (unsigned long)-178965423);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%hd\n", (short)0x1789ffff);
		or = printf("%hd\n", (short)0x1789ffff);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%+12.5d\n", 0x44ff551100);
		or = printf("%+12.5d\n", 0x44ff551100);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
		or = printf("cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%#0#4lo\n", 0);
		or = printf("%#0#4lo\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%hhld\n", (unsigned char)128);
		or = printf("%hhld\n", (unsigned char)128);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%ld\n", LONG_MIN);
		or = printf("%ld\n", LONG_MIN);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%#0.3o\n", 17);
		or = printf("%#0.3o\n", 17);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("{%+03d}\n", 0);
		or = printf("{%+03d}\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%04d\n", 0);
		or = printf("%04d\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("{% 03d}\n", 0);
		or = printf("{% 03d}\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("{%0-3d}\n", 0);
		or = printf("{%0-3d}\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("{%8B}\n", 42);
		or = printf("{%o}\n", 42);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%018.4p]\n", NULL);
		or = printf("ORIG>\t[%018.4p]\n", NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t% #9.0p\n", 482);
		or = printf("ORIG>\t% #9.0p\n", 482);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("% p|%+p\n", 42, 42);
		or = printf("% p|%+p\n", 42, 42);
		ft_print_result(mr, or, __LINE__);


		mr = ft_printf("% p|\n", &free);
		or = printf("% p|\n", &free);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%----24p et hello %2p %12p\n", &mr, &or, NULL);
		or = printf("%----24p et hello %2p %12p\n", &mr, &or, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("% f\n", -12.47);
		or = printf("% f\n", -12.47);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%+ .3f\n", -12.47);
		or = printf("%+ .3f\n", -12.47);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%+ .3f\n", -0);
		or = printf("%+ .3f\n", -0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%+ .3f\n", -7.6988);
		or = printf("%+ .3f\n", -7.6988);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%#-+11 .3f\n", -7.6988);
		or = printf("%#-+11 .3f\n", -7.6988);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%#-+3 .3f\n", -7.6988);
		or = printf("%#-+3 .3f\n", -7.6988);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%.5u|%-.5u|%0.5u\n", 0U, 0U, 0U);
		or = printf("%.5u|%-.5u|%0.5u\n", 0U, 0U, 0U);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%1.X|%-1.X|%#1.X|%01.X", 0U, 0U, 0U, 0U);
		ft_putchar('\n');
		or = printf("%1.X|%-1.X|%#1.X|%01.X", 0U, 0U, 0U, 0U);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%23X|%-23X|%#X|%023X", 0U, 0U, 0U, 0U);
		ft_putchar('\n');
		or = printf("%23X|%-23X|%#X|%023X", 0U, 0U, 0U, 0U);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("%1.i|%-1.i|%+1.i|% 1.i|%01.i", 0, 0, 0, 0, 0);
		ft_putchar('\n');
		or = printf("%1.i|%-1.i|%+1.i|% 1.i|%01.i", 0, 0, 0, 0, 0);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_print_result(mr, or, __LINE__);


		mr = ft_printf("%023.i", 0);
		ft_putchar('\n');
		or = printf("%023.i", 0);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_print_result(mr, or, __LINE__);



	return (0);
}

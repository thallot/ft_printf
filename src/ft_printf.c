/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:04:22 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 10:04:39 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list list;
	int		ret;
	char 	*pf_str;

	ret = 0;
	va_start(list, format);
	pf_str = ft_print(format, list);
	va_end(list);
	ret = ft_strlen(pf_str);
	ft_putstr(pf_str);
	return (ret);
}

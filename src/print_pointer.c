/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:25:42 by thallot           #+#    #+#             */
/*   Updated: 2019/05/22 14:26:51 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_pointer(va_list list, t_arg *arg)
{
  arg->nbr = va_arg(list, uintmax_t);
  ft_putstr("0x");
  if (arg->nbr != 0)
  {
    ft_itoa_base_unsll(16, arg);
    ft_putstr(arg->value);
    arg->len = ft_strlen(arg->value) + 2;
    ft_memdel((void **)&(arg)->value);
  }
  else
  {
    ft_putstr("0");
    arg->len = 3;
  }
  return (arg->len);
}

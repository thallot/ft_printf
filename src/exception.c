/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:56:08 by thallot           #+#    #+#             */
/*   Updated: 2019/05/29 14:56:09 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int   exep_oct(t_arg *arg)
{
  if ((uintmax_t)arg->nbr == ULONG_MAX)
  {
      arg->value = ft_strdup("1777777777777777777777");
      arg->len = 23;
      return (arg->len);
  }
  return (0);
}

int   exep_hex(t_arg *arg)
{
  if ((uintmax_t)arg->nbr == ULLONG_MAX)
  {
      arg->value = ft_strdup("ffffffffffffffff");
      arg->len = 17;
      return (arg->len);
  }
  return (0);
}

int   exep_hexx(t_arg *arg)
{
  if ((uintmax_t)arg->nbr == ULLONG_MAX)
  {
      arg->value = ft_strdup("FFFFFFFFFFFFFFFF");
      arg->len = 17;
      return (arg->len);
  }
  return (0);
}

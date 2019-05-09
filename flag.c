/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:10:19 by thallot           #+#    #+#             */
/*   Updated: 2019/05/08 15:26:08 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		is_valid_type(char c)
{
	if (ft_strchr("diouxXcspf", c) != NULL)
		return (1);
	return (0);
}

int		is_valid_lh(char before, char current)
{
	if ((before == 'l' && current == 'l')
		|| (current == 'h' && before == 'h'))
		return (1);
	return (0);
}

int		is_valid_precision(char c)
{
	if (ft_strchr(".*$", c) != NULL)
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (ft_strchr("#0+- ", c) != NULL)
		return (1);
	return (0);
}

int		is_valid(char c)
{
	if (is_flag(c) || is_valid_type(c) || ft_isdigit(c)
		|| is_valid_precision(c) || c == 'h' || c == 'l')
		return (1);
	return (0);
}

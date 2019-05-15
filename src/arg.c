/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:37:48 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 11:03:13 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print(char *str, va_list list)
{
	int		i;
	int		len;
	t_arg	*arg;
	char	*tmp;
	char	*pf_str;

	i = 0;
	pf_str = ft_strnew(0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = 1;
			arg = get_arg(&str[i], &len);
			ft_print_value(list, arg);
			tmp = ft_strsub(str, 0, i);
			pf_str = ft_strjoin(pf_str, tmp);
			arg->value == NULL ? arg->value = ft_strdup("(null)") : arg->value;
			pf_str = ft_strjoin(pf_str, arg->value);
			str = str + len + i;
			i = 0;
			/*printf("--Type : %d, W : %d Sh/z/p/m/s : %d/%d/%d/%d/%d len : %d (%d) Precision : %d conv %d --\n", 
			arg->type, arg->width, arg->sharp, arg->zero, arg->plus, arg->minus, arg->space,
			len, arg->flag_preci,  arg->precision, arg->conv);*/
			free_arg(arg);
		}
		else
			i++;
	}
	pf_str = ft_strjoin(pf_str, str);
	return (pf_str);
}

int		ft_print_value(va_list list, t_arg *arg)
{
	unsigned int	uns_int;
	int				ret;
	
	ret = 0;
	if (arg->type == TYPE_D)
		ret = ft_print_int(list, arg);
	else if (arg->type == TYPE_S)
		ret = ft_print_string(list, arg);
	else if (arg->type == TYPE_C)
		ret = ft_print_char(list, arg);
	else if (arg->type == TYPE_O)
		ret = ft_print_oct(list, arg);
	else if (arg->type == TYPE_U)
	{
		uns_int = va_arg(list, unsigned int);
		ft_putnbr(uns_int);
	}
	else if (arg->type == TYPE_X)
		ret = ft_print_hex(list, arg);
	else if (arg->type == TYPE_XX)
		ret = ft_print_hexx(list, arg);
	else if (arg->type == TYPE_F)
	{
	}
	else if (arg->type == TYPE_PERCENT)
		ret = ft_print_percent(list, arg);
	return (ret);
}

int		ft_get_nb_arg(char *str)
{
	int		i;
	int		count;
	t_arg	*arg;
	int		len;

	len = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i++] == '%')
		{
			if ((arg = get_arg(str, &len)) != NULL)
				count++;
		}
	}
	return (count);
}


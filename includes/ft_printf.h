/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:07:09 by thallot           #+#    #+#             */
/*   Updated: 2019/05/09 13:01:22 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 1024
# define TYPE_S 8
# define TYPE_C 7
# define TYPE_D 6
# define TYPE_P 4
# define TYPE_X 4
# define TYPE_XX 3
# define TYPE_U 2
# define TYPE_O 1
# define TYPE_F 0
# define TYPE_PERCENT 0
# define PRECISION 8192
# define PREC_PARSE 4096
# define MODIFIER_X 2048
# define MODIFIER_H 1024
# define MODIFIER_HH 512
# define MODIFIER_L 256
# define MODIFIER_LL 128
# define MODIFIER_J 64
# define MODIFIER_Z 32

typedef struct	s_arg
{
	int		pos;
	int		type;
	int		conv;
	int		minus;
	int		plus;
	int		sharp;
	int		zero;
	int		space;
	int		flag_preci;
	int		precision;
	int		error;
	void	*value;
	size_t	len;
}				t_arg;

int				is_valid_type(char c);
int				is_valid_lh(char before, char current);
int				is_flag(char c);
int				is_valid_precision(char c);
int				is_valid(char c);

t_arg			*get_arg(char *str, int *len);
t_arg			*get_flag(char *str, t_arg *arg, int *i);
t_arg			*get_type(char *str, t_arg *arg, int *i);
t_arg			*get_precision(char *str, t_arg *arg);

void			ft_print(char *str, va_list list);
void			ft_print_value(va_list list, t_arg *arg);
int				ft_get_nb_arg(char *str);

void			ft_print_string(va_list list, t_arg *arg);
void			ft_print_char(va_list list, t_arg *arg);

int				get_len_int(int nb);
void			ft_print_int(va_list list, t_arg *arg);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:07:09 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 15:13:54 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <inttypes.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 1024
# define TYPE_S 9
# define TYPE_C 8
# define TYPE_D 7
# define TYPE_P 6
# define TYPE_X 5
# define TYPE_XX 4
# define TYPE_U 3
# define TYPE_O 2
# define TYPE_F 1
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

/*
********************************* Structure ***********************************
*/
typedef struct	s_arg
{
	int			pos;
	int			type;
	int			conv;
	int			minus;
	int			plus;
	int			sharp;
	int			zero;
	int			space;
	int			flag_preci;
	int			precision;
	int			error;
	int			width;
	char		*value;
	intmax_t	nbr;
	size_t		len;
}				t_arg;
/*
********************************** Flag.c * ***********************************
*/
int				is_valid_type(char c);
int				is_valid_lh(char before, char current);
int				is_flag(char c);
int				is_valid_precision(char c);
int				is_valid(char c);
/*
********************************* Get_flag.c **********************************
*/
t_arg			*get_width(char *str, t_arg *arg);
t_arg			*get_arg(char *str, int *len);
t_arg			*get_preflag(char *str, t_arg *arg, int *i);
t_arg			*get_type(char *str, t_arg *arg, int *i);
t_arg			*get_precision(char *str, t_arg *arg);
t_arg			*get_flag(char *str, t_arg *arg, int *i);
/*
********************************* Convert.c ***********************************
*/
intmax_t		convert_arg(t_arg *arg, va_list list);
/*
********************************* Arg.c ***************************************
*/
int				ft_printf(char *format, ...);
char			*ft_print(char *str, va_list list);
int				ft_print_value(va_list list, t_arg *arg);
int				ft_get_nb_arg(char *str);
/*
********************************* String.c ************************************
*/
int				ft_print_string(va_list list, t_arg *arg);
int				ft_print_char(va_list list, t_arg *arg);
/*
********************************* Integer.c ***********************************
*/
int				ft_print_int(va_list list, t_arg *arg);
int				ft_print_hex(va_list list, t_arg *arg);
int				ft_print_hexx(va_list list, t_arg *arg);
int				ft_print_oct(va_list list, t_arg *arg);
/*
********************************* Functions.c *********************************
*/
intmax_t		ft_pow(intmax_t nb, int pow);
char			*ft_itoa_base_x(intmax_t value, int base);
char			*ft_itoa_base_xx(intmax_t value, int base);
char			*ft_cjoin(char c, char *s);
char			*ft_joinc(char *str, char c);
/*
********************************* Percent.c ***********************************
*/
int				ft_print_percent(va_list list, t_arg *arg);
/*
********************************* Free.c **************************************
*/
void			free_arg(t_arg *arg);
/*
********************************* Integer.c ***********************************
*/
int				get_len_int(intmax_t nb);
t_arg			*set_flag_int(t_arg *arg, intmax_t nb);
/*
********************************* Caster.c ************************************
*/
t_arg			*caster_int(t_arg *arg);
#endif

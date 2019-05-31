/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:07:09 by thallot           #+#    #+#             */
/*   Updated: 2019/05/30 16:24:29 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <inttypes.h>
# include <unistd.h>
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
# define TYPE_B 0
# define TYPE_PERCENT 10
# define MODIFIER_H 4
# define MODIFIER_HH 3
# define MODIFIER_L 2
# define MODIFIER_LL 1
# define WHITE \x1b[37m
# define BLUE \x1b[36m
# define GREEN \033[1;32m
# define GREY \x1b[33m
# define RED \x1b[31m

/*
********************************* Structure ***********************************
*/
typedef struct			s_arg
{
	int				pos;
	int				type;
	int				conv;
	int				minus;
	int				plus;
	int				sharp;
	int				zero;
	int				space;
	int				flag_preci;
	int				flag;
	int				sign;
	long long int	precision;
	int				error;
	long long int	width;
	char			*value;
	long long int	nbr;
	long long int	len;
}						t_arg;
/*
********************************** Flag.c * ***********************************
*/
int						is_valid_type(char c);
int						is_valid_lh(char before, char current);
int						is_flag(char c);
int						is_valid_precision(char c);
int						is_valid(char c);
/*
********************************* Get_flag.c **********************************
*/
t_arg					*get_width(const char *str, t_arg *arg);
t_arg					*get_arg(const char *str, int *len);
t_arg					*get_preflag(const char *str, t_arg *arg, int *i);
t_arg					*get_type(const char *str, t_arg *arg, int *i);
t_arg					*get_precision(const char *str, t_arg *arg);
t_arg					*get_flag(const char *str, t_arg *arg, int *i);
/*
********************************* Convert.c ***********************************
*/
intmax_t				convert_arg(t_arg *arg, va_list list);
intmax_t				conver_arg_s(t_arg *arg, va_list list);
intmax_t				conver_arg_u(t_arg *arg, va_list list);
/*
********************************* Arg.c ***************************************
*/
int						ft_printf(const char *format, ...);
int						ft_print(const char *str, va_list list,
						int i, int count);
int						ft_print_value(va_list list, t_arg *arg);
int						ft_get_nb_arg(char *str);
/*
********************************* String.c ************************************
*/
int						ft_print_string(va_list list, t_arg *arg);
int						ft_print_char(va_list list, t_arg *arg);
int						ft_print_percent(va_list list, t_arg *arg);
int						set_flag_str(t_arg *arg, int len);
/*
********************************* Integer.c ***********************************
*/
int						ft_print_hex(va_list list, t_arg *arg);
int						ft_print_int(va_list list, t_arg *arg);
int						ft_print_unsigned(va_list list, t_arg *arg);
int						ft_print_hexx(va_list list, t_arg *arg);
int						ft_print_oct(va_list list, t_arg *arg);
/*
********************************* Itoa_base.c *********************************
*/
char					*ft_itoa_base(int nb, int base);
int						ft_itoa_base_uns(int base, t_arg *arg);
int						ft_itoa_base_unsl(int base, t_arg *arg);
int						ft_itoa_base_unsll(int base, t_arg *arg);
/*
********************************* Strjoin.c ***********************************
*/
char					*ft_cjoin(char c, char *s);
char					*ft_joinc(char *str, char c);
/*
********************************* Ft_pow.c.c **********************************
*/
unsigned int			ft_pow(intmax_t nb, int pow);
unsigned long int		ft_powl(intmax_t nb, int pow);
uintmax_t				ft_powll(unsigned long long int nb, int pow);
/*
********************************* Free.c **************************************
*/
void					free_arg(t_arg *arg);
/*
********************************* Integer.c ***********************************
*/
void					set_flag_int(t_arg *arg, int len);
void					set_flag_uint(t_arg *arg, int len);
void					set_flag_oct(t_arg *arg, int len);
void					set_flag_hex(t_arg *arg, int len);
void					set_flag_hexx(t_arg *arg, int len);
/*
********************************* Caster.c ************************************
*/
t_arg					*caster_int(t_arg *arg);
t_arg					*caster_uint(t_arg *arg);
t_arg					*caster_sint(t_arg *arg);
/*
********************************* Caster.c ************************************
*/
intmax_t				ft_nbrlen(intmax_t nb, long base);
intmax_t				ft_power_long(intmax_t nb, long pow);
/*
******************************** Function.c ************************************
*/
void					ft_putnbr_max(long long int nb);
void					ft_putnbr_umax(uintmax_t nb);
int						get_len_int(intmax_t nb);
int						get_len_uint(uintmax_t nb);
/*
******************************** Putter.c **************************************
*/
int						set_offset(int *len, t_arg *arg, intmax_t num, int *p);
int						ft_put(char c, int i);
void					ft_put_all(char c, int *n, int *i);
int						ft_putter(char *c, int i);
int						set_exception(t_arg *arg, int n);
/*
******************************** Print_Pointer.c *******************************
*/
int						ft_print_pointer(va_list list, t_arg *arg);
void					set_flag_point(t_arg *arg, int len);
int						ft_print_float(va_list list, t_arg *arg);
/*
******************************** Exception.c ***********************************
*/
int						exep_oct(t_arg *arg);
int						exep_hex(t_arg *arg);
int						exep_hexx(t_arg *arg);
/*
******************************** Float.c **************************************
*/
int						ft_printf_float(va_list list, t_arg *arg);
int						set_flag_float(t_arg *arg, int preci,
						char *intp, char *decip);
/*
******************************** Binary.c *************************************
*/
int						ft_print_binary(va_list list, t_arg *arg);
#endif

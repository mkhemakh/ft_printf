/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:36:18 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/02/27 20:40:52 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct		s_printf
{
	const char		*conv_set;
	char			*hexa_set;
	int				aster;
	int				zero;
	int				minus;
	int				f_val;
	int				prec;
	int				p_val;
	int				p_val_neg;
	int				print_prec;
	int				width;
	int				w_val;
	int				i;
	int				len;
	int				nb_neg;
	int				min_flag;
	int				conv;
	int				nb_di;
	unsigned int	nb_u;
	unsigned long	nb_p;
	int				nb_len;
	int				s_len;
}					t_printf;

int					ft_printf(const char *s, ...);
int					prec_c(t_printf *var, char c);
void				width_c(t_printf *var, char c);
void				zero_c(t_printf *var, char c);
void				minus_c(t_printf *var, char c);
void				arg_c(t_printf *var, va_list arg);
int					prec_di(t_printf *var);
void				width_di(t_printf *var);
void				zero_di(t_printf *var);
void				minus_di(t_printf *var);
void				no_flags_di(t_printf *var);
void				arg_di(t_printf *var, va_list arg);
int					prec_p(t_printf *var);
void				width_p(t_printf *var);
void				zero_p(t_printf *var);
void				minus_p(t_printf *var);
void				arg_p(t_printf *var, va_list arg);
void				prec_s(t_printf *var, char **str);
void				width_s(t_printf *var, char *str);
void				zero_s(t_printf *var, char *str);
void				minus_s(t_printf *var, char *str);
void				arg_s(t_printf *var, va_list arg);
int					prec_u(t_printf *var);
void				width_u(t_printf *var);
void				zero_u(t_printf *var);
void				minus_u(t_printf *var);
void				arg_u(t_printf *var, va_list arg);
int					prec_x(t_printf *var);
void				width_x(t_printf *var);
void				zero_x(t_printf *var);
void				minus_x(t_printf *var);
void				arg_x(t_printf *var, va_list arg);
void				flags_parser(t_printf *var, const char *s);
void				prec_parser(t_printf *var, const char *s);
void				width_parser(t_printf *var, const char *s);
void				format_parser(t_printf *var, const char *s, va_list arg);
void				aster_width(t_printf *var, va_list arg);
void				aster_prec(t_printf *var, va_list arg);
void				aster_flags(t_printf *var, va_list arg);
void				aster_parser(t_printf *var, const char *s, va_list arg);
void				ft_putchar_track(char c, t_printf *var);
void				ft_putstr_track(char *s, t_printf *var);
void				print_p_val(t_printf *var);
void				print_w_val(t_printf *var);
void				print_f_val(t_printf *var, char c);
void				print_p_s_val(t_printf *var, char **str);
void				ft_putnbr_track(int nb, t_printf *var);
void				ft_putnbr_base_track(unsigned long nb, char *base,
																t_printf *var);
int					ft_intlen(int nb);
int					ft_ulllen_base(unsigned long long nb, int base_size);
void				struct_init(t_printf *var);
void				struct_clean(t_printf *var);
int					find_index(char c, const char *set);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);

#endif

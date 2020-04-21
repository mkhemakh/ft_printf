/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 18:08:55 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/03/27 20:29:36 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aster_width(t_printf *var, va_list arg)
{
	var->w_val = va_arg(arg, int);
	var->width = TRUE;
	if (var->w_val < 0)
	{
		var->minus = TRUE;
		var->f_val = -var->w_val;
		var->w_val = FALSE;
		var->width = FALSE;
	}
}

void	aster_prec(t_printf *var, va_list arg)
{
	var->prec = TRUE;
	var->p_val = va_arg(arg, int);
	if (var->p_val < 0)
		var->prec = FALSE;
}

void	aster_flags(t_printf *var, va_list arg)
{
	var->f_val = va_arg(arg, int);
	if (var->f_val < 0)
	{
		var->minus = TRUE;
		var->f_val = -var->f_val;
	}
}

void	aster_parser(t_printf *var, const char *s, va_list arg)
{
	if (s[var->i - 1] == '%')
		aster_width(var, arg);
	if (s[var->i - 1] == '.')
		aster_prec(var, arg);
	if (s[var->i - 1] == '0' || s[var->i - 1] == '-')
		aster_flags(var, arg);
	var->i++;
}

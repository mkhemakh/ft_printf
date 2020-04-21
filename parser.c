/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:09:01 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/03/25 18:10:26 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_parser(t_printf *var, const char *s)
{
  	if (s[var->i] == '0')
	{
		var->zero = TRUE;
		var->i++;
	}
	if (s[var->i] == '-')
	{
		var->minus = TRUE;
		var->i++;
	}
	var->f_val = 0;
	while (s[var->i] && (s[var->i] >= '0' && s[var->i] <= '9'))
	{
		var->f_val = 10 * var->f_val + (s[var->i] - '0');
		var->i++;
	}
}

void	prec_parser(t_printf *var, const char *s)
{
	int neg_flag;

	neg_flag = FALSE;
	var->prec = TRUE;
	var->i++;
	if (s[var->i] == '-')
	{
		var->i++;
		neg_flag = TRUE;
	}
	var->p_val = 0;
	while (s[var->i] && ((s[var->i] >= '0' && s[var->i] <= '9')))
	{
		var->p_val = 10 * var->p_val + (s[var->i] - '0');
		var->i++;
	}
	if (neg_flag == TRUE)
	{
		var->p_val_neg = var->p_val;
		var->p_val = 0;
	}
}

void	width_parser(t_printf *var, const char *s)
{
	var->width = TRUE;
	var->w_val = 0;
	while (s[var->i] && (s[var->i] >= '0' && s[var->i] <= '9'))
	{
		var->w_val = 10 * var->w_val + (s[var->i] - '0');
		var->i++;
	}
}

void	format_parser(t_printf *var, const char *s, va_list arg)
{
	if (s[var->i] == '*')
		aster_parser(var, s, arg);
	if ((s[var->i] >= '1' && s[var->i] <= '9') && (s[var->i - 1] == '%'))
		width_parser(var, s);
	if ((s[var->i] == '0' && s[var->i - 1] == '%') || s[var->i] == '-')
		flags_parser(var, s);
	if (s[var->i] == '.')
		prec_parser(var, s);
}

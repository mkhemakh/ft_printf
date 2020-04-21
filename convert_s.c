/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:43:09 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/02/26 00:39:06 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prec_s(t_printf *var, char **str)
{
	(*str)[var->p_val] = '\0';
	var->f_val = var->f_val - var->p_val;
	var->w_val = var->w_val - var->p_val;
	var->print_prec = TRUE;
}

void	width_s(t_printf *var, char *str)
{
	if (var->print_prec == FALSE)
		var->w_val -= var->s_len;
	print_w_val(var);
	ft_putstr_track(str, var);
}

void	zero_s(t_printf *var, char *str)
{
	if (var->print_prec == FALSE)
		var->f_val -= var->s_len;
	print_f_val(var, '0');
	ft_putstr_track(str, var);
}

void	minus_s(t_printf *var, char *str)
{
	if (var->print_prec == FALSE)
		var->f_val -= var->s_len;
	ft_putstr_track(str, var);
	print_f_val(var, ' ');
}

void	arg_s(t_printf *var, va_list arg)
{
	char	*str;

	str = ft_strdup(va_arg(arg, char *));
	var->s_len = ft_strlen(str);
	if (var->prec == TRUE)
	{
		if (var->p_val_neg > 0)
		{
			print_p_s_val(var, &str);
			return ;
		}
		else if (var->s_len > var->p_value)
			prec_s(var, &str);
	}
	if (var->width == TRUE)
		width_s(var, str);
	else if (var->zero == TRUE && var->minus == FALSE)
		zero_s(var, str);
	else if (var->minus == TRUE)
		minus_s(var, str);
	else
		ft_putstr_track(str, var);
	free(str);
	str = NULL;
	struct_clean(var);
}
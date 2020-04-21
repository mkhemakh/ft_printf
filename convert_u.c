/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:53:12 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/04/16 00:41:55 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_u(t_printf *var)
{
	if (var->p_val_neg > 0)
	{
		ft_putnbr_base_track(var->nb_u, "0123456789", var);
		while (var->p_val_neg > var->nb_len && var->p_val_neg-- > 0)
			ft_putchar_track(' ', var);
		return (-1);
	}
	else if (var->nb_len < var->p_val)
	{
		var->p_val = var->p_val - var->nb_len;
		var->f_val = var->f_val - var->nb_len - var->p_val;
		var->w_val = var->w_val - var->nb_len - var->p_val;
		var->print_prec = TRUE;
	}
	return (1);
}

void	width_u(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->w_val = var->w_val - var->nb_len;
	if (var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
					&& var->print_prec == FALSE && var->nb_u == 0)
		var->w_val++;
	print_w_val(var);
	if (var->print_prec == TRUE)
		print_p_val(var);
	ft_putnbr_base_track(var->nb_u, "0123456789", var);
}

void	zero_u(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->f_val = var->f_val - var->nb_len;
	if (var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
					&& var->print_prec == FALSE && var->nb_u == 0)
		var->f_val++;
	if (var->prec == TRUE)
	{
		print_f_val(var, ' ');
		if (var->print_prec == TRUE)
			print_p_val(var);
	}
	else
		print_f_val(var, '0');
	ft_putnbr_base_track(var->nb_u, "0123456789", var);
}

void	minus_u(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->f_val = var->f_val - var->nb_len;
	if (var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
					&& var->print_prec == FALSE && var->nb_u == 0)
		var->f_val++;
	if (var->print_prec == TRUE)
		print_p_val(var);
	ft_putnbr_base_track(var->nb_u, "0123456789", var);
	print_f_val(var, ' ');
}

void	arg_u(t_printf *var, va_list arg)
{
	var->nb_u = va_arg(arg, int);
	var->nb_len = ft_ulllen_base(var->nb_u, 10);
	if (var->prec == TRUE && prec_u(var) == -1)
		return ;
	if (var->width == TRUE)
		width_u(var);
	else if (var->zero == TRUE && var->minus == FALSE)
		zero_u(var);
	else if (var->minus == TRUE)
		minus_u(var);
	else
	{
		if (var->print_prec == TRUE)
			print_p_val(var);
		ft_putnbr_base_track(var->nb_u, "0123456789", var);
	}
	struct_clean(var);
}

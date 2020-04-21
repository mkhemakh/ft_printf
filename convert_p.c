/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 15:42:13 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/04/03 04:46:31 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_p(t_printf *var)
{
	if (var->p_val_neg > 0)
	{
		ft_putstr_track("0x", var);
		ft_putnbr_base_track(var->nb_p, "0123456789abcdef", var);
		while (var->p_val_neg > var->nb_len && var->p_val_neg-- > 0)
			ft_putchar_track(' ', var);
		return (-1);
	}
	else if (var->nb_len < var->p_val)
	{
		var->p_val = var->p_val - var->nb_len + 2;
		var->f_val = var->f_val - var->nb_len - var->p_val;
		var->w_val = var->w_val - var->nb_len - var->p_val;
		var->print_prec = TRUE;
	}
	return (1);
}

void	width_p(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->w_val = var->w_val - var->nb_len;
	if (var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
					&& var->print_prec == FALSE && var->nb_p == 0)
		var->w_val++;
	print_w_val(var);
	ft_putstr_track("0x", var);
	if (var->print_prec == TRUE)
		print_p_val(var);
	ft_putnbr_base_track(var->nb_p, "0123456789abcdef", var);
}

void	zero_p(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->f_val = var->f_val - var->nb_len;
	if (var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
					&& var->print_prec == FALSE && var->nb_p == 0)
		var->f_val++;
	if (var->prec == TRUE)
	{
		print_f_val(var, ' ');
		ft_putstr_track("0x", var);
		if (var->print_prec == TRUE)
			print_p_val(var);
	}
	else
	{
		ft_putstr_track("0x", var);
		print_f_val(var, '0');
	}
	ft_putnbr_base_track(var->nb_p, "0123456789abcdef", var);
}

void	minus_p(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->f_val = var->f_val - var->nb_len;
	if ((var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
						&& var->print_prec == FALSE) && var->nb_p == 0)
		var->f_val++;
	ft_putstr_track("0x", var);
	if (var->print_prec == TRUE)
		print_p_val(var);
	ft_putnbr_base_track(var->nb_p, "0123456789abcdef", var);
	print_f_val(var, ' ');
}

void	arg_p(t_printf *var, va_list arg)
{
	var->nb_p = va_arg(arg, unsigned long);
	var->nb_len = ft_ulllen_base(var->nb_p, 16) + 2;
	if (var->prec == TRUE && prec_p(var) == -1)
		return ;
	if (var->width == TRUE)
		width_p(var);
	else if (var->zero == TRUE && var->minus == FALSE)
		zero_p(var);
	else if (var->minus == TRUE)
		minus_p(var);
	else
	{
		ft_putstr_track("0x", var);
		if (var->print_prec == TRUE)
			print_p_val(var);
		ft_putnbr_base_track(var->nb_p, "0123456789abcdef", var);
	}
	struct_clean(var);
}
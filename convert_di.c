/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:54:26 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/04/19 02:35:34 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_di(t_printf *var)
{
	if (var->p_val_neg > 0)
	{
		ft_putnbr_track(var->nb_di, var);
		while (var->p_val_neg > var->nb_len && var->p_val_neg-- > 0)
			ft_putchar_track(' ', var);
		return (-1);
	}
	else if ((var->nb_len - var->nb_neg) < var->p_val)
	{
		var->p_val = var->p_val - var->nb_len + var->nb_neg;
		var->f_val = var->f_val - var->nb_len - var->p_val;
		var->w_val = var->w_val - var->nb_len - var->p_val;
		var->print_prec = TRUE;
	}
	return (1);
}

void	width_di(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->w_val = var->w_val - var->nb_len;
	if (var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
					&& var->print_prec == FALSE && var->nb_di == 0)
		var->w_val++;
	print_w_val(var);
	if (var->nb_neg == TRUE)
		ft_putchar_track('-', var);
	if (var->print_prec == TRUE)
		print_p_val(var);
	ft_putnbr_track(var->nb_di, var);
}

void	zero_di(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->f_val = var->f_val - var->nb_len;
	if (var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
					&& var->print_prec == FALSE && var->nb_di == 0)
		var->f_val++;
	if (var->prec == TRUE)
	{
		print_f_val(var, ' ');
		if (var->nb_neg == TRUE)
			ft_putchar_track('-', var);
		if (var->print_prec == TRUE)
			print_p_val(var);
	}
	else
	{
		if (var->nb_neg == TRUE)
			ft_putchar_track('-', var);
		print_f_val(var, '0');
	}
	ft_putnbr_track(var->nb_di, var);
}

void	minus_di(t_printf *var)
{
	if (var->print_prec == FALSE)
		var->f_val = var->f_val - var->nb_len;
	if (var->prec == TRUE && var->p_val == 0 && var->nb_di == 0
					&& var->print_prec == FALSE && var->nb_di == 0)
		var->f_val++;
	if (var->nb_neg == TRUE)
		ft_putchar_track('-', var);
	if (var->print_prec == TRUE)
		print_p_val(var);
	ft_putnbr_track(var->nb_di, var);
	print_f_val(var, ' ');
}

void	arg_di(t_printf *var, va_list arg)
{
	var->nb_di = va_arg(arg, int);
	if (var->nb_di < 0)
	{
		var->nb_neg = TRUE;
		if (var->nb_di == INT_MIN)
			var->min_flag = TRUE;
	}
	var->nb_len = ft_intlen(var->nb_di);
	if (var->prec == TRUE && prec_di(var) == -1)
		return ;
	if (var->width == TRUE)
		width_di(var);
	else if (var->zero == TRUE && var->minus == FALSE)
		zero_di(var);
	else if (var->minus == TRUE)
		minus_di(var);
	else
	{
		if (var->nb_neg == TRUE)
			ft_putchar_track('-', var);
		if (var->print_prec == TRUE)
			print_p_val(var);
		ft_putnbr_track(var->nb_di, var);
	}
	struct_clean(var);
}
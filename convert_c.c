/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:25:32 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/04/16 00:36:05 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_c(t_printf *var, char c)
{
	if (var->p_val_neg > 0)
	{
		var->p_val_neg--;
		ft_putchar_track(c, var);
		while (var->p_val_neg-- > 0)
			ft_putchar_track(' ', var);
		return (-1);
	}
	return (1);
}

void	width_c(t_printf *var, char c)
{
	var->w_val--;
	print_w_val(var);
	ft_putchar_track(c, var);
}

void	zero_c(t_printf *var, char c)
{
	var->f_val--;
	print_f_val(var, '0');
	ft_putchar_track(c, var);
}

void	minus_c(t_printf *var, char c)
{
	var->f_val--;
	ft_putchar_track(c, var);
	print_f_val(var, ' ');
}

void	arg_c(t_printf *var, va_list arg)
{
	char	c;

	if (var->conv == 8)
		c = '%';
	else
		c = va_arg(arg, int);
	if (var->prec == TRUE && prec_c(var, c) == -1)
		return ;
	if (var->width == TRUE && var->w_val > 1)
		width_c(var, c);
	else if (var->zero == TRUE && var->minus == FALSE && var->f_val > 1)
		zero_c(var, c);
	else if (var->minus == TRUE && var->f_val > 1)
		minus_c(var, c);
	else
		ft_putchar_track(c, var);

	struct_clean(var);
}
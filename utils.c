/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:30:27 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/02/24 18:53:37 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_track(char c, t_printf *var)
{
	write(1, &c, 1);
	var->len++;
}

void	ft_putstr_track(char *s, t_printf *var)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_track(s[i], var);
			i++;
		}
	}
}

void	print_p_val(t_printf *var)
{
	while (var->p_val > 0)
	{
		ft_putchar_track('0', var);
		var->p_val--;
	}
}

void	print_w_val(t_printf *var)
{
	while (var->w_val > 0)
	{
		ft_putchar_track(' ', var);
		var->w_val--;
	}
}

void	print_f_val(t_printf *var, char c)
{
	while (var->f_val > 0)
	{
		ft_putchar_track(c, var);
		var->f_val--;
	}
}

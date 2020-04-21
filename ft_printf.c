/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:18:11 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/02/25 18:42:59 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list			arg;
	t_printf		var;
	static void		(*fct_conv[])(t_printf*, va_list) = {arg_c, arg_s, arg_p,
									arg_di, arg_di, arg_u, arg_x, arg_x, arg_c};

	va_start(arg, str);
	struct_init(&var);
	while (str[var.i])
	{
		if (str[var.i] == '%')
		{
			var.i++;
			while (str[var.i] && (str[var.i] == '.' || str[var.i] == '*' ||
					str[var.i] == '-' || (str[var.i] >= '0' && str[var.i] <= '9')))
				format_parser(&var, str, arg);
			if ((var.conv = find_index(str[var.i], var.conv_set)) != -1)
				(*fct_conv[var.conv])(&var, arg);
		}
		else
			ft_putchar_track(str[var.i], &var);
		if (str[var.i])
			var.i++;
	}
	va_end(arg);
	return (var.len);
}

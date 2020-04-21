/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:42:35 by mkhemakh          #+#    #+#             */
/*   Updated: 2020/02/25 19:08:05 by mkhemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		struct_init(t_printf *var)
{
	var->conv_set = "cspdiuxX%";
	var->hexa_set = "0123456789abcdef";
	var->aster = FALSE;
	var->zero = FALSE;
	var->minus = FALSE;
	var->f_val = FALSE;
	var->prec = FALSE;
	var->p_val = FALSE;
	var->p_val_neg = FALSE;
	var->print_prec = FALSE;
	var->width = FALSE;
	var->w_val = FALSE;
	var->i = FALSE;
	var->len = FALSE;
	var->nb_neg = FALSE;
	var->min_flag = FALSE;
	var->conv = FALSE;
	var->nb_di = FALSE;
	var->nb_u = FALSE;
	var->nb_p = FALSE;
	var->nb_len = FALSE;
	var->s_len = FALSE;
}

void		struct_clean(t_printf *var)
{
	var->hexa_set = "0123456789abcdef";
	var->aster = FALSE;
	var->zero = FALSE;
	var->minus = FALSE;
	var->f_val = FALSE;
	var->prec = FALSE;
	var->p_val = FALSE;
	var->p_val_neg = FALSE;
	var->print_prec = FALSE;
	var->width = FALSE;
	var->w_val = FALSE;
	var->nb_neg = FALSE;
	var->min_flag = FALSE;
	var->conv = FALSE;
	var->nb_di = FALSE;
	var->nb_u = FALSE;
	var->nb_p = FALSE;
	var->nb_len = FALSE;
	var->s_len = FALSE;
}

int			find_index(char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	if (!s1)
		return (ft_strdup("(null)"));
	if (!(s2 = (char*)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

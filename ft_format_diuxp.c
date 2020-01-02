/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_diuxp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:29:06 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/02 02:25:04 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_diuxp(t_parse *parsed, long long value, size_t *ret)
{
	char	*str;

	if (parsed->is_prec && parsed->is_width && parsed->type != 'p')
		str = ft_apply_precision_n_width_diuxp(parsed, value);
	else if (parsed->is_prec && !parsed->is_width && parsed->type != 'p')
		str = ft_apply_precision_diuxp(parsed, value);
	else
		str = ft_apply_width_diuxp(parsed, value);
	*ret += ft_strlen(str);
	return (str);
}

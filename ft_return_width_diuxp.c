/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_width_diuxp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:25:43 by dhaouhao          #+#    #+#             */
/*   Updated: 2019/12/29 03:44:03 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_return_width_diuxp(t_parse *parsed, size_t is_neg, size_t sz, char *tmp)
{
	char	*str;
	size_t	ln;

	ln = sz - ft_strlen(tmp);
	if (!(str = malloc(sizeof(char) * (sz + 1))))
		return (NULL);
	if (parsed->is_0_filled)
		ft_memset(str, '0', sz);
	else
		ft_memset(str, ' ', sz);
	if (is_neg && (parsed->is_0_filled || parsed->is_left))
		str[0] = '-';
	else if (is_neg && !parsed->is_0_filled && !parsed->is_left)
		str[ln - 1] = '-';
	if (is_neg && parsed->is_left)
		ft_memcpy(str + 1, tmp, ft_strlen(tmp));
	else if (!is_neg && parsed->is_left)
		ft_memcpy(str, tmp, ft_strlen(tmp));
	else if (!parsed->is_left)
		ft_memcpy(str + ln, tmp, ft_strlen(tmp));
	str[sz] = '\0';
	free(tmp);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:29:45 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/01 21:08:04 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_c(t_parse *parsed, char c, size_t *ret)
{
	char	*str;
	size_t	size;
	char	*s;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	size = (parsed->is_width && parsed->width > 1) ? parsed->width : 1;
	*ret += size;
	size -= (c == '\0') ? 1 : 0;
	if (!(s = malloc(sizeof(char) * (size + 1))) || !str)
		return (NULL);
	if (parsed->is_0_filled && parsed->type == '%')
		ft_memset(s, '0', size);
	else
		ft_memset(s, ' ', size);
	if (parsed->is_left && c != '\0')
		ft_memcpy(s, str, 1);
	else if (c != '\0')
		ft_memcpy(s + size - 1, str, 1);
	s[size] = '\0';
	free(str);
	return (s);
}

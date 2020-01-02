/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:29:21 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/01 10:42:33 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_s(t_parse *parsed, char *tmp, size_t *ret)
{
	char	*str;
	size_t	size;
	size_t	len;
	char	*s;

	if (parsed->is_prec && parsed->prec < ft_strlen(tmp))
		str = ft_substr(tmp, 0, parsed->prec);
	else
		str = ft_strdup(tmp);
	free(tmp);
	len = ft_strlen(str);
	size = (parsed->is_width && parsed->width > len) ? parsed->width : len;
	*ret += size;
	if (!(s = malloc(sizeof(char) * (size + 1))) || !str)
		return (NULL);
	if (parsed->is_0_filled)
		ft_memset(s, '0', size);
	else
		ft_memset(s, ' ', size);
	if (parsed->is_left)
		ft_memcpy(s, str, len);
	else
		ft_memcpy(s + (size - len), str, len);
	s[size] = '\0';
	free(str);
	return (s);
}

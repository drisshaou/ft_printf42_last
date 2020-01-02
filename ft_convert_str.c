/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:33:09 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/02 06:32:47 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_str(const char *str, size_t	*ret, char **converted_str, va_list args)
{
	int		i;
	char	*string;
	char	*tmp;

	while (*str)
	{
		i = (*str == '%') ? 1 : 0;
		while (str[i] && ((*str != '%' && str[i] != '%') ||
		(str[i] && *str == '%' && !ft_is_type(str[i], TYPES))))
			i++;
		if (i > 0)
		{
			if (*str == '%' && i++)
				string = ft_get_formated(ft_substr(str, 1, i - 1), ret, args);
			else
				string = ft_substr(str, 0, i);
			//printf("string: %s\n", string);
			*ret += (*str != '%') ? ft_strlen(string) : 0;
			str += i;
			tmp = *converted_str;
			*converted_str = ft_strjoin(tmp, string);
			free(string);
			free(tmp);
		}
	}
}

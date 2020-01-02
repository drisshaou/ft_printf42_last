/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_formated.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:47:36 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/02 06:43:49 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_formated(char *str, size_t *ret, va_list args)
{
	t_parse	parsed;
	char	*va_string;
	char	*formated;
	char	*tmp;

	tmp = ft_strdup(str);
	ft_fill_struct(args, &parsed, str);
	if (parsed.type == '%')
		formated = ft_format_c(&parsed, '%', ret);
	else if (parsed.type == 'c')
		formated = ft_format_c(&parsed, (char)va_arg(args, int), ret);
	else if (parsed.type == 's')
	{
		va_string = va_arg(args, char *);
		va_string = (va_string == NULL) ? "(null)" : va_string;
		formated = ft_format_s(&parsed, ft_strdup(va_string), ret);
	}
	else if (parsed.type == 'd' || parsed.type == 'i')
		formated = ft_format_diuxp(&parsed, va_arg(args, int), ret);
	else if (parsed.type == 'u')
		formated = ft_format_diuxp(&parsed, va_arg(args, unsigned int), ret);
	else if (parsed.type == 'x' || parsed.type == 'X' || parsed.type == 'p')
		formated = ft_format_diuxp(&parsed, va_arg(args, unsigned long), ret);
	else
	{
		formated = ft_strjoin("%", tmp);
		*ret += ft_strlen(formated);
	}
	free (tmp);
	return (formated);
}

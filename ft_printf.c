/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:31:45 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/01 21:38:51 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	char	*converted_str;
	va_list	args;
	size_t	ret;

	if (!str)
		return (0);
	ret = 0;
	converted_str = ft_strdup("");
	va_start(args, str);
	ft_convert_str(str, &ret, &converted_str, args);
	va_end(args);
	if (converted_str != NULL)
	{
		ft_putstr(converted_str);
		free(converted_str);
		return (ret);
	}
	return (0);
}

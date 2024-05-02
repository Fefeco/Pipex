/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:58:19 by fcarranz          #+#    #+#             */
/*   Updated: 2024/02/08 14:05:24 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;
	int			i;
	int			j;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	i = 0;
	while (*(format + i))
	{
		if (*(format + i) != '%')
			j = write(1, format + i, 1);
		else if (*(format + ++i) == '%')
			j = write(1, "%", 1);
		else
			j = ft_write_arg(args, format[i]);
		if (j == -1)
			return (-1);
		len += j;
		++i;
	}
	va_end(args);
	return (len);
}

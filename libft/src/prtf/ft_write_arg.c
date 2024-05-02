/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:07:56 by fcarranz          #+#    #+#             */
/*   Updated: 2024/02/08 13:51:00 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_arg(va_list args, char indicator)
{
	int	len;

	len = 0;
	if (indicator == 'c')
		len = ft_print_char(va_arg(args, int));
	if (indicator == 's')
		len = ft_print_str(va_arg(args, char *));
	if (indicator == 'd' || indicator == 'i')
		len = ft_print_nb(va_arg(args, int));
	if (indicator == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	if (indicator == 'X')
		len = ft_print_hexa("0123456789ABCDEF", va_arg(args, int));
	if (indicator == 'x')
		len = ft_print_hexa("0123456789abcdef", va_arg(args, int));
	if (indicator == 'p')
		len = ft_print_ptr(va_arg(args, void *));
	return (len);
}

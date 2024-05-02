/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:28:22 by fcarranz          #+#    #+#             */
/*   Updated: 2024/02/09 19:05:55 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_address(unsigned long address)
{
	int	len;

	len = 0;
	if (address >= 16)
	{
		len += ft_print_address(address / 16);
		address %= 16;
	}
	len += write(1, &"0123456789abcdef"[address], 1);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				len;

	address = (unsigned long)ptr;
	len = write(1, "0x", 2);
	if (len == -1)
		return (len);
	len += ft_print_address(address);
	return (len);
}

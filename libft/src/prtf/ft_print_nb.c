/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:04:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/02/09 19:03:58 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nb(int n)
{
	int	len;

	if (n == -2147483648)
	{
		len = write(1, "-2147483648", 11);
		return (len);
	}
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		if (len == -1)
			return (len);
		len += ft_print_nb(n * -1);
		return (len);
	}
	if (n > 9)
	{
		len += ft_print_nb(n / 10);
		if (len == -1)
			return (len);
		n %= 10;
	}
	len += write(1, &"0123456789"[n], 1);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:31:11 by fcarranz          #+#    #+#             */
/*   Updated: 2024/02/09 19:07:05 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(char *bstab, unsigned int n)
{
	int				len;
	unsigned int	base;

	base = ft_strlen(bstab);
	len = 0;
	if (n >= base)
	{
		len += ft_print_hexa(bstab, n / base);
		if (len == -1)
			return (len);
		n %= base;
	}
	len += write(1, &bstab[n], 1);
	return (len);
}

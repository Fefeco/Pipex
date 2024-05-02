/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:54 by fcarranz          #+#    #+#             */
/*   Updated: 2024/02/09 19:07:38 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int unb)
{
	int	len;

	len = 0;
	if (unb > 9)
	{
		len += ft_print_unsigned(unb / 10);
		if (len == -1)
			return (len);
		unb %= 10;
	}
	len += ft_print_nb(unb);
	return (len);
}

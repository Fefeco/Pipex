/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:04:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/01/29 11:00:36 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
		return ;
	}
	if (n > 9)
	{
		c = n % 10;
		ft_putnbr_fd(n / 10, fd);
	}
	if (n <= 9)
		write(fd, &"0123456789"[n], 1);
	else
		write(fd, &"0123456789"[c], 1);
}

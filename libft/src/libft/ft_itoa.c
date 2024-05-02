/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:54:57 by fcarranz          #+#    #+#             */
/*   Updated: 2024/01/28 13:43:13 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_special_cases(char *ptr, int n, size_t len)
{
	if (n == 0)
		ft_strlcpy(ptr, "0", len + 1);
	else
		ft_strlcpy(ptr, "-2147483648", len + 1);
}

static size_t	ft_ilen(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	len = 0;
	if (n < 0)
	{
		++len;
		n *= -1;
	}
	while (n != 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;

	len = ft_ilen(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (ptr);
	if (n == -2147483648 || n == 0)
	{
		ft_special_cases(ptr, n, len);
		return (ptr);
	}
	if (n < 0)
	{
		n *= -1;
		ptr[0] = '-';
	}
	ptr[len] = '\0';
	while (n != 0)
	{
		ptr[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (ptr);
}

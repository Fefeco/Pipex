/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:30:47 by fcarranz          #+#    #+#             */
/*   Updated: 2024/01/27 11:28:34 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		while (len - i > 0)
		{
			++i;
			*(d + (len - i)) = *(s + (len - i));
		}
	}
	if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}

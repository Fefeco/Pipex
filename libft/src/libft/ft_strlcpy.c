/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:44:12 by fcarranz          #+#    #+#             */
/*   Updated: 2024/01/28 12:22:19 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	total_len;

	total_len = 0;
	if (dstsize && dstsize > 0)
	{
		while (*src && dstsize > 1)
		{
			*dst++ = *src++;
			++total_len;
			--dstsize;
		}
		*dst = '\0';
	}
	while (*src)
	{
		++total_len;
		++src;
	}
	return (total_len);
}

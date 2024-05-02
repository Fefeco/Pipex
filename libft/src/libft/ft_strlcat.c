/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:11:34 by fcarranz          #+#    #+#             */
/*   Updated: 2024/01/27 11:39:20 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total_len;

	total_len = 0;
	while (*dst && dstsize)
	{
		++dst;
		++total_len;
		--dstsize;
	}
	if (dstsize)
	{
		while (*src && --dstsize)
		{
			*dst++ = *src++;
			++total_len;
		}
		*dst = '\0';
	}
	while (*src++)
		++total_len;
	return (total_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:13:54 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/13 13:52:32 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	total_size;

	total_size = count * size;
	p = malloc(total_size);
	if (!p)
		return (p);
	while (total_size > 0)
		p[--total_size] = '\0';
	return ((void *)p);
}

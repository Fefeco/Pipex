/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_prot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:28:00 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/16 21:24:16 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp_prot(const char *s1, const char *s2, size_t n)
{
	int				i;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && n)
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		++i;
		--n;
	}
	if (n > 0)
		return (s1[i] - s2[i]);
	return (0);
}

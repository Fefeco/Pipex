/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:35:51 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/05 19:45:01 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s_dup;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		++i;
	s_dup = (char *)malloc(sizeof (char) * (i + 1));
	if (!s_dup)
		return (NULL);
	s_dup[i] = '\0';
	while (i >= 0)
	{
		s_dup[i] = s[i];
		--i;
	}
	return (s_dup);
}

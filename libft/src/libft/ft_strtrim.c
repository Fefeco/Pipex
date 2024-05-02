/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:30:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/01/28 13:07:06 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		++start;
	while (ft_strchr(set, s1[end - 1]) && (end - 1) > start && end != 0)
		--end;
	str = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (!str)
		return (str);
	ft_strlcpy(str, s1 + start, ((end + 1) - start));
	return (str);
}

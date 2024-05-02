/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:14:59 by fcarranz          #+#    #+#             */
/*   Updated: 2024/01/28 22:46:02 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free_arrays(char **splited, int i)
{
	while (i >= 0)
	{
		free(splited[i]);
		--i;
	}
	return (0);
}

static int	ft_fill_array(char **splited, const char *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			++s;
		while (*s && *s != c)
		{
			++len;
			++s;
		}
		if (len)
		{
			splited[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!splited[i])
				return (ft_free_arrays(splited, i));
			ft_strlcpy(splited[i], s - len, len + 1);
			++i;
		}
	}
	return (1);
}

static int	ft_count_str(char const *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		count_str;
	char	**splited;

	if (!s)
		return (NULL);
	count_str = ft_count_str(s, c);
	splited = malloc(sizeof(char *) * (count_str + 1));
	if (!splited)
		return (0);
	splited[count_str] = NULL;
	if (ft_fill_array(splited, s, c))
		return (splited);
	return (NULL);
}

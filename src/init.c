/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:31:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/13 18:27:29 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**ft_init_fds(int len)
{
	int	i;
	int	**fds;

	fds = (int **)malloc(sizeof(int *) * len - 1);
	if (!fds)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!fds[i])
		{
			while (--i >= 0)
				free(fds[i]);
			free (fds);
			return (NULL);
		}
		++i;
	}
	return (fds);
}

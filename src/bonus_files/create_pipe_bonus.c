/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:56:37 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/21 12:20:14 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_len)
	{
		if (pipe(pipex->fds[i]) == -1)
		{
			if (i == 0)
				return (1);
			while (i >= 0)
			{
				close (pipex->fds[i][0]);
				close (pipex->fds[i][1]);
				--i;
			}
			return (1);
		}
		++i;
	}
	return (0);
}

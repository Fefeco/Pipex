/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:56:37 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/15 17:09:22 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_create_process(t_pipex *pipex, int i)
{
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
		return (1);
	if (pipex->pid[i] == 0)
	{
		if (i == 0)
			dup2 (pipex->fd_in, STDIN_FILENO);
		else
			dup2 (pipex->fds[i - 1][0], STDIN_FILENO);
		if (i == pipex->total_pipes)
			dup2 (pipex->fd_out, STDOUT_FILENO);
		else
			dup2 (pipex->fds[i][1], STDOUT_FILENO);
		ft_close_fds(pipex);
		execve (pipex->path[i], pipex->cmd[i], NULL);
	}
	if (i != pipex->total_pipes)
		close (pipex->fds[i][1]);
	waitpid(pipex->pid[i], NULL, 0);
	return (0);
}

int	ft_create_pipes(t_pipex *pipex)
{
	int i;

	i = 0;
	while (i < pipex->total_pipes)
	{
		if (pipe(pipex->fds[i++]) == -1)
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
	}
	return (0);
}

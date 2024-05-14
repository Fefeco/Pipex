/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:56:37 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/14 14:03:18 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_create_pipe(t_pipex *pipex, int i)
{
	if (pipe(pipex->fds[i]) == -1)
		return (1);
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
		return (1);
	if (pipex->pid[i] == 0)
	{
		ft_close_fds(pipex, i);
		close (pipex->fds[i][0]);
		dup2 (pipex->fd_in, STDIN_FILENO);
		dup2 (pipex->fds[i][1], STDOUT_FILENO);
		close (pipex->fds[i][1]);
		execve (pipex->path[0], pipex->cmd[0], NULL);
	}
	return (0);
}

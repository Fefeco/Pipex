/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:56:37 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/09 18:27:49 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_create_pipe(t_pipex *pipex)
{
	if (pipe(pipex->fds) == -1)
		return (1);
	pipex->pid[0] = fork();
	if (pipex->pid[0] == -1)
		return (1);
	if (pipex->pid[0] == 0)
	{
		close (pipex->fds[0]);
		dup2 (pipex->fd1, STDIN_FILENO);
		dup2 (pipex->fds[1], STDOUT_FILENO);
		close (pipex->fds[1]);
		execve (pipex->path[0], pipex->cmd[0], NULL);
	}
	return(0);
}

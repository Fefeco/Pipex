/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:39:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/13 17:44:30 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_create_process(t_pipex *pipex, int i)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		dup2 (pipex->fds[i][0], STDIN_FILENO);
		if (i < pipex->cmd_len - 1)
			dup2 (pipex->fds[i + 1][1], STDOUT_FILENO);
		else
			dup2 (pipex->fd_out, STDOUT_FILENO);
		ft_close_fds(pipex);
		execve (pipex->path[i], pipex->cmd[i], NULL);
	}
	close (pipex->fds[i][1]);
	waitpid(pid, NULL, 0);
	return (0);
}

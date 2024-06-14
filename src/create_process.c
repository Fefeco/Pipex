/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:39:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/14 12:41:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_process(t_pipex *pipex, int i)
{
	if (pipex->cmds->index == 0)
		dup2 (pipex->fd_in, STDIN_FILENO);
	else
		dup2 (pipex->fds[i - 1][0], STDIN_FILENO);
	if (!pipex->cmds->next)
		dup2 (pipex->fd_out, STDOUT_FILENO);
	else
		dup2 (pipex->fds[i][1], STDOUT_FILENO);
	execve (pipex->cmds->path, pipex->cmds->command, NULL);
	perror ("pipex");
}

int	ft_create_process(t_pipex *pipex, int i)
{
	int	pid;

	if (pipex->cmds->index == 0 && pipex->fd_in == -1)
		return (close (pipex->fds[i][1]));
	if (!pipex->cmds->next && pipex->fd_out == -1)
		return (1);
	if (!pipex->cmds->path)
	{
		ft_print_stderr(pipex->cmds->command[0], "command not found");
		if (i < pipex->tot_cmds - 1)
			close (pipex->fds[i][1]);
		return (1);
	}
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		ft_exec_process(pipex, i);
	if (i < pipex->tot_cmds - 1)
		close (pipex->fds[i][1]);
	waitpid(pid, NULL, 0);
	return (0);
}

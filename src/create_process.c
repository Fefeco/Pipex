/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:39:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/13 20:54:47 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_first_cmd(char *file_name)
{
	int	fd_in;

	fd_in = ft_open_fd(file_name, O_RDONLY);
	if (fd_in == -1)
		return (1);
	dup2 (fd_in, STDIN_FILENO);
	return (0);
}

int	ft_last_cmd(char *file_name)
{
	int	fd_out;

	fd_out = ft_open_fd(file_name, O_WRONLY | O_TRUNC | O_CREAT);
	if (fd_out == -1)
		return (1);
	dup2 (fd_out, STDOUT_FILENO);
	return (0);
}

int	ft_create_process(char **argv, t_pipex *pipex, int i)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (i == 0 && ft_first_cmd(argv[0]))
			return (close (pipex->fds[i][1]));
		else
			dup2 (pipex->fds[i - 1][0], STDIN_FILENO);
		if (!pipex->cmds->next && ft_last_cmd(argv[pipex->tot_cmds + 1]))
			return (close (pipex->fds[i][1]));
		else
			dup2 (pipex->fds[i][1], STDOUT_FILENO);
		execve (pipex->cmds->path, pipex->cmds->command, NULL);
		perror ("pipex");
	}
	close (pipex->fds[i][1]);
	waitpid(pid, NULL, 0);
	return (0);
}

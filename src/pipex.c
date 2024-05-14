/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/14 12:48:49 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	(void)argv;
	(void)env;
/*	if (argc != 5)
		return (perror("INVALID NUMBER OF ARGUMENTS\n"), 1);*/
	pipex.total_cmds = argc - 3;
	ft_init_cmds(argv, &pipex);
	ft_init_paths(env, &pipex);
	if (ft_open_files(argc, argv, &pipex))
		return (1);
	ft_init_fds(&pipex);
	ft_init_pids(&pipex);
	i = 0;
	while (i <= pipex.total_cmds)
	{
		if (ft_create_pipe(&pipex, i))
			return (1);
		++i;
	}
/*	if (pipe(pipex.fds) == -1)
	{
		perror("Error pipe()\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error fork()\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(pipex.fds[0]);
		dup2(pipex.fd1, STDIN_FILENO);
		dup2(pipex.fds[1], STDOUT_FILENO);
		close(pipex.fds[1]);
		execve(pipex.path1, pipex.cmd[0], NULL);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error fork()\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(pipex.fds[1]);
		dup2(pipex.fds[0], STDIN_FILENO);
		close(pipex.fds[1]);
		dup2(pipex.fd2, STDOUT_FILENO);
		close(pipex.fd2);
		execve(pipex.path2, pipex.cmd[1], NULL);
	}
	close(pipex.fds[0]);
	close(pipex.fds[1]);
	wait(NULL);
	ft_printf("%s esta en %s y %s en %s\n", pipex.cmd[0][0], pipex.path1, pipex.cmd[1][0], pipex.path2);
	ft_free_array((void *)pipex.cmd[0]);
	ft_free_array((void *)pipex.cmd[1]);
	return (free (pipex.path1), free (pipex.path2), 0);*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/08 13:58:24 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		pid;

	if (argc != 5)
		return (perror("INVALID NUMBER OF ARGUMENTS\n"), 1);
	pipex.fd1 = open(argv[1], O_RDONLY);
	pipex.fd2 = open(argv[4], O_WRONLY | O_CREAT, 0777);

	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');

	if (pipex.fd1 == -1)
		return (ft_printf("no such file or directory: %s\n", argv[1]), 1);
	if (pipex.fd2 == -1)
		return (ft_printf("no such file or directory: %s\n", argv[4]), 1);

	pipex.path1 = ft_get_path(env, pipex.cmd1[0]);
	if (!pipex.path1)
		return (ft_printf("command not found: %s\n", pipex.cmd1[0]), 1);
	pipex.path2 = ft_get_path(env, pipex.cmd2[0]);
	if (!pipex.path2)
		return (free (pipex.path1), ft_printf("command not found: %s\n", pipex.cmd2[0]), 1);

	if (pipe(pipex.fds) == -1)
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
		execve(pipex.path1, pipex.cmd1, NULL);
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
		execve(pipex.path2, pipex.cmd2, NULL);
	}
	close(pipex.fds[0]);
	close(pipex.fds[1]);
	wait(NULL);
	ft_free_array((void *)pipex.cmd1);
	ft_free_array((void *)pipex.cmd2);
	ft_printf("%s esta en %s y %s en %s\n", argv[2], pipex.path1, argv[3], pipex.path2);
	return (free (pipex.path1), free (pipex.path2), 0);	
}

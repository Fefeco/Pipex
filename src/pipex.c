/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/06 14:02:18 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd1;
	int		fd2;
	int		fds[2];
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	int		pid;

	if (argc != 5)
		return (perror("INVALID NUMBER OF ARGUMENTS\n"), 1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_WRONLY | O_CREAT, 0777);

	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');

	if (fd1 == -1)
		return (ft_printf("no such file or directory: %s\n", argv[1]), 1);
	fd2 = open(argv[4], O_RDONLY);
	if (fd2 == -1)
		return (ft_printf("no such file or directory: %s\n", argv[4]), 1);

	path1 = ft_get_path(env, cmd1[0]);
	if (!path1)
		return (ft_printf("command not found: %s\n", cmd1[0]), 1);
	path2 = ft_get_path(env, cmd2[0]);
	if (!path2)
		return (free (path1), ft_printf("command not found: %s\n", cmd2[0]), 1);

	if (pipe(fds) == -1)
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
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		execve(path1, cmd1, NULL);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error fork()\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		dup2(fd2, STDOUT_FILENO);
		close(fd2);
		execve(path2, cmd2, NULL);
	}
	close(fds[0]);
	close(fds[1]);
	wait(NULL);
	ft_free_array((void *)cmd1);
	ft_free_array((void *)cmd2);
	ft_printf("%s esta en %s y %s en %s\n", argv[2], path1, argv[3], path2);
	return (free (path1), free (path2), 0);	
}

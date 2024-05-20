/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/20 15:14:51 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit_clean(t_pipex *pipex)
{
	int	len;

	len = 0;
	while (pipex->cmd[len])
		++len;
	ft_free_cmds(pipex, len);
	ft_free_array((void **)pipex->path);
	ft_free_fds(pipex, len);
	free(pipex->pid);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;
	int		mode;

	if (argc < 5)
		return (ft_putstr_fd(EWRARGS, 2), 1);
	mode = (O_WRONLY | O_CREAT);
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		pipex.fd_out = ft_open_file(argv[argc - 1], mode | O_APPEND);
		pipex.std_in = ft_read_from_file(STDIN_FILENO, argv[2]);
		argv++;
	}
	else
	{
		pipex.fd_out = ft_open_file(argv[argc - 1], mode | O_TRUNC);
		pipex.fd_in = ft_open_file(argv[1], O_RDONLY);
		pipex.std_in = ft_read_from_file(pipex.fd_in, NULL);
	}
	ft_init_cmds(argv + 2, &pipex);
	ft_init_paths(env, &pipex);
	ft_init_fds(&pipex);
	ft_init_pids(&pipex);
	if (ft_create_pipes(&pipex))
		return (ft_exit_clean(&pipex), 1);
	i = 0;
//	while (i < pipex.total_cmds)
//		ft_create_process(&pipex, i++);
	close(pipex.fd_in);
	close(pipex.fd_out);
	ft_exit_clean(&pipex);
	return (0);
}

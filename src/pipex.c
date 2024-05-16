/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/16 12:02:16 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_clean(t_pipex *pipex)
{
	ft_free_cmds(pipex);
	ft_free_array((void **)pipex->path);
	ft_free_fds(pipex);
	free(pipex->pid);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	if (argc != 5)
		return (ft_putstr_fd("Invalid number of arguments\n", 2), 1);
	pipex.total_cmds = argc - 3;
	pipex.total_pipes = pipex.total_cmds - 1;
	ft_init_cmds(argv, &pipex);
	ft_init_paths(env, &pipex);
	if (ft_open_files(argc, argv, &pipex))
		return (1);
	ft_init_fds(&pipex);
	ft_init_pids(&pipex);
	if (ft_create_pipes(&pipex))
		return (ft_exit_clean(&pipex), 1);
	i = 0;
	while (i < pipex.total_cmds)
		ft_create_process(&pipex, i++);
	ft_exit_clean(&pipex);
	return (0);
}

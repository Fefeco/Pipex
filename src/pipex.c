/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/15 13:48:21 by fcarranz         ###   ########.fr       */
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
	pipex.total_pipes = pipex.total_cmds - 1;
	ft_init_cmds(argv, &pipex);
	ft_init_paths(env, &pipex);
	if (ft_open_files(argc, argv, &pipex))
		return (1);
	ft_init_fds(&pipex);
	ft_init_pids(&pipex);
	ft_printf("Llego\n");
	if (ft_create_pipes(&pipex))
		return (1); // Falta liberar memoria antes de salir
	i = 0;
	while (i < pipex.total_cmds)
		ft_create_process(&pipex, i++);
	ft_free_cmds(&pipex);
	ft_free_fds(&pipex);
	ft_free_array((void **)pipex.path);
	return (0);
}

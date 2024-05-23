/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/23 13:59:05 by fcarranz         ###   ########.fr       */
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
		return (ft_putstr_fd(EWRARGS, 2), 1);
	if (ft_parse_args(&pipex, ++argv, argc - 3, env))
		exit(EXIT_FAILURE);
//	ft_open_files(&pipex, argv, argc);
	pipex.std_in = ft_read_from_file(pipex.fd_in);
//	ft_init_cmds(argv + 2, &pipex);
//	ft_init_paths(env, &pipex);
	ft_init_fds(&pipex);
	ft_init_pids(&pipex);
	if (ft_create_pipes(&pipex))
		return (ft_exit_clean(&pipex), 1);
	write(pipex.fds[0][1], pipex.std_in, ft_strlen(pipex.std_in));
	free (pipex.std_in);
	i = 0;
	while (i < pipex.cmd_len)
		ft_create_process(&pipex, i++);
	ft_exit_clean(&pipex);
	return (0);
}

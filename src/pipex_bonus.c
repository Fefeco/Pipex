/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/18 12:15:07 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit_clean(t_pipex *pipex)
{
	ft_free_cmds(pipex);
	ft_free_array((void **)pipex->path);
	ft_free_fds(pipex);
	free(pipex->pid);
}
void	ft_set_params_for_hd(char *flag, t_pipex *pipex)
{
	pipex->hd_in = ft_read_from_hd(flag);
	if (!pipex->hd_in)
		exit (EXIT_FAILURE);
	pipex->total_cmds -= 1;
	pipex->total_pipes += 1;
	pipex->start_cmd += 1;	
	pipex->here_doc = 1;
}


int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	if (argc < 5)
		return (ft_putstr_fd("invalid number of arguments\n", 2), 1);
	pipex.total_cmds = argc - 3;
	pipex.total_pipes = pipex.total_cmds - 1;
	pipex.start_cmd = 2;	
	pipex.here_doc = 0;
	if (!ft_strncmp(argv[1], "here_doc", 8))
		ft_set_params_for_hd(argv[2], &pipex);
	ft_init_cmds(argv + pipex.start_cmd, &pipex);
	ft_init_paths(env, &pipex);
	ft_init_fds(&pipex);
	ft_init_pids(&pipex);
	if (ft_open_files(argc, argv, &pipex) || ft_create_pipes(&pipex))
		return (ft_exit_clean(&pipex), 1);
	i = 0;
	while (i < pipex.total_cmds)
		ft_create_process(&pipex, i++);
	close(pipex.fd_in);
    close(pipex.fd_out);
	ft_exit_clean(&pipex);
	return (0);
}

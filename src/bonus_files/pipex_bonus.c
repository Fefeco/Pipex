/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/29 15:45:18 by fcarranz         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	if (argc < 5 || (argc == 5 && !ft_strncmp(argv[1], "here_doc", 8)))
		return (ft_putstr_fd(EWRARGS, 2), 1);
	if (ft_parse_args(&pipex, ++argv, argc - 3, env))
		exit(EXIT_FAILURE);
	if (!ft_strncmp(argv[0], "here_doc", 8))
		pipex.std_in = ft_read_from_file(STDIN_FILENO, argv[1]);
	else
		pipex.std_in = ft_read_from_file(pipex.fd_in, NULL);
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

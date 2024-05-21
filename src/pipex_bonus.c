/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/21 13:55:13 by fcarranz         ###   ########.fr       */
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

static int	aux(t_pipex *pipex, char ***argv, char **env)
{
	int	i;

	ft_init_cmds(*argv + 2, pipex);
	ft_init_paths(env, pipex);
	ft_init_fds(pipex);
	ft_init_pids(pipex);
	if (ft_create_pipes(pipex))
		return (ft_exit_clean(pipex), 1);
	write(pipex->fds[0][1], pipex->std_in, ft_strlen(pipex->std_in));
	free (pipex->std_in);
	i = 0;
	while (i < pipex->cmd_len)
		ft_create_process(pipex, i++);
	ft_exit_clean(pipex);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
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
	return (aux(&pipex, &argv, env));
}

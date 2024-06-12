/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/12 17:20:45 by fcarranz         ###   ########.fr       */
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

static void	ft_exit_wrong_args(void)
{
	ft_putendl_fd("pipex: invalid number of arguments", 2);
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	if (argc != 5)
		ft_exit_wrong_args();
	i = 1;
	while (i < argc)
		if (!ft_isalnum(argv[i++][0]))
			ft_exit_wrong_args();
	pipex.fd_in = ft_open_fd_in(argv[1], O_RDONLY);
	if (ft_parse_args(&pipex, ++argv, argc - 3, env))
		exit(EXIT_FAILURE);
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

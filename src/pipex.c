/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/16 12:01:11 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_fds(t_pipex *pipex)
{
	int	len;

	len = pipex->tot_cmds - 2;
	while (len >= 0)
		free (pipex->fds[len--]);
	free (pipex->fds);
}

static void	ft_exit_wrong_args(void)
{
	ft_putendl_fd("pipex: invalid number of arguments", 2);
	exit (EXIT_FAILURE);
}

static t_cmd	*ft_get_next_cmd(t_cmd *cmds)
{
	t_cmd	*tmp;

	tmp = cmds;
	cmds = cmds->next;
	ft_free_cmd_struct(tmp);
	return (cmds);
}

static void	ft_chech_first_or_last(t_pipex *pipex, char **argv, int argc)
{
	if (pipex->cmds->index == 0)
		pipex->fd_in = ft_open_fd_in(argv[1], O_RDONLY);
	if (!pipex->cmds->next)
		pipex->fd_out = ft_open_fd_out(argv[argc -1], O_WRONLY
				| O_TRUNC | O_CREAT);
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
	pipex.tot_cmds = argc -3;
	pipex.cmds = ft_parser(argv + 2, pipex.tot_cmds, env);
	pipex.fds = ft_init_fds(pipex.tot_cmds);
	ft_create_pipes(&pipex);
	i = 0;
	while (pipex.cmds)
	{
		ft_chech_first_or_last(&pipex, argv, argc);
		ft_create_process(&pipex, i);
		pipex.cmds = ft_get_next_cmd(pipex.cmds);
		++i;
	}
	ft_free_fds (&pipex);
	return (0);
}

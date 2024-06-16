/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/16 13:05:43 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_chech_first_or_last(t_pipex *pipex, char **argv, int argc)
{
	if (pipex->cmds->index == 0 && !pipex->here_doc_exist)
		pipex->fd_in = ft_open_fd_in(argv[1], O_RDONLY);
	if (pipex->cmds->index == 0 && pipex->here_doc_exist)
		pipex->fd_in = ft_open_fd_in(pipex->hd_file, O_RDONLY);
	if (!pipex->cmds->next && !pipex->here_doc_exist)
		pipex->fd_out = ft_open_fd_out(argv[argc -1], O_WRONLY
				| O_TRUNC | O_CREAT);
	if (!pipex->cmds->next && pipex->here_doc_exist)
		pipex->fd_out = ft_open_fd_out(argv[argc -1], O_WRONLY
				| O_APPEND | O_CREAT);
	if (pipex->cmds->index == 1 && pipex->here_doc_exist)
		unlink (pipex->hd_file);
}

static void	ft_exit_wrong_args(int error)
{
	if (error == 1)
		ft_putendl_fd("pipex: invalid number of arguments", 2);
	if (error == 2)
		ft_putendl_fd("pipex: passing invalid argument/s", 2);
	exit (EXIT_FAILURE);
}

static void	ft_check_wrong_args(char c)
{
	if (!ft_isalnum(c))
		if (c != '/')
			ft_exit_wrong_args(2);
}

static t_cmd	*ft_get_next_cmd(t_cmd *cmds)
{
	t_cmd	*tmp;

	tmp = cmds;
	cmds = cmds->next;
	ft_free_cmd_struct(tmp);
	return (cmds);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	if (argc < 5 || (ft_check_here_doc(&pipex, argv[1]) && argc == 5))
		ft_exit_wrong_args(1);
	i = 1;
	while (i < argc)
		ft_check_wrong_args(argv[i++][0]);
	ft_set_params(&pipex, argv, argc, env);
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

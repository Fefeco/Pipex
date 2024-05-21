/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:31:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/21 14:36:41 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_cmds(char **argv, t_pipex *pipex)
{
	int		i;

	pipex->cmd_len = 0;
	while (argv[pipex->cmd_len + 1])
		pipex->cmd_len++;
	pipex->cmd = (char ***)malloc(sizeof(char ***) * (pipex->cmd_len + 1));
	if (!pipex->cmd)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < pipex->cmd_len)
		pipex->cmd[i++] = NULL;
	i = 0;
	while (i < pipex->cmd_len)
	{
		pipex->cmd[i] = ft_split(argv[i], ' ');
		if (!pipex->cmd[i])
		{
			ft_free_cmds(pipex);
			break ;
		}
		++i;
	}
}

static void	ft_init_paths_aux(t_pipex *pipex, int i)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(pipex->cmd[i][0], 2);
	ft_putstr_fd("\n", 2);
	ft_free_cmds(pipex);
	ft_free_array((void **)pipex->path);
	exit(EXIT_FAILURE);
}

void	ft_init_paths(char **env, t_pipex *pipex)
{
	char	*tmp;
	int		i;
	int		len;

	len = pipex->cmd_len;
	pipex->path = (char **)malloc(sizeof(char **) * (len + 1));
	if (!pipex->path)
	{
		ft_free_cmds(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->path[len] = NULL;
	i = 0;
	while (i < len)
	{
		tmp = ft_get_path(env, pipex->cmd[i][0]);
		if (!tmp)
			ft_init_paths_aux(pipex, i);
		pipex->path[i] = tmp;
		tmp = NULL;
		++i;
	}
}

void	ft_init_fds(t_pipex *pipex)
{
	int	i;
	int	len;

	len = pipex->cmd_len;
	pipex->fds = (int **)malloc(sizeof(int **) * (len));
	if (!pipex->fds)
	{
		ft_free_cmds(pipex);
		ft_free_array((void **)pipex->path);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < len)
	{
		pipex->fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipex->fds[i])
		{
			ft_free_fds(pipex);
			exit(EXIT_FAILURE);
		}
		++i;
	}
}

void	ft_init_pids(t_pipex *pipex)
{
	int	len;

	len = pipex->cmd_len;
	pipex->pid = (int *)malloc(sizeof(int *) * len);
	if (!pipex->pid)
	{
		ft_free_cmds(pipex);
		ft_free_array((void **)pipex->path);
		ft_free_fds(pipex);
		exit(EXIT_FAILURE);
	}
}

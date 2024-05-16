/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:31:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/16 10:29:01 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_cmds(char **argv, t_pipex *pipex)
{
	char	**tmp;
	int		i;

	pipex->cmd = (char ***)malloc(sizeof(char ***) * (pipex->total_cmds + 1));
	if (!pipex->cmd)
		exit(EXIT_FAILURE);
	i = 0;
	while (i <= pipex->total_cmds)
		pipex->cmd[i++] = NULL;
	i = 0;
	while (i != pipex->total_cmds)
	{
		tmp = ft_split(argv[i + 2], ' ');
		if (!tmp)
		{
			ft_free_cmds(pipex);
			break ;
		}
		pipex->cmd[i] = tmp;
		tmp = NULL;
		++i;
	}
}

void	ft_wstderr(const char *str)
{
	write (2, "command not found: ", 19);
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
}

void	ft_init_paths(char **env, t_pipex *pipex)
{
	char	*tmp;
	int		i;

	pipex->path = (char **)malloc(sizeof(char **) * (pipex->total_cmds + 1));
	if (!pipex->path)
	{
		ft_free_cmds(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->path[pipex->total_cmds] = NULL;
	i = 0;
	while (i < pipex->total_cmds)
	{
		tmp = ft_get_path(env, pipex->cmd[i][0]);
		if (!tmp)
		{
			ft_wstderr (pipex->cmd[i][0]);
			ft_free_cmds(pipex);
			ft_free_array((void **)pipex->path);
			exit(EXIT_FAILURE);
		}
		pipex->path[i] = tmp;
		tmp = NULL;
		++i;
	}
}

void	ft_init_fds(t_pipex *pipex)
{
	int	i;

	pipex->fds = (int **)malloc(sizeof(int **) * (pipex->total_pipes));
	if (!pipex->fds)
	{
		ft_free_cmds(pipex);
		ft_free_array((void **)pipex->path);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < pipex->total_pipes)
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
	pipex->pid = (int *)malloc(sizeof(int *) * pipex->total_cmds);
	if (!pipex->pid)
	{
		ft_free_cmds(pipex);
		ft_free_array((void **)pipex->path);
		ft_free_fds(pipex);
		exit(EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:31:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/09 21:12:13 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_cmds(t_pipex *pipex, int len)
{
	while (len-- != -1)
		while (*pipex->cmd[len])
			free (pipex->cmd[len]++);
	ft_free_array((void *)pipex->cmd);
}

void	ft_init_cmds(char **argv, t_pipex *pipex)
{
	char **tmp;
	int		i;

	pipex->cmd = (char ***)malloc(sizeof(char ***) * (pipex->total_cmds + 1));
	if (!pipex->cmd)
		exit(EXIT_FAILURE);
	pipex->cmd[pipex->total_cmds] = NULL;
	i = 0;
	while (i != pipex->total_cmds)
	{
		tmp = ft_split(argv[i + 2], ' ');
		if (!tmp)
		{
			ft_free_cmds(pipex, --i);
			break ;
		}
		pipex->cmd[i] = tmp;
		tmp = NULL;
		++i;
	}
}

void	ft_init_paths(char **env, t_pipex *pipex)
{
	char *tmp;
	int		i;

	pipex->path = (char **)malloc(sizeof(char **) * (pipex->total_cmds + 1));
	if (!pipex->path)
	{
		free (pipex->cmd);
		exit(EXIT_FAILURE);
	}
	pipex->path[pipex->total_cmds] = NULL;
	i = 0;
	while (i != pipex->total_cmds)
	{
		tmp	= ft_get_path(env, pipex->cmd[i][0]);
		if (!tmp)
		{
			ft_printf("command not found: %s\n", pipex->cmd[i][0]);
			ft_free_cmds(pipex, pipex->total_cmds);
			while (i-- != -1)
				free (pipex->path[i]);
			ft_free_array((void *)pipex->cmd);
			break ;
		}
		pipex->path[i] = tmp;
		tmp = NULL;
		++i;
	}
}

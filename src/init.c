/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:31:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/14 10:22:14 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_cmds(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	while (i <= pipex->total_cmds)
	{
		if (pipex->cmd[i])
		{
			j = 0;
			while (pipex->cmd[i][j])
				free (pipex->cmd[i][j++]);
			free (pipex->cmd[i][j]);
		}
		free (pipex->cmd[i]);
		++i;
	}
	free (pipex->cmd);
}

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
			ft_printf("command not found: %s\n", pipex->cmd[i][0]);
			ft_free_cmds(pipex);
			ft_free_array(pipex->path);
			exit(EXIT_FAILURE);
		}
		pipex->path[i] = tmp;
		tmp = NULL;
		++i;
	}
}

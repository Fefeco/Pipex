/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:31:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/12 18:58:55 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

t_cmd	*ft_init_cmd(char *arg, char **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		exit(EXIT_FAILURE);
	cmd->next = NULL;
	cmd->args = ft_split(arg, ' ');
	if (!cmd->args)
	{
		free (cmd);
		perror("Fail ft_split()");
		exit(EXIT_FAILURE);
	}
	if (cmd->args[0][0] == '/')
		cmd->path = cmd->args[0];
	else
		cmd->path = ft_get_path(env, cmd->args[0]);
	return (cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:59:46 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/14 12:30:25 by fcarranz         ###   ########.fr       */
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

void	ft_free_fds(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->total_cmds)
		free (pipex->fds[i++]);
	free (pipex->fds);
}


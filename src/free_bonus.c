/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:59:46 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/20 15:05:11 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_cmds(t_pipex *pipex, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i <= len)
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

void	ft_free_fds(t_pipex *pipex, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
		free (pipex->fds[i++]);
	free (pipex->fds);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:57:40 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/15 12:59:43 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fds(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->total_cmds - 2)
	{
		close(pipex->fds[i][0]);
		close(pipex->fds[i][1]);
		++i;
	}
}
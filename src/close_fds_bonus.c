/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:57:40 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/21 12:48:06 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_fds(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_len)
	{
		close(pipex->fds[i][0]);
		close(pipex->fds[i][1]);
		++i;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:39:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/16 20:43:56 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    ft_create_process_hd(t_pipex *pipex, int i)
{
    if (i == 0)
    {
        write (pipex->fds[0][1], pipex->hd_in, ft_strlen(pipex->hd_in));
        dup2 (pipex->fds[0][0],  STDIN_FILENO);
    }
    else
        dup2 (pipex->fds[i][0], STDIN_FILENO);
    if (i == pipex->total_pipes - 1)
        dup2 (pipex->fd_out, STDOUT_FILENO);
    else
        dup2 (pipex->fds[i + 1][1], STDOUT_FILENO);
    ft_close_fds(pipex);
    execve (pipex->path[i], pipex->cmd[i], NULL);

}

int	ft_create_process(t_pipex *pipex, int i)
{
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
		return (1);
	if (pipex->pid[i] == 0)
	{
        if (pipex->here_doc)
            ft_create_process_hd(pipex, i);
		if (i == 0)
			dup2 (pipex->fd_in, STDIN_FILENO);
		else
			dup2 (pipex->fds[i - 1][0], STDIN_FILENO);
		if (i == pipex->total_pipes)
			dup2 (pipex->fd_out, STDOUT_FILENO);
		else
			dup2 (pipex->fds[i][1], STDOUT_FILENO);
		ft_close_fds(pipex);
		execve (pipex->path[i], pipex->cmd[i], NULL);
	}
	if (i != pipex->total_pipes)
		close (pipex->fds[i][1]);
	waitpid(pipex->pid[i], NULL, 0);
	return (0);
}

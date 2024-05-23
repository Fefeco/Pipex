/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/23 13:45:05 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_wstderr(char *err)
{
	ft_putstr_fd(err, 2);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_open_files(t_pipex *pipex, char **argv, int argc)
{
	pipex->errors = NULL;
	if (access(argv[1], F_OK))
		ft_save_errors(ENOFILE, argv[1], pipex);
	else if (access(argv[1], R_OK))
		ft_save_errors(ENOAUTH, argv[1], pipex);
	else
		pipex->fd_in = open(argv[1], O_RDONLY);
	if (!access(argv[argc - 1], F_OK))
	{
		if (access(argv[argc - 1], W_OK))
			ft_save_errors(ENOAUTH, argv[argc - 1], pipex);
	}
	else
		pipex->fd_out = open(argv[argc - 1], O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_in == -1 || pipex->fd_out == -1)
		ft_wstderr(EOPENFD);
	if (!pipex->errors)
		return ;
	ft_putstr_fd(pipex->errors, 2);
	free (pipex->errors);
	exit(EXIT_FAILURE);
}

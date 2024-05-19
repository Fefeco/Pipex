/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/18 14:13:51 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_wstderr(char *err, char *file_name)
{
	ft_putstr_fd(err, 2);
	ft_putstr_fd(file_name, 2);
	write(2, "\n", 1);
}

int	ft_open_files(int argc, char **argv, t_pipex *pipex)
{
	int flags;

	flags = (O_WRONLY | O_CREAT | O_APPEND);
	if (!pipex->here_doc)
	{
		flags = (O_WRONLY | O_CREAT | O_TRUNC);
		if (access(argv[1], F_OK))
			return (ft_wstderr(ENOFILE, argv[1]), 1);
		if (access(argv[1], R_OK))
			return (ft_wstderr(ENOAUTH, argv[1]), 1);
		pipex->fd_in = open(argv[1], O_RDONLY);
		if (pipex->fd_in == -1)
			return (ft_wstderr(EOPENFD, argv[1]), 1);
	}
	if (access(argv[argc - 1], F_OK))
	{
		if (access(argv[argc - 1], W_OK))
			return (close(pipex->fd_in), ft_wstderr(ENOAUTH, argv[argc - 1]), 1);
	}
	pipex->fd_out = open(argv[argc - 1], flags, 0666);
	if (pipex->fd_out == -1)
		return (close(pipex->fd_in), ft_wstderr(EOPENFD, argv[argc - 1]), 1);
	return (0);
}

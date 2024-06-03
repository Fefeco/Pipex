/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/03 11:20:43 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_save_errors(char *error, char *cause, t_pipex *pipex)
{
	char	*full_error;

	full_error = ft_strjoin(ft_strdup(error), ft_strdup(cause));
	full_error = ft_strjoin(full_error, ft_strdup("\n"));
	if (pipex->errors)
		pipex->errors = ft_strjoin(pipex->errors, full_error);
	else
		pipex->errors = full_error;
}

static void	ft_open_fd_in_aux(int *fd)
{
	perror("pipex: 'entrada estandar'");
	close(*fd);
	*fd = -1;
}

int	ft_open_fd_in(char *file_name, int mode, t_pipex *pipex)
{
	int		fd;
	char	*check_directory;

	if (access(file_name, F_OK))
		ft_save_errors(ENOFILE, file_name, pipex);
	else if (access(file_name, R_OK))
		ft_save_errors(ENOAUTH, file_name, pipex);
	else
	{
		check_directory = (char *)malloc(1);
		if (!check_directory)
			return (-1);
		fd = open(file_name, mode);
		if (fd != -1)
		{
			if (read(fd, check_directory, 1) < 0)
				ft_open_fd_in_aux(&fd);
			free (check_directory);
			return (fd);
		}
		perror("Error function open()");
	}
	return (-1);
}

int	ft_open_fd_out(char *file_name, int mode, t_pipex *pipex)
{
	int	fd;

	if (!access(file_name, F_OK))
		if (access(file_name, W_OK))
			return (ft_save_errors(ENOAUTH, file_name, pipex), -1);
	fd = open(file_name, mode, 0644);
	if (fd != -1)
		return (fd);
	perror("pipex");
	return (-1);
}

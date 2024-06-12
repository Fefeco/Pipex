/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/12 18:09:02 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_open_fd_in(char *file_name, int mode)
{
	int		fd;

	fd = -1;
	if (access(file_name, F_OK | R_OK))
		ft_printf("pipex: %s: %s\n", strerror(errno), file_name);
	else
	{
		fd = open(file_name, mode);
			if (fd == -1)
				ft_printf("pipex: %s\n", strerror(errno));
	}
	return (fd);
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

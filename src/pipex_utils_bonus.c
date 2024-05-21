/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/21 13:45:44 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_wstderr(char *err, char *file_name)
{
	ft_putstr_fd(err, 2);
	ft_putstr_fd(file_name, 2);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	ft_open_file(char *file_name, int mode)
{
	int	fd;

	if (mode == O_RDONLY)
	{
		if (access(file_name, F_OK))
			ft_wstderr(ENOFILE, file_name);
		if (access(file_name, R_OK))
			ft_wstderr(ENOAUTH, file_name);
		fd = open(file_name, mode);
		if (fd == -1)
			ft_wstderr(EOPENFD, file_name);
		return (fd);
	}
	if (!access(file_name, F_OK))
		if (access(file_name, W_OK))
			ft_wstderr(ENOAUTH, file_name);
	fd = open(file_name, mode, 0644);
	if (fd == -1)
		ft_wstderr(EOPENFD, file_name);
	return (fd);
}

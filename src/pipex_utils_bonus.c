/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/16 20:46:10 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_open_files_aux(char *file_name, char *msj)
{
	ft_putstr_fd(msj, 2);
	ft_putstr_fd(file_name, 2);
	write(2, "\n", 1);
}

int	ft_open_files(int argc, char **argv, t_pipex *pipex)
{
	int	i;

	if (access(argv[1], F_OK))
	{
		ft_open_files_aux(argv[1], "pipex: no such file or directory: ");
		return (1);
	}
	if (access(argv[1], R_OK))
	{
		ft_open_files_aux(argv[1], "pipex: permission denied: ");
		return (1);
	}
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
	{
		ft_open_files_aux(argv[1], "pipex: error open file: ");
		return (1);
	}
	i = 0;
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (pipex->fd_out == -1)
		return (close(pipex->fd_in), 1);
	return (0);
}

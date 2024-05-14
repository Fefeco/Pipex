/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/14 10:42:47 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_files(int argc, char **argv, t_pipex *pipex)
{
	int	i;

	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
		return (ft_printf("no such file or directory: %s\n", argv[1]), 1);
	i = 0;
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (pipex->fd_out == -1)
		return (close(pipex->fd_in), 1);
	return (0);
}

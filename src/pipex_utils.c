/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/08 18:42:03 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_files(char **argv, t_pipex *pipex)
{
	int	i;

	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 == -1)
		return (ft_printf("no such file or directory: %s\n", argv[1]), 1);
	i = 0;
	while (argv[i + 1])
		++i;
	pipex->fd2 = open(argv[i], O_WRONLY | O_CREAT, 0644);
	if (pipex->fd2 == -1)
		return (ft_printf("no such file or directory: %s\n", argv[i]), 1);
	return (0);
}

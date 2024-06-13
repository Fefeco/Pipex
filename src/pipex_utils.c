/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/13 21:01:48 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_fd(char *file_name, int mode)
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

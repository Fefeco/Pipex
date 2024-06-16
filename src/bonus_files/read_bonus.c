/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:01:10 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/16 15:03:28 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_read_from(int fd, char *stop)
{
	char	*read_line;
	char	*full_line;

	full_line = NULL;
	read_line = get_next_line(fd);
	if (stop)
		stop = ft_strjoin(ft_strdup(stop), ft_strdup("\n"));
	while (read_line)
	{
		if (stop && !ft_strncmp_prot(read_line, stop, ft_lenstr(stop)))
		{
			free (read_line);
			free (stop);
			break ;
		}
		if (!full_line)
			full_line = read_line;
		else
			full_line = ft_strjoin(full_line, read_line);
		read_line = get_next_line(fd);
	}
	return (full_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:01:10 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/08 11:16:40 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_read_from_file(int fd, char *stop)
{
	char	*read_line;
	char	*full_line;

	full_line = (char *)malloc(1);
	if (!full_line)
		return (full_line);
	read_line = get_next_line(fd);
	while (read_line)
	{
		if (stop && !ft_strncmp_prot(read_line, stop, ft_strlen(read_line) - 1))
		{
			free (read_line);
			break ;
		}
		full_line = ft_strjoin(full_line, read_line);
		read_line = get_next_line(fd);
	}
	return (full_line);
}

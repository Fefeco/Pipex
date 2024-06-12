/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:59:40 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/12 13:38:39 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_read_from_file(int fd)
{
	char	*read_line;
	char	*full_line;

	full_line = get_next_line(fd);
	if (!full_line)
		return (NULL);
	read_line = get_next_line(fd);
	while (read_line)
	{
		full_line = ft_strjoin(full_line, read_line);
		read_line = get_next_line(fd);
	}
	return (full_line);
}

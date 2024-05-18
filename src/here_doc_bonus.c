/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:21:10 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/18 12:15:32 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_read_from_hd(char *delimiter)
{
	char	*line;
	char	*hd_stdin;

	hd_stdin = (char *)malloc(1);
	if (!hd_stdin)
		return (hd_stdin);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp_prot(line, delimiter, ft_strlen(delimiter)))
		{
			free (line);
			break ;
		}
		hd_stdin = ft_strjoin(hd_stdin, line);
		line = get_next_line(STDIN_FILENO);
	}
	return (hd_stdin);
}

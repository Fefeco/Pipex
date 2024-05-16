/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:21:10 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/16 21:26:20 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_read_from_stdin(char *delimiter)
{
	char	*line;
	char	*str_stdin;

	line = NULL;
	str_stdin = NULL;
	while (!ft_strncmp_prot(line, delimiter, ft_strlen(delimiter)))
	{
		if (line)
			free (line);
		line = get_next_line(STDIN_FILENO);
		str_stdin = ft_strjoin(str_stdin, line);
	}
	ft_printf("CAPTURE %s\n", str_stdin);
}

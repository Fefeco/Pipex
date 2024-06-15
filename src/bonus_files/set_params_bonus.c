/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:28:54 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/15 20:33:54 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_set_params(t_pipex *pipex, char **argv, int argc, char **env)
{
	char	*read_from_here_doc;
	int		fd;

	if (pipex->here_doc_exist)
	{
		read_from_here_doc = ft_read_from(STDIN_FILENO, argv[2]);
		fd = open(pipex->hd_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		write (fd, read_from_here_doc, ft_strlen(read_from_here_doc));
		close (fd);
		free (read_from_here_doc);
		read_from_here_doc = NULL;
		pipex->tot_cmds = argc - 4;
		pipex->cmds = ft_parser(argv + 3, pipex->tot_cmds, env);
	}
	pipex->tot_cmds = argc - 3;
	pipex->cmds = ft_parser(argv + 2, pipex->tot_cmds, env);
}

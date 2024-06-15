/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/15 21:42:28 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_cmd_struct(t_cmd *cmd)
{
	int	i;

	if (cmd->path)
		free (cmd->path);
	i = 0;
	while (cmd->command[i])
		free (cmd->command[i++]);
	free (cmd->command);
	free (cmd);
	cmd = NULL;
}

void	ft_print_stderr(char *cause, char *error)
{
	write(2, "pipex: ", 7);
	write(2, cause, ft_strlen(cause));
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

int	ft_open_fd_in(char *file_name, int mode)
{
	int		fd;

	fd = open(file_name, mode);
	if (fd == -1)
		ft_printf("pipex: %s: %s\n", file_name, strerror(errno));
	return (fd);
}

int	ft_open_fd_out(char *file_name, int mode)
{
	int		fd;

	fd = open(file_name, mode, 0664);
	if (fd == -1)
		ft_printf("pipex: %s: %s\n", file_name, strerror(errno));
	return (fd);
}

bool	ft_check_here_doc(t_pipex *pipex, char *str)
{
	if (ft_strncmp(str, "here_doc\0", 9))
	{
		pipex->here_doc_exist = false;
		return (0);
	}
	pipex->here_doc_exist = true;
	pipex->hd_file = "here_doc.tmp";
	return (1);
}

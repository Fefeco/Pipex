/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:50:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/16 13:00:16 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_fds(t_pipex *pipex)
{
	int	len;

	len = pipex->tot_cmds - 2;
	while (len >= 0)
		free (pipex->fds[len--]);
	free (pipex->fds);
}

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
	write(2, cause, ft_lenstr(cause));
	write(2, ": ", 2);
	write(2, error, ft_lenstr(error));
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

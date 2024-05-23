/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:58:09 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/23 18:39:49 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_save_errors(char *error, char *cause, t_pipex *pipex)
{
	char	*full_error;

	full_error = ft_strjoin(ft_strdup(error), ft_strdup(cause));
	full_error = ft_strjoin(full_error, ft_strdup("\n"));
	if (pipex->errors)
		pipex->errors = ft_strjoin(pipex->errors, full_error);
	else
		pipex->errors = full_error;
}

int	ft_open_fin(char *file_name, int mode, t_pipex *pipex)
{
	int	fd;

	if (access(file_name, F_OK))
		ft_save_errors(ENOFILE, file_name, pipex);
	else if (access(file_name, R_OK))
		ft_save_errors(ENOAUTH, file_name, pipex);
	else
	{
		fd = open(file_name, mode);
		if (fd != -1)
			return (fd);
		perror("Error function open()");
	}
	return (-1);
}

int	ft_open_fout(char *file_name, int mode, t_pipex *pipex)
{
	int	fd;

	if (!access(file_name, F_OK))
		if (access(file_name, W_OK))
			return (ft_save_errors(ENOAUTH, file_name, pipex), -1);
	fd = open(file_name, mode);
	if (fd != -1)
		return (fd);
	perror("Error function open()");
	return (-1);
}

void	ft_free_cmd_err_path(t_pipex *pipex)
{
	free (pipex->errors);
	ft_free_array ((void **)pipex->path);
	ft_free_cmds(pipex);
}

void	ft_check_cmd(char *cmd, char **env, t_pipex *pipex)
{
	char	**tmp;
	char	*path;
	int		i;

	tmp = ft_split(cmd, ' ');
	if (!tmp)
	{
		perror("Fail ft_split()");
		ft_free_cmd_err_path(pipex);
		exit (EXIT_FAILURE);
	}
	if (tmp[0][0] == '/')
		path = ft_strdup(tmp[0]);
	else
		path = ft_get_path(env, tmp[0]);
	if (!path)
		ft_save_errors(ECMDNOF, tmp[0], pipex);
	else if (access(path, X_OK))
		ft_save_errors(ENOAUTH, tmp[0], pipex);
	i = 0;
	while (pipex->path[i])
		i++;
	pipex->path[i] = path;
	pipex->cmd[i] = tmp;
}

int	ft_alloc_cmd_err_path(t_pipex *pipex, int cmd_count)
{
	int	i;

	pipex->cmd_len = cmd_count;
	pipex->errors = NULL;
	pipex->path = (char **)malloc(sizeof(char **) * (cmd_count + 1));
	if (!pipex->path)
		return (1);
	pipex->path[cmd_count] = NULL;
	pipex->cmd = (char ***)malloc(sizeof(char ***) * (cmd_count + 1));
	if (!pipex->cmd)
		return (free (pipex->path), 1);
	i = 0;
	while (i <= cmd_count)
		pipex->cmd[i++] = NULL;
	return (0);
}

int	ft_parse_args(t_pipex *pipex, char **argv, int cmd_count, char **env)
{
	int	i;
	int	mode;

	if (ft_alloc_cmd_err_path(pipex, cmd_count))
		return (perror("Fail allocating memory"), 1);
	i = 0;
	pipex->fd_in = ft_open_fin(argv[i++], O_RDONLY, pipex);
	if (pipex->fd_in != -1)
		ft_check_cmd(argv[i], env, pipex);
	++i;
	while (i < cmd_count - 1)
		ft_check_cmd(argv[i++], env, pipex);
	mode = (O_WRONLY | O_CREAT | O_TRUNC);
	pipex->fd_out = ft_open_fout(argv[i + 1], mode, pipex);
	if (pipex->fd_out != -1)
		ft_check_cmd(argv[i], env, pipex);
	if (!pipex->errors)
		return (0);
	ft_putstr_fd(pipex->errors, 2);
	return (ft_free_cmd_err_path(pipex), 1);
}

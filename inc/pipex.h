/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:52 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/12 17:56:38 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

# define ENOFILE "pipex: no such file or directory: "
# define ECMDNOF "pipex: command not found: "
# define ENOAUTH "pipex: permission denied: "
# define EOPENFD "pipex: error open file descriptor: "

typedef struct s_cmd
{
	char			*path;
	char			*args;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	t_cmd	command;
	char	***cmd;
	char	**path;
	char	*std_in;
	char	*errors;
	int		cmd_len;
	int		fd_in;
	int		fd_out;
	int		**fds;
	int		*pid;
}	t_pipex;

int		ft_create_pipes(t_pipex *pipex);
int		ft_create_process(t_pipex *pipex, int i);
void	ft_free_cmds(t_pipex *pipex);
void	ft_free_fds(t_pipex *pipex);
char	*ft_get_path(char **env, char *cmd);
void	ft_init_fds(t_pipex *pipex);
void	ft_init_pids(t_pipex *pipex);
int		ft_open_fd_in(char *file_name, int mode);
int		ft_open_fd_out(char *file_name, int mode, t_pipex *pipex);
void	ft_close_fds(t_pipex *pipex);
char	*ft_read_from_file(int fd);
int		ft_parse_args(t_pipex *pipex, char **argv, int cmd_count, char **env);
void	ft_save_errors(char *error, char *cause, t_pipex *pipex);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:52 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/14 12:58:50 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

typedef struct s_cmd
{
	int				index;
	char			*path;
	char			**command;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	t_cmd	*cmds;
	int		tot_cmds;
	int		**fds;
	int		fd_in;
	int		fd_out;
}	t_pipex;

int		ft_create_pipes(t_pipex *pipex);
int		ft_create_process(t_pipex *pipex, int i);
char	*ft_get_path(char **env, char *cmd);
int		**ft_init_fds(int len);
int		ft_open_fd_in(char *file_name, int mode);
int		ft_open_fd_out(char *file_name, int mode);
void	ft_print_stderr(char *cause, char *error);
void	ft_free_cmd_struct(t_cmd *cmd);
t_cmd	*ft_parser(char **argv, int cmd_amount, char **env);
#endif

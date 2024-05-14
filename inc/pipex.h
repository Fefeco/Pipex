/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:52 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/14 12:27:16 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_pipex
{
	char	***cmd;
	int		total_cmds;
	char	**path;
	int		fd_in;
	int		fd_out;
	int		**fds;
	int		*pid;
}	t_pipex;

char	*ft_get_path(char **env, char *cmd);
int		ft_open_files(int argc, char **argv, t_pipex *pipex);
int		ft_create_pipe(t_pipex *pipex, int i);
void	ft_init_cmds(char **argv, t_pipex *pipex);
void	ft_init_paths(char **env, t_pipex *pipex);
void	ft_init_fds(t_pipex *pipex);
void	ft_init_pids(t_pipex *pipex);
void	ft_free_cmds(t_pipex *pipex);
void	ft_free_fds(t_pipex *pipex);

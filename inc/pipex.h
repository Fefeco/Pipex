/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:52 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/09 20:30:36 by fcarranz         ###   ########.fr       */
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
	int		fd1;
	int		fd2;
	int		fds[2];
	int		*pid;
}	t_pipex;

char	*ft_get_path(char **env, char *cmd);
int		ft_open_files(char **argv, t_pipex *pipex);
int		ft_create_pipe(t_pipex *pipex);
void	ft_init_cmds(char **argv, t_pipex *pipex);
void	ft_init_paths(char **env, t_pipex *pipex);

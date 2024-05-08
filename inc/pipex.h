/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:52 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/08 13:49:42 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	int		fd1;
	int		fd2;
	int		fds[2];
}	t_pipex;

char	*ft_get_path(char **env, char *cmd);

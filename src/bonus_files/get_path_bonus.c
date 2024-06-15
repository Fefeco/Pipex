/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:16:17 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/15 21:01:31 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**ft_get_env_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break ;
		++env;
	}
	return (env);
}

char	*ft_get_path(char **env, char *cmd)
{
	char	**paths;
	char	*full_path;
	int		i;

	if (!env | !cmd)
		return (NULL);
	env = ft_get_env_path(env);
	if (!*env)
		return (NULL);
	paths = ft_split(*env + 5, ':');
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(ft_strdup(paths[i]), ft_strdup("/"));
		full_path = ft_strjoin(full_path, ft_strdup(cmd));
		if (access(full_path, F_OK) == 0)
			break ;
		free (full_path);
		full_path = NULL;
		++i;
	}
	ft_free_array((void *)paths);
	return (full_path);
}

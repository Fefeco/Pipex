/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:46 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd1;
//	int		fd2;
	char	*path1;
	char	*path2;

	if (argc != 5)
		return (perror("INVALID NUMBER OF ARGUMENTS\n"), 1);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		return (ft_printf("no such file or directory: %s\n", argv[1]), 1);


	path1 = ft_get_path(env, argv[2]);
	if (!path1)
		return (ft_printf("command not found: %s\n", argv[2]), 1);
	path2 = ft_get_path(env, argv[3]);
	if (!path2)
		return (free (path1), ft_printf("command not found: %s\n", argv[3]), 1);
	ft_printf("%s esta en %s y %s en %s\n", argv[2], path1, argv[3], path2);
	free (path1);
	free (path2);

	return (0);	
}

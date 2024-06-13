/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:47:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/13 20:57:17 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	ft_exit_clean(t_pipex *pipex)
{
	ft_free_cmds(pipex);
}*/

static void	ft_exit_wrong_args(void)
{
	ft_putendl_fd("pipex: invalid number of arguments", 2);
	exit (EXIT_FAILURE);
}

static t_cmd	*ft_get_next_cmd(t_cmd *cmds)
{
	t_cmd	*tmp;

	tmp = cmds;
	cmds = cmds->next;
	free (tmp);
	tmp = NULL;
	return (cmds);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	if (argc != 5)
		ft_exit_wrong_args();
	i = 1;
	while (i < argc)
		if (!ft_isalnum(argv[i++][0]))
			ft_exit_wrong_args();
	pipex.tot_cmds = argc -3;
	pipex.cmds = ft_parser(argv + 2, pipex.tot_cmds, env);
	pipex.fds = ft_init_fds(pipex.tot_cmds);
	ft_create_pipes(&pipex);
	i = 0;
	while (pipex.cmds)
	{
		ft_create_process(argv++, &pipex, i);
		pipex.cmds = ft_get_next_cmd(pipex.cmds);
	}
//	ft_exit_clean(&pipex);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:00:59 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/13 16:28:33 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_free_cmds(t_cmd cmds)
{
	t_cmd	*tmp;

	while (cmds)
	{
		tmp = cmds->next;
		free (cmds);
		cmds = tmp;
	}
	return (1);
}

t_cmd	*ft_parcer(char **argv, int cmd_amount, char **env)
{
	int		i;
	t_cmd	*head;
	t_cmd	*cmds;

	i = 0;
	while (i < cmd_amount)
	{
		if (i == 0)
		{
			head = (t_cmd *)malloc(sizeof(t_cmd));
			if (!head)
				return (NULL);
			cmds = head;
		}
		else
		{
			cmds->next = (t_cmd *)malloc(sizeof(t_cmd));
			if (!cmds)
				return (ft_free_cmds(head));
			cmds = cmds->next;
		}
		cmds->cmd = ft_split(argv[i]);
		cmds->path = ft_get_path(env, cmds->cmd[0]);
		++i;
	}
	return (head);
}

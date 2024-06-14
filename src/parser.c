/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:00:59 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/14 12:57:01 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_free_commands(t_cmd *cmds)
{
	t_cmd	*tmp;

	while (cmds)
	{
		tmp = cmds->next;
		ft_free_cmd_struct(cmds);
		cmds = tmp;
	}
	return (NULL);
}

static t_cmd	*ft_addlast(t_cmd *head, t_cmd *cmds)
{
	t_cmd	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = cmds;
	return (head);
}

t_cmd	*ft_parser(char **argv, int cmd_amount, char **env)
{
	int		i;
	t_cmd	*head;
	t_cmd	*cmd;

	i = 0;
	while (i < cmd_amount)
	{
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!cmd)
			return (ft_free_commands(head));
		if (i == 0)
			head = cmd;
		else
			ft_addlast(head, cmd);
		cmd->index = i;
		cmd->command = ft_split(argv[i], ' ');
		cmd->path = ft_get_path(env, cmd->command[0]);
		cmd->next = NULL;
		++i;
	}
	return (head);
}

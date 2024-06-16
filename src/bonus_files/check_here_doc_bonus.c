/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:55:23 by fcarranz          #+#    #+#             */
/*   Updated: 2024/06/16 13:06:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

bool	ft_check_here_doc(t_pipex *pipex, char *str)
{
	if (ft_strncmp(str, "here_doc\0", 9))
	{
		pipex->here_doc_exist = false;
		return (0);
	}
	pipex->here_doc_exist = true;
	pipex->hd_file = "here_doc.tmp";
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_char_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:04:20 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/01 13:28:56 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_char_nb(char *nb)
{
	int	len;
	int	zero_flag;

	len = 0;
	zero_flag = 0;
	if (*nb == '-')
		++nb;
	while (*nb == '0')
	{
		++zero_flag;
		++nb;
	}
	if (!*nb && zero_flag)
		return (1);
	while (*nb)
	{
		if (!ft_strchr(NUMBERS, *nb))
			return (-1);
		++nb;
		++len;
	}
	return (len);
}

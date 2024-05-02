/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:51:40 by fcarranz          #+#    #+#             */
/*   Updated: 2024/02/08 13:07:54 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_write_arg(va_list args, char indicator);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_nb(int nb);
int		ft_print_unsigned(unsigned int un);
int		ft_putnbr(int nb);
size_t	ft_strlen(const char *str);
int		ft_print_hexa(char *bstab, unsigned int n);
int		ft_print_ptr(void *ptr);

#endif

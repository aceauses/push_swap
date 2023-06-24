/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:47:00 by aceauses          #+#    #+#             */
/*   Updated: 2023/05/08 16:30:44 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);

int		ft_putchar(char c);
int		ft_putstr(char *c);
size_t	ft_strlen(const char *str);

int		ft_put_ptr(void *p);
int		ft_print_hex(unsigned int num, int format);

int		ft_putnmbr(long int n);
int		ft_putnmbr_un(unsigned int n);
#endif
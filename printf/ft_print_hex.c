/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:18:01 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/23 22:01:15 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int index)
{
	int	i;

	i = 0;
	while (index != 0)
	{
		i++;
		index = index / 16;
	}
	return (i);
}

static void	ft_printf_hex(unsigned int num, int format)
{
	if (num >= 16)
	{
		ft_printf_hex(num / 16, format);
		ft_printf_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			else if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int num, int format)
{
	if (num == 0)
		return (ft_putchar('0'));
	else
		ft_printf_hex(num, format);
	return (ft_hex_len(num));
}

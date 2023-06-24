/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:37:24 by aceauses          #+#    #+#             */
/*   Updated: 2023/05/08 16:43:16 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long index)
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

static int	ft_printf_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_printf_ptr(num / 16);
		ft_printf_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
	return (ft_ptr_len(num));
}

int	ft_put_ptr(void *p)
{
	unsigned long	ptr;
	int				len;

	len = 0;
	ptr = (unsigned long)p;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += 1;
	return (len + ft_printf_ptr(ptr));
}

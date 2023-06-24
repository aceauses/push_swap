/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:47:11 by aceauses          #+#    #+#             */
/*   Updated: 2023/05/08 16:30:51 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_symbol(va_list args, int c)
{
	int	print;

	print = 0;
	if (c == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (c == 'd' | c == 'i')
		print += ft_putnmbr(va_arg(args, int));
	else if (c == 'u')
		print += ft_putnmbr_un(va_arg(args, unsigned int));
	else if (c == 'p')
		print += ft_put_ptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
		print += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		print += ft_putchar('%');
	return (print);
}

int	ft_printf(const char *str, ...)
{
	int		print;
	int		i;
	va_list	args;

	print = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += printf_symbol(args, str[i + 1]);
			i++;
		}
		else
			print += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}

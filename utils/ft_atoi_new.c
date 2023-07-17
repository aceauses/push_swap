/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:13:59 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/10 17:53:50 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Check if str is not a digit*/
int	ft_atoi_new(const char *str)
{
	int			sign;
	int long	number;

	sign = 1;
	number = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (!ft_isdigit(*str))
			ft_error();
		number *= 10;
		number += *str - 48;
		str++;
	}
	if ((sign * number) > 2147483647 || (sign * number) < -2147483648)
		ft_error();
	return (number * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:15:52 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/26 13:40:13 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sort(t_node *a)
{
	int	tmp;

	tmp = a->index;
	while (a)
	{
		if (tmp > a->index)
			return (0);
		tmp = a->index;
		a = a->next;
	}
	return (1);
}

/*
  1 2 3 4
  |
  |
 tmp
*/
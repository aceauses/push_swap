/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:55 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/28 14:04:53 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stack_len(t_node *a)
{
	int	count;

	if (!a)
		return (0);
	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

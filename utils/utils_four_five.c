/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:50:21 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/14 17:40:53 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_b(t_node **a, t_node **b, int location)
{
	if (location == 0)
	{
		ft_pb(a, b);
		return ;
	}
	else if (location == 1)
		ft_sa(a, 1);
	else if (location == 2)
	{
		ft_rra(a, 1);
		ft_rra(a, 1);
	}
	else
		ft_rra(a, 1);
	if (!ft_is_sort(*a))
		ft_pb(a, b);
}

int	find_min(t_node **a)
{
	t_node	*temp;
	int		i;
	int		loc;
	int		max;

	temp = *a;
	loc = 0;
	max = 0;
	i = (*a)->index;
	while (temp != NULL)
	{
		if (temp->index < i)
		{
			i = temp->index;
			loc = max;
		}
		temp = temp->next;
		max++;
	}
	return (loc);
}

void	set_min(t_node **a, t_node **b)
{
	int	min;

	min = find_min(a);
	if (min == 4)
		ft_rra(a, 1);
	else if (min == 3)
	{
		ft_rra(a, 1);
		if (ft_lst_size(*a) == 5)
			ft_rra(a, 1);
	}
	else if (min == 2)
	{
		ft_ra(a, 1);
		ft_sa(a, 1);
	}
	else if (min == 1)
		ft_sa(a, 1);
	ft_pb(a, b);
}

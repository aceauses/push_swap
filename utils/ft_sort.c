/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:41:43 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/04 16:45:24 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_node **a)
{
	int		c;
	t_node	*b;

	b = NULL;
	c = (*a)->index;
	if (c > (*a)->next->index)
		ft_sa(a, 1);
	if ((*a)->next->next->index < c)
		ft_rra(a, 1);
	c = (*a)->index;
	if (c > (*a)->next->index)
		ft_sa(a, 1);
	if ((*a)->next->index > (*a)->next->next->index)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
}

void	ft_sort_four(t_node **a)
{
	t_node	*b;
	int		loc;

	b = NULL;
	loc = find_min(a);
	push_to_b(a, &b, loc);
	ft_sort_three(a);
	ft_pa(a, &b);
}

void	push_to_b(t_node **a, t_node **b, int location)
{
	if (location == 0)
		ft_pb(a, b);
	else if (location == 1)
	{
		ft_sa(a, 1);
		ft_pb(a, b);
	}
	else if (location == 2)
	{
		ft_rra(a, 1);
		ft_rra(a, 1);
		ft_pb(a, b);
	}
	else
	{
		ft_rra(a, 1);
		ft_pb(a, b);
	}
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

void	ft_sort(t_node *a)
{
	t_node	*b;

	b = NULL;
	// a = ft_sort_a(&a);
	print_stacks(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:41:43 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/07 17:25:06 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_node **a)
{
	int		head;
	int		tail;
	int		mid;

	head = (*a)->index;
	mid = (*a)->next->index;
	tail = (*a)->next->next->index;
	if (head > tail && head > mid)
		ft_ra(a, 1);
	if (head > mid && tail > head)
		ft_sa(a, 1);
	if (mid > head && mid > tail)
		ft_rra(a, 1);
	if (!ft_is_sort(*a))
		ft_sa(a, 1);
}

void	ft_sort_four(t_node **a)
{
	t_node	*b;
	int		loc;

	b = NULL;
	loc = find_min(a);
	push_to_b(a, &b, loc);
	if (!ft_is_sort(*a))
	{
		ft_sort_three(a);
		ft_pa(a, &b);
	}
}

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

static void	ft_push_to_3(t_node **a, t_node **b)
{
	int		size;
	int		push;
	int		i;

	size = ft_lst_size(*a);
	push = 0;
	i = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			ft_pb(a, b);
			push++;
		}
		else
			ft_ra(a, 1);
		i++;
	}
	while (size - push > 3)
	{
		ft_pb(a, b);
		push++;
	}
}

void	ft_sort(t_node *a)
{
	t_node	*b;

	b = NULL;
	ft_push_to_3(&a, &b);
	ft_sort_three(&a);
	print_stacks(a, b);
}

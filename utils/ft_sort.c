/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:41:43 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/14 17:44:31 by aceauses         ###   ########.fr       */
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

	if (ft_is_sort(*a))
		return ;
	b = NULL;
	loc = find_min(a);
	push_to_b(a, &b, loc);
	if (!ft_is_sort(*a))
	{
		ft_sort_three(a);
		ft_pa(a, &b);
	}
}

void	ft_sort_five(t_node **a)
{
	t_node	*b;

	b = NULL;
	set_min(a, &b);
	if (!ft_is_sort(*a))
	{
		set_min(a, &b);
		ft_sort_three(a);
	}
	while (b)
		ft_pa(a, &b);
}

static int	median(t_node *a)
{
	t_node	*temp;
	int		median;

	temp = a;
	median = 0;
	while (temp != NULL)
	{
		median += temp->index;
		temp = temp->next;
	}
	return (median);
}

static void	push(t_node **a, t_node **b, int median)
{
	int	pushed;
	int	size;
	int	i;

	size = ft_lst_size(*a);
	i = 0;
	pushed = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index < median)
		{
			ft_pb(a, b);
			pushed++;
		}
		else
			ft_ra(a, 1);
		i++;
	}
	while (size - pushed > 4)
	{
		ft_pb(a, b);
		pushed++;
	}
}

void	ft_sort(t_node *a)
{
	t_node	*b;
	int		med;

	b = NULL;
	med = median(a) / ft_lst_size(a);
	printf("[%d]\n", med);
	push(&a, &b, med);
	// while (ft_lst_size(a) != 0)
	// 	ft_pb(&a, &b);
	ft_sort_four(&a);
	// ft_sort_b(&b, &a);
	print_stacks(a, b);
}

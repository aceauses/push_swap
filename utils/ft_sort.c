/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:41:43 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/28 18:06:29 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_stack(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		printf("| %d |->", current->index);
		current = current->next;
	}
	printf(" NULL\n");
}

static void	print_stacks(t_node *stackA, t_node *stackB)
{
	printf("Stack A: ");
	print_stack(stackA);
	printf("Stack B: ");
	print_stack(stackB);
}

void	ft_sort_three(t_node **a)
{
	int		c;
	t_node	*b;

	b = NULL;
	c = (*a)->index;
	if (c > (*a)->next->index)
		ft_sa(a);
	if ((*a)->next->next->index < c)
	{
		ft_pb(a, &b);
		ft_sa(a);
		ft_pa(a, &b);
	}
	c = (*a)->index;
	if (c > (*a)->next->index)
		ft_sa(a);
	if ((*a)->next->index > (*a)->next->next->index)
	{
		ft_pb(a, &b);
		ft_sa(a);
		ft_pa(a, &b);
	}
	print_stacks(*a, b);
}

void	ft_sort(t_node *a)
{
	t_node	*b;

	b = NULL;
	print_stacks(a, b);
}

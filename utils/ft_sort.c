/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:41:43 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/27 15:15:31 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_stack(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d ", current->index);
		current = current->next;
	}
	printf("\n");
}

static void	print_stacks(t_node *stackA, t_node *stackB)
{
	printf("Stack A: ");
	print_stack(stackA);

	printf("Stack B: ");
	print_stack(stackB);
}

void	ft_sort(t_node *a)
{
	t_node	*b;

	if (ft_lst_size(a) == 2 && !ft_is_sort(a))
		ft_sa(&a);
	b = NULL;
	ft_pb(&a, &b);
	print_stacks(a, b);
}

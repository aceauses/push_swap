/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:44:13 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/04 16:44:49 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *stack)
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

void	print_stacks(t_node *stackA, t_node *stackB)
{
	printf("Stack A: ");
	print_stack(stackA);
	printf("Stack B: ");
	print_stack(stackB);
}
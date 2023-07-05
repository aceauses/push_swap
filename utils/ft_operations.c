/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:06:08 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/05 14:57:32 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_node **a, int write)
{
	t_node	*a_back;
	int		i;

	if (*a == NULL && (*a)->next == NULL)
		return ;
	a_back = (*a)->next;
	i = (*a)->index;
	(*a)->index = a_back->index;
	a_back->index = i;
	if (write == 1)
		ft_printf("sa\n");
}

void	ft_sb(t_node **b, int write)
{
	t_node	*b_back;
	int		i;

	if (*b == NULL && (*b)->next == NULL)
		return ;
	b_back = (*b)->next;
	i = (*b)->index;
	(*b)->index = b_back->index;
	b_back->index = i;
	if (write == 1)
		ft_printf("sb\n");
}

void	ft_pb(t_node **a, t_node **b)
{
	t_node	*temp;

	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	ft_printf("pb\n");
}

void	ft_pa(t_node **a, t_node **b)
{
	t_node	*temp;

	temp = *a; /*temp == a*/
	*a = *b; /*Getting node of B to A*/
	*b = (*b)->next; /*Moving B to next node*/
	(*a)->next = temp; /*Tell that a->[second node] == temp so we dont copy the intire node to 	B and just the first one*/
	ft_printf("pa\n");
}

void	ft_ss(t_node	**a, t_node **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	ft_printf("ss\n");
}

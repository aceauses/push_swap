/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:37:24 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/03 13:41:37 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_node **a, int write)
{
	t_node	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = ft_lst_last(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	if (write == 1)
		ft_printf("ra\n");
}

void	ft_rb(t_node **b, int write)
{
	t_node	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = ft_lst_last(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	if (write == 1)
		ft_printf("rb\n");
}

void	ft_rr(t_node **a, t_node **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	ft_printf("rr\n");
}

void	ft_rra(t_node **a, int write)
{
	t_node	*temp;
	int		i;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	i = 0;
	temp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (write == 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_node **b, int write)
{
	t_node	*temp;
	int		i;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	i = 0;
	temp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (write == 1)
		ft_printf("rrb\n");
}

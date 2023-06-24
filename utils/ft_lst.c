/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:06:17 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/22 11:22:59 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lst_last(t_node *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lst_add_back(t_node **lst, t_node *new)
{
	t_node	*nnode;

	if (lst)
	{
		if (*lst)
		{
			nnode = ft_lst_last(*lst);
			nnode->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lst_clear(t_node **lst)
{
	t_node	*nnode;

	if (lst)
	{
		while (*lst)
		{
			nnode = (*lst)->next;
			ft_lst_delone(*lst);
			*lst = nnode;
		}
	}
}

void	ft_lst_delone(t_node *lst)
{
	if (lst)
	{
		free(lst);
	}
}

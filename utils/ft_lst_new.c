/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:35:31 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/20 19:25:58 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lst_new(int content)
{
	t_node	*nnode;

	nnode = (t_node *)malloc(sizeof(t_node));
	if (!nnode)
		ft_error();
	nnode->index = content;
	nnode->next = NULL;
	return (nnode);
}

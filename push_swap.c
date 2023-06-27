/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:38:31 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/27 10:48:31 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node		*a;

	if (argc < 2)
		ft_error();
	a = ft_process(argc, argv);
	if (ft_check_double(a))
	{
		ft_lst_delone(a);
		ft_error();
	}
	// while (a)
	// {
	// 	printf("%d\n", a->index);
	// 	a = a->next;
	// 	if (a->next == NULL)
	// 	{
	// 		printf("%d\n", a->index);
	// 		break ;
	// 	}
	// }
	ft_sort(a);
	// if (!ft_is_sort(a))
	// {
	// 	ft_printf("has to be sorted\n");
	// }
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:38:31 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/04 12:58:58 by aceauses         ###   ########.fr       */
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
		ft_free(&a);
		ft_error();
	}
	if (!ft_is_sort(a))
	{
		if (ft_lst_size(a) == 2)
			ft_sa(&a, 1);
		else if (ft_lst_size(a) == 3)
			ft_sort_three(&a);
		else if (ft_lst_size(a) == 4)
			ft_sort_four(&a);
		else
			ft_sort(a);
	}
	ft_free(&a);
	return (0);
}

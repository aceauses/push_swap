/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:07:08 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/22 10:59:23 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_double(t_node	*a)
{
	t_node	*tmp;

	while (a->next != NULL)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->index == a->index)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

t_node	*ft_quotes(char **argv)
{
	t_node	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], ' ');
	if (!tmp)
		ft_error();
	while (tmp[i])
	{
		j = ft_atoi_new(tmp[i]);
		ft_lst_add_back(&a, ft_lst_new(j));
		i++;
	}
	free(tmp);
	return (a);
}

t_node	*ft_process(int argc, char **argv)
{
	t_node	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc == 2)
		a = ft_quotes(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi_new(argv[i]);
			ft_lst_add_back(&a, ft_lst_new(j));
			i++;
		}
	}
	return (a);
}

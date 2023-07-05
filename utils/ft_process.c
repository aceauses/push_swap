/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:07:08 by aceauses          #+#    #+#             */
/*   Updated: 2023/07/05 16:20:06 by aceauses         ###   ########.fr       */
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

static	void	ft_validation(char **argv, int i)
{
	int	count;

	count = 0;
	if (argv[i][0] == '-')
	{
		count++;
		if (argv[i][count] == '\0')
			ft_error();
	}
	while (argv[i][count] != '\0')
	{
		if (ft_isdigit(argv[i][count]) == 0)
			ft_error();
		count++;
	}
}

t_node	*ft_process(int argc, char **argv)
{
	t_node	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		a = ft_quotes(argv);
	else
	{
		while (i < argc)
		{
			ft_validation(argv, i);
			j = ft_atoi_new(argv[i]);
			ft_lst_add_back(&a, ft_lst_new(j));
			i++;
		}
	}
	return (a);
}

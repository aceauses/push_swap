/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:38:31 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/19 15:35:14 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// t_list	a;
	// t_list	b;
	int		i;
	char	*args;
	char	*join;

	i = 1;
	// // while (i < argc && argc != 1)
	// // 	printf("You typed: [%s]\n", argv[i++]);
	join = ft_calloc(sizeof(argc), 4);
	while (argc > i)
	{
		args = argv[i++];
		printf("ft_split of argv: [%s]\n", args);
		join = ft_strjoin(join, args);
	}
	printf("%s\n", join);
	return (0);
}
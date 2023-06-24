/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:00:47 by aceauses          #+#    #+#             */
/*   Updated: 2023/06/24 15:59:43 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		main(int argc, char **argv);
int		ft_atoi_new(const char *str);
int		ft_check_double(t_node	*a);

void	ft_error(void);
void	ft_lst_add_back(t_node **lst, t_node *new);
void	free_mem(t_node **mem);
void	ft_lst_clear(t_node **lst);
void	ft_lst_delone(t_node *lst);

t_node	*ft_process(int argc, char **argv);
t_node	*ft_lst_new(int content);
t_node	*ft_lst_last(t_node *lst);
t_node	*ft_quotes(char **argv);

#endif
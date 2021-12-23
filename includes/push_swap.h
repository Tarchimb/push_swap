/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:00:10 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 12:22:37 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_group
{
	int		i;
	int		low_v;
	int		high_v;
	int		value;
	int		index;
	int		chunk;
	int		size;
	t_list	*tmp;
}	t_group;

void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_b, t_list **stack_a);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
int		ft_check_sort(t_list **stack_a);
int		ft_sort_to_5(t_list **stack_a, t_list **stack_b);
int		ft_sort_to_3(t_list **stack_a);
int		ft_create_stack(int argc, char **argv, t_list **alst);
int		ft_get_index_position(t_list **stack_a);
void	radix(t_list **stack_a, t_list **stack_b);
void	ft_print_pil(t_list **stack);
int		ft_sort_to_150(t_list **stack_a, t_list **stack_b);
int		ft_checker(int argc, char **argv);
int		ft_check_sort(t_list **stack_a);
int		ft_call_algorithm(t_list **stack_a, t_list **stack_b);
int		ft_check_stack(t_list **stack_a);

#endif

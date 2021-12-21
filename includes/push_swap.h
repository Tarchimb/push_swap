/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:00:10 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 15:26:39 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	ft_ss(t_list **pile_a, t_list **pile_b);
void	ft_sa(t_list **pile_a);
void	ft_sb(t_list **pile_b);
void	ft_pa(t_list **pile_a, t_list **pile_b);
void	ft_pb(t_list **pile_b, t_list **pile_a);
void	ft_ra(t_list **pile_a);
void	ft_rb(t_list **pile_b);
void	ft_rr(t_list **pile_a, t_list **pile_b);
void	ft_rra(t_list **pile_a);
void	ft_rrb(t_list **pile_b);
void	ft_rrr(t_list **pile_a, t_list **pile_b);
int		ft_check_sort(t_list **pile_a);
int		ft_medium_sort(t_list **pile_a, t_list **pile_b);
int		ft_small_sort(t_list **pile_a);
int		ft_create_pile(int argc, char **argv, t_list **alst);
int		ft_get_index_position(t_list **pile_a);
void	ft_big_sort(t_list **pile_a, t_list **pile_b);

#endif

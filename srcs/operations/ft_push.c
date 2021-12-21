/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:03:04 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 15:54:42 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	tmp = NULL;
	if ((*pile_b))
		tmp = (*pile_b);
	else
		return ;
	(*pile_b) = (*pile_b)->next;
	if (*pile_a)
		tmp->next = (*pile_a);
	else
		tmp->next = NULL;
	ft_lstadd_front(pile_a, tmp);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_list **pile_b, t_list **pile_a)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp1 = (*pile_a)->last;
	tmp = (*pile_a);
	(*pile_a) = (*pile_a)->next;
	tmp1->next = (*pile_a);
	ft_lstadd_front(pile_b, tmp);
	ft_putstr_fd("pb\n", 1);
}

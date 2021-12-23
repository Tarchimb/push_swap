/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:02:53 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 15:42:40 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_ra(t_list **pile_a)
{
	t_list	*tmp;

	tmp = (*pile_a);
	(*pile_a) = (*pile_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile_a, tmp);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list **pile_b)
{
	t_list	*tmp;

	if (!(*pile_b)->next)
		return ;
	tmp = (*pile_b);
	(*pile_b) = (*pile_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile_b, tmp);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	tmp = (*pile_a);
	(*pile_a) = (*pile_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile_a, tmp);
	if (!(*pile_b)->next)
		return ;
	tmp = (*pile_b);
	(*pile_b) = (*pile_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile_b, tmp);
	ft_putstr_fd("rrr\n", 1);
}

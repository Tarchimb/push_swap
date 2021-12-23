/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:02:57 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 07:58:06 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rra(t_list **pile_a)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!(*pile_a)->next)
		return ;
	tmp = (*pile_a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp;
	tmp = tmp->next;
	tmp1->next = NULL;
	ft_lstadd_front(pile_a, tmp);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_list **pile_b)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!(*pile_b)->next)
		return ;
	tmp = (*pile_b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp;
	tmp = tmp->next;
	tmp1->next = NULL;
	ft_lstadd_front(pile_b, tmp);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!(*pile_a)->next)
		return ;
	tmp = (*pile_a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp;
	tmp = tmp->next;
	tmp1->next = NULL;
	ft_lstadd_front(pile_a, tmp);
	if (!(*pile_b)->next)
		return ;
	tmp = (*pile_b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp;
	tmp = tmp->next;
	tmp1->next = NULL;
	ft_lstadd_front(pile_b, tmp);
	ft_putstr_fd("rrr\n", 1);
}

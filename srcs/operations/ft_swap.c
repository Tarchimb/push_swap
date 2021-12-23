/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:02:19 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 07:56:45 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_sa(t_list **pile_a)
{
	t_list	*tmp;

	tmp = (*pile_a)->next;
	(*pile_a)->next = (*pile_a)->next->next;
	ft_lstadd_front(pile_a, tmp);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_list **pile_b)
{
	t_list	*tmp;

	tmp = (*pile_b)->next;
	(*pile_b)->next = (*pile_b)->next->next;
	ft_lstadd_front(pile_b, tmp);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	tmp = (*pile_a)->next;
	(*pile_a)->next = (*pile_a)->next->next;
	ft_lstadd_front(pile_a, tmp);
	tmp = (*pile_b)->next;
	(*pile_b)->next = (*pile_b)->next->next;
	ft_lstadd_front(pile_b, tmp);
	ft_putstr_fd("ss\n", 1);
}

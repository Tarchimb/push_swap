/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:02:57 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 11:12:26 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp;
	tmp = tmp->next;
	tmp1->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp;
	tmp = tmp->next;
	tmp1->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp;
	tmp = tmp->next;
	tmp1->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	if (!(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp;
	tmp = tmp->next;
	tmp1->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("rrr\n", 1);
}

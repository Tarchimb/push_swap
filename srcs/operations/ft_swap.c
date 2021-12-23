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

void	ft_sa(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	ft_lstadd_front(stack_a, tmp);
	tmp = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("ss\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:03:04 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 11:12:26 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = NULL;
	if ((*stack_b))
		tmp = (*stack_b);
	else
		return ;
	(*stack_b) = (*stack_b)->next;
	if (*stack_a)
		tmp->next = (*stack_a);
	else
		tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	tmp = NULL;
	if (*stack_a)
		tmp = (*stack_a);
	else
		return ;
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	else
		(*stack_a) = NULL;
	if (*stack_b)
		tmp->next = (*stack_b);
	else
		tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("pb\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:08:14 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 12:25:13 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_check_b(t_list **stack_b, t_group i)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_b) == 0 || ft_lstsize(*stack_b) == 1)
		return ;
	tmp = *stack_b;
	if (tmp->index > (i.low_v + (i.size / 2)))
		ft_rb(stack_b);
}

void	ft_push_to_b(t_list **stack_a, t_list **stack_b, t_group i)
{
	i.tmp = *stack_a;
	if (i.low_v + i.size - 1 < ft_lstsize(*stack_a))
		i.high_v = i.low_v + i.size - 1;
	else
		i.high_v = ft_lstsize(*stack_a) + i.low_v;
	while (i.tmp && i.chunk <= (i.high_v - i.low_v))
	{
		while ((i.tmp->index < i.low_v) || (i.tmp->index > i.high_v))
		{
			i.i++;
			i.tmp = i.tmp->next;
		}
		i.value = i.tmp->index;
		if (i.i > (ft_lstsize(*stack_a) / 2))
			while ((*stack_a)->index != i.value)
				ft_rra(stack_a);
		while ((*stack_a)->index != i.value)
			ft_ra(stack_a);
		ft_check_b(stack_b, i);
		ft_pb(stack_b, stack_a);
		i.tmp = *stack_a;
		i.chunk++;
		i.i = 0;
	}
}

void	ft_push_to_a(t_list **stack_a, t_list **stack_b, t_group i)
{
	i.index = ft_lstsize(*stack_b) - 1;
	i.tmp = *stack_b;
	while (*stack_b)
	{
		while (i.tmp->index != i.index)
		{
			i.i++;
			i.tmp = i.tmp->next;
		}
		if (i.i > (ft_lstsize(*stack_b) / 2))
			while ((*stack_b)->index != i.index)
				ft_rrb(stack_b);
		else
			while ((*stack_b)->index != i.index)
				ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
		i.tmp = *stack_b;
		i.index--;
		i.i = 0;
	}
}

int	ft_sort_to_150(t_list **stack_a, t_list **stack_b)
{
	t_group	i;

	i.i = 0;
	i.low_v = 0;
	i.high_v = 0;
	i.value = 0;
	i.index = 0;
	i.chunk = 0;
	i.size = ft_lstsize(*stack_a) / 5;
	while (*stack_a)
	{
		ft_push_to_b(stack_a, stack_b, i);
		i.low_v += i.size;
	}
	while (*stack_b)
		ft_push_to_a(stack_a, stack_b, i);
	return (0);
}

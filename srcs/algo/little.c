/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:00:58 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 12:03:26 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_sort_to_3(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 2 && ft_check_sort(stack_a) != 0)
	{
		ft_sa(stack_a);
		return (0);
	}
	while (ft_check_sort(stack_a) != 0)
	{
		if (ft_lstsize(*stack_a) > 2)
			if ((*stack_a)->next->index > (*stack_a)->next->next->index)
				ft_rra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			ft_sa(stack_a);
	}
	return (0);
}

static int	ft_get_low_index(t_list **stack, int *low_index,
	t_list *tmp, int *i)
{
	tmp = *stack;
	*low_index = tmp->index;
	while (tmp)
	{
		if (*low_index > tmp->index)
		{
			*low_index = tmp->index;
			tmp = (*stack);
		}
		tmp = tmp->next;
	}
	tmp = (*stack);
	while (tmp->index != *low_index)
	{
		*i += 1;
		tmp = tmp->next;
	}
	return (*i);
}

static int	ft_get_high_index(t_list **stack, int *high_index,
	t_list *tmp, int i)
{
	tmp = *stack;
	*high_index = tmp->index;
	while (tmp)
	{
		if (*high_index < tmp->index)
		{
			*high_index = tmp->index;
			tmp = (*stack);
		}
		tmp = tmp->next;
	}
	tmp = (*stack);
	while (tmp->index != *high_index)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > 1)
		while ((*stack)->index != *high_index)
			ft_rra(stack);
	else
		while ((*stack)->index != *high_index)
			ft_ra(stack);
	return (i);
}

int	ft_sort_to_5(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		low_index;
	int		high_index;
	t_list	*tmp;

	tmp = (*stack_a);
	i = 0;
	ft_get_low_index(stack_a, &low_index, tmp, &i);
	if (i > 2)
		while ((*stack_a)->index != low_index)
			ft_rra(stack_a);
	else
		while ((*stack_a)->index != low_index)
			ft_ra(stack_a);
	ft_pb(stack_b, stack_a);
	tmp = (*stack_a);
	i = 0;
	ft_get_high_index(stack_a, &high_index, tmp, i);
	ft_pb(stack_b, stack_a);
	ft_sort_to_3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	return (0);
}

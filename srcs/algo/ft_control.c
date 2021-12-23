/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:57:51 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 12:04:10 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_check_sort(t_list **stack_a)
{
	int		i;
	t_list	*tmp;

	if (!*stack_a)
		return (1);
	i = 0;
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

int	ft_call_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_b);
	size = ft_lstsize(*stack_a);
	if (ft_check_sort(stack_a) == 0)
		return (0);
	if (size <= 3)
		ft_sort_to_3(stack_a);
	else if (size <= 5)
		ft_sort_to_5(stack_a, stack_b);
	else if (size <= 150)
		ft_sort_to_150(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
	return (0);
}

int	ft_check_stack(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		j;

	tmp = *stack_a;
	tmp1 = (*stack_a)->next;
	j = 0;
	while (tmp->next)
	{
		while (tmp1)
		{
			if (tmp->content == tmp1->content)
				j++;
			if (j > 0)
				return (0);
			tmp1 = tmp1->next;
		}
		j = 0;
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
	return (1);
}
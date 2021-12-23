/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:23:30 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 12:01:12 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	radix(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;
	int	size_tmp;
	int	count;

	size = ft_lstsize(*stack_a);
	i = 0;
	size_tmp = size;
	count = 0;
	while (ft_check_sort(stack_a) != 0)
	{
		while (size--)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_b, stack_a);
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		size = size_tmp;
		i++;
	}
}

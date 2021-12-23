/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:23:30 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 15:46:42 by tarchimb         ###   ########.fr       */
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


int	ft_small_sort(t_list **pile_a)
{
	if (ft_lstsize(*pile_a) == 2 && ft_check_sort(pile_a) != 0)
	{
		ft_sa(pile_a);
		return (0);
	}
	while (ft_check_sort(pile_a) != 0)
	{
		if (ft_lstsize(*pile_a) > 2)
			if ((*pile_a)->next->content > (*pile_a)->next->next->content)
				ft_rra(pile_a);
		if ((*pile_a)->content > (*pile_a)->next->content)
			ft_sa(pile_a);
	}
	return (0);
}

static int	ft_get_low_value(t_list **pile, size_t *low_value,
	t_list *tmp, int i)
{
	*low_value = (size_t)tmp->content;
	while (tmp)
	{
		if (*low_value > (size_t)tmp->content)
		{
			*low_value = (size_t)tmp->content;
			tmp = (*pile);
		}
		tmp = tmp->next;
	}
	tmp = (*pile);
	while (*low_value != (size_t)tmp->content && tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > 2)
		while (i++ < 5)
			ft_rra(pile);
	else
		while (i--)
			ft_ra(pile);
	return (i);
}

static int	ft_get_high_value(t_list **pile, size_t *high_value,
	t_list *tmp, int i)
{
	*high_value = (size_t)tmp->content;
	while (tmp)
	{
		if (*high_value < (size_t)tmp->content)
		{
			*high_value = (size_t)tmp->content;
			tmp = (*pile);
		}
		tmp = tmp->next;
	}
	tmp = (*pile);
	while (*high_value != (size_t)tmp->content && tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > 1)
		while (i++ < 4)
			ft_rra(pile);
	else
		while (i--)
			ft_ra(pile);
	return (i);
}

int	ft_medium_sort(t_list **pile_a, t_list **pile_b)
{
	int		i;
	size_t	low_value;
	size_t	high_value;
	t_list	*tmp;

	tmp = (*pile_a);
	i = 0;
	ft_get_low_value(pile_a, &low_value, tmp, i);
	ft_pb(pile_b, pile_a);
	tmp = (*pile_a);
	ft_get_high_value(pile_a, &high_value, tmp, i);
	ft_pb(pile_b, pile_a);
	ft_small_sort(pile_a);
	ft_pa(pile_a, pile_b);
	ft_ra(pile_a);
	ft_pa(pile_a, pile_b);
	return (0);
}

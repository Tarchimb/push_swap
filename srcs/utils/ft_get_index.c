/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:12:12 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 11:04:09 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t	get_lowest_value(t_list **pile_a)
{
	size_t	value;
	t_list	*tmp;

	tmp = *pile_a;
	value = (size_t)tmp->content;
	while (tmp)
	{
		if ((size_t)tmp->content < value)
			value = (size_t)tmp->content;
		tmp = tmp->next;
	}
	return (value);
}

size_t	get_next_lowest_value(t_list **pile_a, size_t lowest_value)
{
	size_t	value;
	t_list	*tmp;

	tmp = *pile_a;
	value = 2147483649;
	while (tmp)
	{
		if ((size_t)tmp->content <= value
			&& (size_t)tmp->content > lowest_value)
			value = (size_t)tmp->content;
		tmp = tmp->next;
	}
	return (value);
}

int	ft_get_index_position(t_list **pile_a)
{
	int		i;
	size_t	value;
	size_t	lowest_value;
	t_list	*tmp;
	t_list	*tmp1;

	i = 1;
	tmp = *pile_a;
	tmp1 = *pile_a;
	value = get_lowest_value(pile_a);
	while (tmp)
	{
		while (tmp1)
		{
			if ((size_t)tmp1->content > value)
				tmp1->index = i;
			tmp1 = tmp1->next;
		}
		i++;
		tmp = tmp->next;
		tmp1 = *pile_a;
		lowest_value = value;
		value = get_next_lowest_value(pile_a, lowest_value);
	}
	return (0);
}

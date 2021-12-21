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

#include "../../includes/push_swap.h"

void	ft_big_sort(t_list **pile_a, t_list **pile_b)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = *pile_a;
	while (*pile_a)
	{
		if ((((*pile_a)->index >> i) & 1) == 0)
		{
			ft_pb(pile_b, pile_a);
		}
		else
		{
			ft_ra(pile_a);
		}
	}
	*pile_a = tmp;
}

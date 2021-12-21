/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 08:55:09 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 07:53:02 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_print_pil(t_list **pile)
{
	while (*pile)
	{
		// printf("%zd\n", (size_t)(*pile)->content);
		printf("%d\n", (*pile)->index);
		*pile = (*pile)->next;
	}
}

int	ft_check_sort(t_list **pile_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *pile_a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

int	ft_call_algorithm(t_list **pile_a, t_list **pile_b)
{
	int	size;

	size = ft_lstsize(*pile_a);
	(void)pile_b;
	if (ft_check_sort(pile_a) == 0)
		return (0);
	if (size <= 3)
	{
		ft_small_sort(pile_a);
		return (0);
	}
	else if (size <= 5)
		ft_medium_sort(pile_a, pile_b);

	else if (size <= 100)
		ft_big_sort(pile_a, pile_b);
	// else
	//	 ft_huge_sort(pile_a, pile_b);
	return (0);
}

int	ft_check_pile(t_list **pile_a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		j;

	tmp = *pile_a;
	tmp1 = (*pile_a)->next;
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

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	int	d;

	d = 8;
	// printf("%d\n", 12&23);

	if (argc < 2)
		return (0);
	pile_a = NULL;
	pile_b = NULL;
	ft_create_pile(argc, argv, &pile_a);
	if (!ft_check_pile(&pile_a))
	{
		ft_putstr_fd("Error", 2);
		return (ft_lstclear(&pile_a, free));
	}
	ft_get_index_position(&pile_a);
	ft_call_algorithm(&pile_a, &pile_b);
	printf("==PILE A==\n\n");
	ft_print_pil(&pile_a);
	printf("==PILE B==\n\n");
	ft_print_pil(&pile_b);
	return (0);
}

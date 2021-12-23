/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   ft_create_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:59:44 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 15:34:34 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_fill_stack(t_list **stack_a, char **argv, int i, int j)
{
	t_list	*dest;

	dest = NULL;
	while (argv[++i])
	{
		dest = ft_lstnew(ft_atoi(argv[j++], stack_a));
		dest->index = 0;
		if (!dest)
			return (ft_lstclear(stack_a, free));
		ft_lstadd_back(stack_a, dest);
	}
	return (1);
}

int	ft_create_pile(int argc, char **argv, t_list **stack_a)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = 1;
	count = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		j = 0;
		count++;
	}
	else
		i = 0;
	if (!ft_fill_stack(stack_a, argv, i, j))
	{
		if (count)
			ft_free_all((void **)argv);
		return (0);
	}
	if (count)
		ft_free_all((void **)argv);
	return (1);
}

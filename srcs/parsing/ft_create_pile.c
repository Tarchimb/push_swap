/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:59:44 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 15:34:34 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_create_pile(int argc, char **argv, t_list **alst)
{
	int		i;
	int		j;
	t_list	*dest;
	t_list	*tmp;

	i = -1;
	j = 1;
	dest = NULL;
	tmp = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		j = 0;
	}
	else
		i = 0;
	while (argv[++i])
	{
		dest = ft_lstnew((void *)(size_t)ft_atoi(argv[j++], alst));
		dest->index = 0;
		dest->last = tmp;
		tmp = dest;
		if (!dest)
			return (ft_lstclear(alst, free));
		ft_lstadd_back(alst, dest);
	}
	return (1);
}

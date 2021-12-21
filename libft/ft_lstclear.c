/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:47:27 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 11:05:26 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	(void)del;
	if (!lst)
		return (0);
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		(*lst) = next;
	}
	return (0);
}

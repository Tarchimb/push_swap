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

#include <push_swap.h>

int    get_index(t_list *lst, int value)
{
    int        i;

    i = 0;
    while (lst)
    {
        if (lst->content < value && lst->content != value)
            i++;
        lst = lst->next;
    }
    return (i);
}

int	ft_get_index_position(t_list **stack_a)
{
    t_list    *head;

    head = *stack_a;
    while (head)
    {
        head->index = get_index(*stack_a, head->content);
        head = head->next;
    }
	return (0);
}

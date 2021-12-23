/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:25:40 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 08:02:19 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return;
	if (*alst)
		new->next = *alst;
	else
		new->next = NULL;
	*alst = new;
}

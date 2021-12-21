/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:36:40 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/21 08:28:29 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_c(char c, t_list **pile_a)
{
	if (c < '0' || c > '9')
	{
		ft_putstr_fd("Error", 2);
		ft_lstclear(pile_a, free);
		exit(0);
	}
}

int	ft_atoi(char *str, t_list **pile_a)
{
	int	negative;
	int	r;
	int	i;

	i = 0;
	negative = 0;
	r = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	ft_check_c(str[i], pile_a);
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (r * -1);
	return (r);
}

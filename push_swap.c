/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:54:41 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 12:14:02 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_create_stack(argc, argv, &stack_a) == 0)
		return (0);
	if (!ft_check_stack(&stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_lstclear(&stack_a, free));
	}
	ft_get_index_position(&stack_a);
	ft_call_algorithm(&stack_a, &stack_b);
	// if (ft_check_sort(&stack_a) == 0)
	// 	printf("\nOK");
	ft_lstclear(&stack_a, free);
	return (0);
}

void	ft_print_pil(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("content-->%d,index-->%d \n",
			tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

#include <push_swap.h>

void	ft_check_b(t_list **stack_b, int value)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_b) == 0 || ft_lstsize(*stack_b) == 1)
		return ;
	tmp = *stack_b;
	if (tmp->index > (value + 10))
		ft_rb(stack_b);
}

void	ft_push_to_b(t_list **stack_a, t_list **stack_b, int low_value, int chunk)
{
	int		i;
	int		high_value;
	t_list	*tmp;
	int		value;

	tmp = *stack_a;
	i = 0;
	if (low_value + 19 < ft_lstsize(*stack_a))
		high_value = low_value + 19;
	else
		high_value = ft_lstsize(*stack_a) + low_value;
	while (tmp)
	{
		while(((tmp->index < low_value) || (tmp->index > high_value) ) && tmp)
		{
			i++;
			tmp=tmp->next;
		}
		value = tmp->index;
		if (i > (ft_lstsize(*stack_a) / 2))
			while ((*stack_a)->index != value)
				ft_rra(stack_a);
		while ((*stack_a)->index != value)
			ft_ra(stack_a);
		ft_check_b(stack_b, low_value);
		ft_pb(stack_b, stack_a);
		tmp = *stack_a;
		if (chunk == (high_value - low_value) || !tmp)
			return ;
		chunk++;
		i = 0;
	}
}

void	ft_push_to_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		index;
	t_list	*tmp;

	index = ft_lstsize(*stack_b) - 1;
	tmp = *stack_b;
	i = 0;
	while (*stack_b)
	{
		while (tmp->index != index)
		{
			i++;
			tmp = tmp->next;
		}
		if (i > (ft_lstsize(*stack_b) / 2))
			while ((*stack_b)->index != index)
				ft_rrb(stack_b);
		else
			while ((*stack_b)->index != index)
				ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
		tmp = *stack_b;
		index--;
		i = 0;
	}
}
int	ft_medium_algo(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		low_value;
	int		chunk;
	t_list	*tmp;

	i = 0;
	chunk = 0;
	low_value = 0;
	tmp = *stack_a;
	while (*stack_a)
	{
		ft_push_to_b(stack_a, stack_b, low_value, 0);
		low_value += 20;
	}
	while (*stack_b)
		ft_push_to_a(stack_a, stack_b);
	return (0);
}

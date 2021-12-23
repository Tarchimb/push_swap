#include <push_swap.h>

// int	ft_error(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return (ft_putstr_fd("not enough argument", 2));
// 	if ()
// }

// int	ft_check_args(int argc, char **argv)
// {
// 	int		i;
// 	char	**tmp;

// 	i = 0;

// }

void	ft_order_stack(t_list **stack_a, t_list **stack_b)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, "sa", 3) == 0)
			ft_sa(stack_a);
		else if (ft_strncmp(line, "sb", 3) == 0)
			ft_sb(stack_b);
		else if (ft_strncmp(line, "ss", 3) == 0)
			ft_ss(stack_a, stack_b);
		else if (ft_strncmp(line, "pa", 3) == 0)
			ft_pa(stack_a, stack_b);
		else if (ft_strncmp(line, "pb", 3) == 0)
			ft_pb(stack_b, stack_a);
		else if (ft_strncmp(line, "ra", 3) == 0)
			ft_ra(stack_a);
		else if (ft_strncmp(line, "rb", 3) == 0)
			ft_rb(stack_b);
		else if (ft_strncmp(line, "rr", 3) == 0)
			ft_rr(stack_a, stack_b);
		else if (ft_strncmp(line, "rra", 4) == 0)
			ft_rra(stack_a);
		else if (ft_strncmp(line, "rrb", 4) == 0)
			ft_rrb(stack_b);
		else if (ft_strncmp(line, "rrr", 4) == 0)
			ft_rrr(stack_a, stack_b);
		else
			return ;
		free(line);
		line = get_next_line(0);
		line = NULL;
	}
}

int	ft_checker(int	argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	// if (!ft_check_args(argc, argc))
	// 	return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!ft_create_pile(argc, argv, &stack_a))
		return (0);
	ft_order_stack(&stack_a, &stack_b);
	if (ft_check_sort(&stack_a) == 0)
	{
		ft_lstclear(&stack_a, free);
		if (stack_b)
			ft_lstclear(&stack_b, free);
		return (ft_putstr_fd("OK", 1));
	}
	else
	{
		ft_lstclear(&stack_a, free);
		if (stack_b)
			ft_lstclear(&stack_b, free);
		return (ft_putstr_fd("KO", 1));
	}
}

int	main(int argc, char **argv)
{
	ft_checker(argc, argv);
}

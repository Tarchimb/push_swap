#include "includes/push_swap.h"

int	ft_check_sort(t_list **pile_a)
{
	int		i;
	t_list	*tmp;

	if (!*pile_a)
		return (1);
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

	size = ft_lstsize(*pile_b);
	size = ft_lstsize(*pile_a);
	if (ft_check_sort(pile_a) == 0)
		return (0);
	if (size <= 3)
		ft_small_sort(pile_a);
	else if (size <= 5)
		ft_medium_sort(pile_a, pile_b);
	else if (size <= 150)
		ft_medium_algo(pile_a, pile_b);
	else
	 	radix(pile_a, pile_b);
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

	if (argc < 2)
		return (0);
	pile_a = NULL;
	pile_b = NULL;
	if (ft_create_pile(argc, argv, &pile_a) == 0)
		return (0);
	if (!ft_check_pile(&pile_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_lstclear(&pile_a, free));
	}
	ft_get_index_position(&pile_a);
	ft_call_algorithm(&pile_a, &pile_b);
	//ft_print_pil(&pile_a);
	ft_lstclear(&pile_a, free);
	ft_print_pil(&pile_a);
	return (0);
}

void	ft_print_pil(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	while (tmp)
	{
		printf("content-->%d,index-->%d \n",
			tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

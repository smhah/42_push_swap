/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:21:17 by smhah             #+#    #+#             */
/*   Updated: 2021/11/10 13:06:09 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five_case(int size, char ***stack_index)
{
	char	**stack_b;
	int		i;

	i = 0;
	stack_b = m_malloc((sizeof(char *) * size) + 1, 0);
	empty_b(&stack_b, size);
	search_zero_one_push(size, stack_index, &stack_b);
	ft_sort_three_case(size, stack_index);
	ft_putstr("pa\npa\n");
	push_a(stack_index, &stack_b, size);
	push_a(stack_index, &stack_b, size);
}

void	continue_in_new_functions(char ***stack_sorted,
	char **stack_origine, int size)
{
	char	**stack_index;
	int		i;

	i = 0;
	stack_index = m_malloc((sizeof(char *) * size) + 1, 0);
	compare_sort_nb_stacks(stack_sorted, stack_origine, &stack_index, size);
	if (size == 4)
		ft_sort_three_case(size, &stack_index);
	else if (size == 6)
		ft_sort_five_case(size, &stack_index);
	else
		ft_sort(size, &stack_index);
}

int	check_errors(char **tab)
{
	int	i;

	i = 0;
	if (!check_double_number(tab))
		return (0);
	if (!check_is_digit(tab))
		return (0);
	if (is_sorted(tab))
		return (0);
	if (!check_max_min_int(tab))
		return (0);
	return (1);
}

int	allocate_stack_and_fill(int size, int ac, char **av)
{
	char	**stack_sorted;
	int		i;
	int		j;
	char	**stack_origine;

	if (ac > 1)
	{
		i = 0;
		j = 1;
		stack_sorted = m_malloc((sizeof(char *) * size) + 1, 0);
		while (j < ac)
		{
			stack_sorted[i] = ft_strdup(av[j]);
			i++;
			j++;
		}
		stack_sorted[i] = NULL;
		if (!check_errors(stack_sorted))
			return (0);
		copy_stack_origine(&stack_sorted, &stack_origine, size);
		sorting_data(&stack_sorted, size);
		continue_in_new_functions(&stack_sorted, stack_origine, size);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;

	(void)ac;
	i = 0;
	while (av[i])
		i++;
	if (!allocate_stack_and_fill(i, ac, av))
		return (0);
	return (1);
}

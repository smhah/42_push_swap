/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:00:49 by macbook           #+#    #+#             */
/*   Updated: 2021/11/12 18:29:24 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	compare_sort_nb_stacks(char ***stack_sorted, char **stack_origine,
		char ***stack_index, int size)
{
	int	k;
	int	i;
	int	j;

	j = 0;
	k = 0;
	while (k < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmpr(stack_origine[k], (*stack_sorted)[i]))
			{
				(*stack_index)[j++] = ft_strdup_1(ft_itoa(i));
			}
			i++;
		}
		k++;
	}
	(*stack_index)[j] = NULL;
}

void	read_operations(char ***operations)
{
	int	i;

	i = 0;
	while (get_next_line(0, &(*operations)[i]))
	{
		i++;
	}
	get_next_line(0, &(*operations)[i]);
	(*operations)[++i] = NULL;
}

void	copy_stack_origine(char ***stack_sorted,
		char ***stack_origine, int size)
{
	int		i;

	(void)size;
	*stack_origine = m_malloc((sizeof(char *) * size) + 1, 0);
	i = 0;
	while ((*stack_sorted)[i])
	{
		(*stack_origine)[i] = ft_strdup((*stack_sorted)[i]);
		i++;
	}
	(*stack_origine)[i] = NULL;
}

void	sorting_data(char ***stack_sorted, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (ft_atoi((*stack_sorted)[i]) > ft_atoi((*stack_sorted)[j]))
				swap_nb(&(*stack_sorted)[j], &(*stack_sorted)[i]);
			j++;
		}
		i++;
	}
	i = 0;
}

int	create_index_of_args(char **av, int size, char ***stack_index)
{
	char	**stack_sorted;
	int		i;
	int		j;
	char	**stack_origine;

	if (size > 1)
	{
		i = 0;
		j = 1;
		stack_sorted = m_malloc((sizeof(char *) * size) + 1, 0);
		while (j < size)
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
		*stack_index = m_malloc((sizeof(char *) * size) + 1, 0);
		compare_sort_nb_stacks(&stack_sorted, stack_origine, stack_index, size);
	}
	return (1);
}

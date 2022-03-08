/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:19:32 by macbook           #+#    #+#             */
/*   Updated: 2021/11/12 18:29:12 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

int	execute_operations_check_stacks(char ***stack_a,
		int size, char **operations)
{
	char	**stack_b;

	stack_b = m_malloc((sizeof(char *) * size) + 1, 0);
	empty_b(&stack_b, size);
	if (!wich_operations(stack_a, &stack_b, operations, size))
		return (0);
	check_stacks(*stack_a, stack_b);
	return (1);
}

int	check_errors(char **tab)
{
	int	i;

	i = 0;
	if (!check_double_number(tab))
		return (0);
	if (!check_is_digit(tab))
		return (0);
	if (!check_max_min_int(tab))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char	**operations;
	char	**stack_index;
	int		i;

	if (ac > 1)
	{
		stack_index = m_malloc((sizeof(char *) * ac) + 1, 0);
		i = 0;
		operations = malloc((sizeof(char *) * (100001)));
		if (!create_index_of_args(av, ac, &stack_index))
			return (0);
		read_operations(&operations);
		if (!(execute_operations_check_stacks(&stack_index, ac, operations)))
			return (0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:51:47 by macbook           #+#    #+#             */
/*   Updated: 2021/11/12 18:19:49 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

int	put_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int	compare_execute_operations(char *op, char ***stack_a,
	char ***stack_b, int size)
{
	if (ft_strcmpr(op, "pa"))
		push_a(stack_a, stack_b, size);
	else if (ft_strcmpr(op, "pb"))
		push_b(stack_a, stack_b, size);
	else if (ft_strcmpr(op, "sa"))
		swap_a(stack_a);
	else if (ft_strcmpr(op, "sb"))
		swap_b(stack_b);
	else if (ft_strcmpr(op, "ss"))
		swap_a_b(stack_a, stack_b);
	else if (ft_strcmpr(op, "ra"))
		rotaate_a(stack_a, size);
	else if (ft_strcmpr(op, "rb"))
		rotaate_a(stack_b, size);
	else if (ft_strcmpr(op, "rr"))
		rotaate_a_b(stack_a, stack_b, size);
	else if (ft_strcmpr(op, "rra"))
		rotate_reeverse_a(stack_a, size);
	else if (ft_strcmpr(op, "rrb"))
		rotate_reeverse_a(stack_b, size);
	else if (ft_strcmpr(op, "rrr"))
		rotaate_reverse_a_b(stack_a, stack_b, size);
	else if (!ft_strcmpr(op, ""))
		return (put_error());
	return (1);
}

int	wich_operations(char ***stack_a, char ***stack_b,
	char **operations, int size)
{
	int	i;

	i = 0;
	while (operations[i])
	{
		if (!compare_execute_operations(operations[i], stack_a, stack_b, size))
			return (0);
		i++;
	}
	return (1);
}

int	if_empty(char **str)
{
	int	i;

	i = 0;
	if (str[0])
		return (0);
	else
		return (1);
	return (1);
}

void	check_stacks(char **stack_a, char **stack_b)
{
	int	i;

	i = 0;
	if (is_sorted(stack_a) && if_empty(stack_b))
	{
		ft_putstr("OK\n");
	}
	else
		ft_putstr("KO\n");
}

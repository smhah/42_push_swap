/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:21:02 by smhah             #+#    #+#             */
/*   Updated: 2021/11/09 13:30:48 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int size, char ***stack_index)
{
	int		c;
	int		bits;
	int		i;
	char	**stack_b;

	stack_b = m_malloc((sizeof(char *) * size) + 1, 0);
	empty_b(&stack_b, size);
	c = size - 1;
	bits = ft_calcule_bits(c);
	i = 0;
	while (i < bits)
	{
		ft_sort_binary(stack_index, size, i, &stack_b);
		while (stack_b[0])
		{
			push_a(stack_index, &stack_b, size);
			ft_putstr("pa\n");
		}
		i++;
	}
}

void	ft_sort_three_case(int size, char ***stack_index)
{
	int	a;
	int	b;
	int	c;

	a = ft_atoi((*stack_index)[0]);
	b = ft_atoi((*stack_index)[1]);
	c = ft_atoi((*stack_index)[2]);
	if (b < a && a < c && b < c)
		case_one(stack_index);
	else if (a > b && a > c && b > c)
		case_two(stack_index, size);
	else if (a > b && a > c && b < c)
		case_three(stack_index, size);
	else if (a < b && a < c && b > c)
		case_four(stack_index, size);
	else if (a < b && a > c && b > c)
	{
		rotate_reeverse_a(stack_index, size);
		ft_putstr("rra\n");
	}
}

void	search_zero_push(int size, char ***stack_index, char ***stack_b)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while ((*stack_index)[i])
	{
		if (ft_atoi((*stack_index)[i]) == 0)
		{
			c = i;
			while (c--)
			{
				ft_putstr("ra\n");
				rotaate_a(stack_index, size);
			}
			ft_putstr("pb\n");
			push_b(stack_index, stack_b, size);
		}
		i++;
	}
}

void	search_one_push(int size, char ***stack_index, char ***stack_b)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while ((*stack_index)[i])
	{
		if (ft_atoi((*stack_index)[i]) == 1)
		{
			c = i;
			while (c--)
			{
				ft_putstr("ra\n");
				rotaate_a(stack_index, size);
			}
			ft_putstr("pb\n");
			push_b(stack_index, stack_b, size);
		}
		i++;
	}
}

void	search_zero_one_push(int size, char ***stack_index, char ***stack_b)
{
	search_zero_push(size, stack_index, stack_b);
	search_one_push(size, stack_index, stack_b);
}

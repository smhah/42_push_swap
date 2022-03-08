/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:21:05 by smhah             #+#    #+#             */
/*   Updated: 2021/11/08 15:45:49 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	case_one(char ***stack_index)
{
	swap_a(stack_index);
	ft_putstr("sa\n");
}

void	case_two(char ***stack_index, int size)
{
	swap_a(stack_index);
	rotate_reeverse_a(stack_index, size);
	ft_putstr("sa\nrra\n");
}

void	case_three(char ***stack_index, int size)
{
	rotaate_a(stack_index, size);
	ft_putstr("ra\n");
}

void	case_four(char ***stack_index, int size)
{
	swap_a(stack_index);
	rotaate_a(stack_index, size);
	ft_putstr("sa\nra\n");
}

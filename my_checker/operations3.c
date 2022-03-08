/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:41:46 by macbook           #+#    #+#             */
/*   Updated: 2021/11/12 18:20:31 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	swap_a_b(char ***stack_a, char ***stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rotaate_a_b(char ***stack_a, char ***stack_b, int size)
{
	rotaate_a(stack_a, size);
	rotaate_a(stack_b, size);
}

void	rotaate_reverse_a_b(char ***stack_a, char ***stack_b, int size)
{
	rotate_reeverse_a(stack_a, size);
	rotate_reeverse_a(stack_b, size);
}

void	empty_b(char ***stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*stack_b)[i] = NULL;
		i++;
	}
}

int	is_sorted(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		if (!tab[j])
			return (1);
		if (tab[i] && tab[j] && (ft_atoi(tab[i]) < ft_atoi(tab[j])))
			i++;
		else
			return (0);
	}
	return (1);
}

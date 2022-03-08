/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:20:59 by smhah             #+#    #+#             */
/*   Updated: 2021/11/08 15:21:00 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

int	ft_calcule_bits(int c)
{
	int	i;

	i = 0;
	while (c)
	{
		c = c >> 1;
		i++;
	}
	return (i);
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

char	*top_value(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i > 0)
		return (tab[i - 1]);
	return (NULL);
}

void	ft_sort_binary(char ***stack_index, int size, int i, char ***stack_b)
{
	int	j;

	j = size - 1;
	while (j--)
	{
		if (ft_atoi((*stack_index)[0]) >> i & 1)
		{
			rotaate_a(stack_index, size);
			ft_putstr("ra\n");
		}
		else
		{
			push_b(stack_index, stack_b, size);
			ft_putstr("pb\n");
		}
	}
}

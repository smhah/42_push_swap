/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:20:56 by smhah             #+#    #+#             */
/*   Updated: 2021/11/08 15:20:57 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_free(int count)
{
	int	i;

	i = -1;
	while (++i < count + 1)
		free(g_pointer[i]);
}

void	*m_malloc(size_t n, int indicator)
{
	void		*tmp;
	static int	count = 0;

	if (indicator == 1)
	{
		to_free(count);
		return (NULL);
	}
	tmp = malloc(n);
	if (!tmp)
		return (NULL);
	g_pointer[count] = tmp;
	count++;
	return (tmp);
}

void	swap_nb(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
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

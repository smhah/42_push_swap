/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:21:35 by smhah             #+#    #+#             */
/*   Updated: 2021/11/09 13:46:49 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_norme(char ***stack_index, char **tab_tmp,
		char ***stack_b, int size)
{
	int		i;
	char	*temp;
	int		j;

	j = 0;
	i = 0;
	temp = (*stack_b)[j];
	(*stack_b)[j++] = ft_strdup_1((*stack_index)[0]);
	free(temp);
	new_delete_top_value(stack_index, size);
	while (tab_tmp[i])
	{
		temp = (*stack_b)[j];
		(*stack_b)[j++] = ft_strdup_1(tab_tmp[i]);
		free(temp);
		i++;
	}
	temp = (*stack_b)[j];
	(*stack_b)[j] = NULL;
	free(temp);
}

void	push_b(char ***stack_index, char ***stack_b, int size)
{
	int			i;
	char		**tab_tmp;

	i = 0;
	tab_tmp = malloc(sizeof(char *) * (size + 1));
	while ((*stack_b)[i])
	{
		tab_tmp[i] = ft_strdup_1((*stack_b)[i]);
		i++;
	}
	tab_tmp[i] = NULL;
	push_b_norme(stack_index, tab_tmp, stack_b, size);
	i = 0;
	while (tab_tmp[i])
		free(tab_tmp[i++]);
	free(tab_tmp);
}

void	push_a_norme(char ***stack_index,
		char ***stack_b, int size, char **tab_tmp)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if ((*stack_b)[0])
	{
		temp = (*stack_index)[j];
		(*stack_index)[j++] = ft_strdup_1((*stack_b)[0]);
		free(temp);
		new_delete_top_value(stack_b, size);
	}
	while (tab_tmp[i])
	{
		temp = (*stack_index)[j];
		(*stack_index)[j++] = ft_strdup_1(tab_tmp[i]);
		free(temp);
		i++;
	}
	(*stack_index)[j] = NULL;
}

void	push_a(char ***stack_index, char ***stack_b, int size)
{
	int		i;
	char	**tab_tmp;

	i = 0;
	tab_tmp = malloc(sizeof(char *) * (size + 1));
	while ((*stack_index)[i])
	{
		tab_tmp[i] = ft_strdup_1((*stack_index)[i]);
		i++;
	}
	tab_tmp[i] = NULL;
	push_a_norme(stack_index, stack_b, size, tab_tmp);
	i = 0;
	while (tab_tmp[i])
		free(tab_tmp[i++]);
	free(tab_tmp);
}

void	swap_a(char ***stack_index)
{
	int	i;

	i = 0;
	if ((*stack_index)[0] && (*stack_index)[1])
		swap_nb(&(*stack_index)[0], &(*stack_index)[1]);
}

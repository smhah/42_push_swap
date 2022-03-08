/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:26:08 by macbook           #+#    #+#             */
/*   Updated: 2021/11/12 18:06:02 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	rotaate_a_norme(char ***stack_index, char **tab_tmp)
{
	int		i;
	char	*temp;
	int		j;

	j = 0;
	i = 0;
	while (tab_tmp[i] && tab_tmp[i + 1] != NULL)
	{
		temp = (*stack_index)[j];
		(*stack_index)[j++] = ft_strdup_1(tab_tmp[i + 1]);
		free(temp);
		i++;
	}
	temp = (*stack_index)[j];
	(*stack_index)[j++] = ft_strdup_1(tab_tmp[0]);
	free(temp);
	temp = (*stack_index)[j];
	(*stack_index)[j] = NULL;
	free(temp);
}

void	rotaate_a(char ***stack_index, int size)
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
	rotaate_a_norme(stack_index, tab_tmp);
	i = 0;
	while (tab_tmp[i])
		free(tab_tmp[i++]);
	free(tab_tmp);
}

void	rotate_reeverse_a_norme(char ***stack_index,
		char **tab_tmp, int size, int i)
{
	char	*temp;
	int		j;

	j = 0;
	if (i > 0 && (*stack_index)[j] && tab_tmp[i - 1])
	{
		temp = (*stack_index)[j];
		(*stack_index)[j] = ft_strdup_1(tab_tmp[i - 1]);
		free(temp);
	}
	j++;
	i = 0;
	while (j < size - 1 && (*stack_index)[j])
	{
		temp = (*stack_index)[j];
		(*stack_index)[j] = ft_strdup_1(tab_tmp[i]);
		free(temp);
		j++;
		i++;
	}
	(*stack_index)[j] = NULL;
}

void	rotate_reeverse_a(char ***stack_index, int size)
{
	int		i;
	int		j;
	char	**tab_tmp;

	i = 0;
	tab_tmp = malloc(sizeof(char *) * (size + 1));
	while ((*stack_index)[i])
	{
		tab_tmp[i] = ft_strdup_1((*stack_index)[i]);
		i++;
	}
	tab_tmp[i] = NULL;
	j = 0;
	rotate_reeverse_a_norme(stack_index, tab_tmp, size, i);
	i = 0;
	while (tab_tmp[i])
		free(tab_tmp[i++]);
	free(tab_tmp);
}

void	swap_b(char ***stack_b)
{
	int	i;

	i = 0;
	if ((*stack_b)[0] && (*stack_b)[1])
		swap_nb(&(*stack_b)[0], &(*stack_b)[1]);
}

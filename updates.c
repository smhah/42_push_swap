/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:21:14 by smhah             #+#    #+#             */
/*   Updated: 2021/11/09 13:48:31 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup_1(const char *s)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	tmp = (char *)malloc(((len * sizeof(char)) + sizeof(char)));
	if (!tmp)
		return (0);
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

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

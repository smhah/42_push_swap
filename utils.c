/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:20:53 by smhah             #+#    #+#             */
/*   Updated: 2021/11/08 15:20:54 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	tmp = (char *)m_malloc(((len * sizeof(char)) + sizeof(char)), 0);
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

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

int	ft_strcmpr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	new_delete_top_value_norme(char ***tab, char **tab_tmp)
{
	int		k;
	int		i;
	char	*temp;

	k = 1;
	i = 0;
	while (tab_tmp[k])
	{
		temp = (*tab)[i];
		(*tab)[i] = ft_strdup_1(tab_tmp[k]);
		free(temp);
		i++;
		k++;
	}
	temp = (*tab)[i];
	(*tab)[i] = NULL;
	free(temp);
}

void	new_delete_top_value(char ***tab, int size)
{
	int		i;
	char	**tab_tmp;
	int		k;

	i = 0;
	k = 0;
	tab_tmp = malloc(sizeof(char *) * (size + 1));
	while ((*tab)[i])
	{
		tab_tmp[i] = ft_strdup_1((*tab)[i]);
		i++;
	}
	tab_tmp[i] = NULL;
	new_delete_top_value_norme(tab, tab_tmp);
	k = 0;
	while (tab_tmp[k])
		free(tab_tmp[k++]);
	free(tab_tmp);
}

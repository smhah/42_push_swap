/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:34:22 by macbook           #+#    #+#             */
/*   Updated: 2021/11/09 19:06:58 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

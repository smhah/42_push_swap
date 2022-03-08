/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:36:52 by nainhaja          #+#    #+#             */
/*   Updated: 2021/11/12 18:26:46 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_2(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((ft_strlen_2(s) * sizeof(char)) + 1);
	if (ptr == 0)
		return (0);
	else
	{
		while (s[i])
		{
			ptr[i] = s[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*s1;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = start;
	s1 = (char *)malloc(sizeof(char) * len + 1);
	if (s1)
	{
		if (i > (unsigned int)ft_strlen_2(s))
		{
			s1[j] = '\0';
			return (s1);
		}
		while (i < start + len)
		{
			s1[j] = s[i];
			i++;
			j++;
		}
		s1[j] = '\0';
		return (s1);
	}
	else
		return (0);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (c == '\0' && str[i] == c)
		return ((str + i));
	if (i == ft_strlen_2(str))
		return (0);
	ptr = (str + i);
	return (ptr);
}

size_t	ft_strlen_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

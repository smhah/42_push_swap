/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:17:13 by nainhaja          #+#    #+#             */
/*   Updated: 2021/11/12 18:23:16 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_remplir(char *s1, char *s2, char *ret)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	while (s1[i])
	{
		ret[k] = s1[i];
		k++;
		i++;
	}
	while (s2[j])
	{
		ret[k] = s2[j];
		j++;
		k++;
	}
	ret[k] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;

	ret = (char *)malloc(ft_strlen_2(s1) + ft_strlen_2(s2) + 1);
	if (ret)
	{
		ret = ft_remplir(s1, s2, ret);
		return (ret);
	}
	else
		return (0);
}

int	get_boucle(char **test, int *i, int fds)
{
	int		j;
	char	*temp;
	char	*buff;

	while (1)
	{
		buff = malloc(sizeof(char) * (100));
		j = read(fds, buff, 100);
		if (j == 0)
		{
			free(buff);
			return (0);
		}
		buff[j] = '\0';
		temp = *test;
		*test = ft_strjoin(*test, buff);
		free(temp);
		while (test[0][*i] != '\n' && test[0][*i] != '\0')
			*i = *i + 1;
		free(buff);
		if (test[0][*i] == '\n')
			break ;
	}
	return (1);
}

int	get_lastline(char **line, char **test)
{
	line[0] = ft_strdup_2(*test);
	free(*test);
	*test = NULL;
	return (0);
}

int	get_next_line(int fds, char **line)
{
	char		*temp;
	static char	*test;
	int			i;

	if (fds < 0 || read(fds, NULL, 0) != 0)
		return (-1);
	i = 0;
	if (!test)
		test = ft_strdup_2("");
	if (ft_strchr(test, '\n') == 0 && get_boucle(&test, &i, fds) == 0)
		return (get_lastline(line, &test));
	else
		while (test[i] != '\n')
			i++;
	line[0] = ft_substr(test, 0, i);
	temp = test;
	test = ft_strchr(test, '\n');
	if (*test == '\n')
	{
		test = ft_substr(test, 1, ft_strlen_2(test) - 1);
		free(temp);
	}
	return (1);
}

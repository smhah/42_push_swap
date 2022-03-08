/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:44:53 by smhah             #+#    #+#             */
/*   Updated: 2021/11/09 19:03:08 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

static int	ft_clen(int a)
{
	int	i;

	i = 0;
	if (a < 0)
		i++;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

static char	*ft_rev(char *s, int a, int len)
{
	int		i;
	char	tmp;

	i = 0;
	if (a < 0)
		i++;
	len--;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
	return (s);
}

static char	*ft_remplir(char *s, int a, int len)
{
	int				i;
	unsigned int	n;

	i = 0;
	if (a < 0)
	{
		s[i] = '-';
		i++;
		a = a * (-1);
	}
	n = a;
	while (i < len)
	{
		s[i] = (char)(n % 10) + 48;
		n = n / 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int a)
{
	int		len;
	char	*s;

	len = ft_clen(a);
	if (a != 0)
		s = (char *)m_malloc(sizeof(char) * (len + 1), 0);
	else
	{
		s = (char *)m_malloc(sizeof(char) * (len + 2), 0);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (s == 0)
		return (0);
	s = ft_remplir(s, a, len);
	s = ft_rev(s, a, len);
	return (s);
}

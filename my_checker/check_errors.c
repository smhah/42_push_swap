/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:03:50 by macbook           #+#    #+#             */
/*   Updated: 2021/11/12 18:27:21 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

int	check_double_number(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmpr(tab[i], tab[j]))
			{
				ft_putstr("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_not_digit(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			if (str[i] != '+' && str[i] != '-' && c == 0)
				return (1);
			else if (str[i] == '+' || str[i] == '-')
			{
				if (c > 0)
					return (1);
				c++;
			}
		}
		i++;
	}
	return (0);
}

int	check_is_digit(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (is_not_digit(tab[i]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_max_min_int(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strcmpr(tab[i], ft_itoa(atoi(tab[i]))) && tab[i][0] != '+')
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

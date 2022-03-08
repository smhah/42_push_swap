/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:21:44 by smhah             #+#    #+#             */
/*   Updated: 2021/11/09 19:02:58 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

int	condition(long result, int sign)
{
	if (result > 2147483648 && sign == -1)
		return (0);
	if (result > 2147483647 && sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && ((str[i] >= 8 && str[i] <= 13) || (str[i] == ' ')))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
		if ((result > 2147483647 && sign == 1)
			|| (result > 2147483648 && sign == -1))
			return (condition(result, sign));
	}
	return (result * sign);
}

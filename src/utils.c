/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianmarcogeek <gianmarcogeek@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:48:38 by gianmarcoge       #+#    #+#             */
/*   Updated: 2025/07/14 18:27:40 by gianmarcoge      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *error)
{
	return(write(2, error, ft_strlen(error)+1));
}

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	if(str != NULL)
	{
		while(str[len] != '\0')
			len++;
	}
	return (len);
}
static int	is_whitespace(char c)
{
	if (c == 32 || (c >= 8 && c <= 13))
		return(0);
	return(1); 
}
int ft_atoi(char *str)
{
	int num;
	int sign;
	int i;

	num = 0;
	sign = 1;
	i = 0;
	if(str != NULL)
	{
		while(is_whitespace(str[i]) == 0)
		{
			i++;
		}
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while(str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		{
			num *= 10;
			num += (str[i] - 48);
			i++;
		}
	}
	return(num * sign);
}

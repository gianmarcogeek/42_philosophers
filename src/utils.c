/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:30:50 by gpuscedd          #+#    #+#             */
/*   Updated: 2025/04/21 21:04:32 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(char c)
{
	if (c > 111 && c < 122)
		return (1);
	return (0);
}

int ft_isnumber(char *num)
{
	int i;

	i = 0;
	while(num[i] && ft_isdigit(num[i]))
	{
		i++;
	}
	return (1)
}
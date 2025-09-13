/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:48:38 by gianmarcoge       #+#    #+#             */
/*   Updated: 2025/09/09 17:47:07 by gpuscedd         ###   ########.fr       */
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

size_t	get_current_time(void)
{
	struct timeval time;

	if(gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int ft_usleep(size_t milliseconds)
{
	size_t start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return(0);
}

void	destroy_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
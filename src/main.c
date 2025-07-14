/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianmarcogeek <gianmarcogeek@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:43:31 by gianmarcoge       #+#    #+#             */
/*   Updated: 2025/07/14 18:19:42 by gianmarcoge      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_content(char *arg)
{
	int	i;
	i = 0;
	while(arg[i] != '\0')
	{
		if(arg[i] < '0' || arg[i] > '9')
			return(1);
		i++;
	}
	return(0);
}


int check_valid_args(char **argv)
{
	if(ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > PHILO_MAX
		|| check_arg_content(argv[1]) == 1)
		return(error_message("Invalid philosophers number\n"));
	if(ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return(error_message("Invalid time to die\n"));
	if(ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return(error_message("Invalid time to eat\n"));
	if(ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return(error_message("Invalid time to sleep\n"));
	if(argv[5] && (ft_atoi(argv[5]) <= 0 || check_arg_content(argv[5]) == 1))
		return(error_message("Invalid number of times each philosophers must eat\n"));
	return(0);
}

int	main(int argc, char **argv)
{
	// t_program	program;
	// t_philo		philos[PHILO_MAX];
	// pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return(error_message("Wrong amout of parameters\n"));
	if(check_valid_args(argv) == 1)
		return(1);
	return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@42roma.student.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:43:31 by gianmarcoge       #+#    #+#             */
/*   Updated: 2025/10/05 23:46:56 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *error)
{
	return (write(2, error, ft_strlen(error)+1));
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	check_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > PHILO_MAX
		|| check_number(argv[1]) == 1)
		return (error_message("Invalid philosophers number\n"));
	if (ft_atoi(argv[2]) <= 0 || check_number(argv[2]) == 1)
		return (error_message("Invalid time to die\n"));
	if (ft_atoi(argv[3]) <= 0 || check_number(argv[3]) == 1)
		return (error_message("Invalid time to eat\n"));
	if (ft_atoi(argv[4]) <= 0 || check_number(argv[4]) == 1)
		return (error_message("Invalid time to sleep\n"));
	if (argv[5] && (ft_atoi(argv[5]) <= 0 || check_number(argv[5]) == 1))
		return (error_message("Invalid number of times \
each philosophers must eat\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (error_message("Wrong amout of parameters\n"));
	if (check_args(argv) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	destroy_all(NULL, &program, forks);
	return (0);
}

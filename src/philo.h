/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianmarcogeek <gianmarcogeek@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:14:12 by gianmarcoge       #+#    #+#             */
/*   Updated: 2025/07/14 17:59:46 by gianmarcoge      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#	define PHILO_H
#	include <unistd.h>
#	include <stdio.h>
#	include <stdlib.h>
#	include <sys/time.h>
#	include <pthread.h>

#	define	PHILO_MAX 200

typedef	struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef	struct s_program
{
	int	dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo		*philos;
}	t_program;

//main

int	check_arg_content(char *arg);
int check_valid_args(char **argv);
void	destroy_all(char *str, t_program *program, pthread_mutex_t *forks);

//initialization

void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int philo_num);
void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **argv);
void	init_input(t_philo *philo, char **argv);

//threads
int		thread_create(t_program *program, pthread_mutex_t *forks);
void	*monitor(void *pointer);
void	*philo_routine(void *pointer);

//actions
void	eat(t_philo *philo);
void	dream(t_philo *philo);
void	think(t_philo *philo);

//monitor utils
int		dead_loop(t_philo *philo);
int		check_if_all_ate(t_philo *philos);
int		check_if_deatd(t_philo *philos);
int		philosopher_dead(t_philo *philo, size_t time_to_die);

//utils
int	ft_atoi(char *str);
int ft_usleep(size_t microseconds);
size_t	ft_strlen(char *str);
void	print_message(char *str, t_philo *philo, int id);
size_t	get_current_time(void);
int	error_message(char *error);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianmarcogeek <gianmarcogeek@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:57:22 by gianmarcoge       #+#    #+#             */
/*   Updated: 2025/09/03 17:09:29 by gianmarcoge      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_message(char *str, t_philo *philo, int id)
{
    size_t time;

    pthread_mutex_lock(philo->write_lock);
    time = get_current_time() - philo->start_time;
    if (!dead_loop(philo))
        printf("%zu %d %s\n", time, id, str);
    pthread_mutex_unlock(philo->write_lock);
}

int philosopher_dead(t_philo *philo, size_t time_to_die)
{
    pthread_mutex_lock(philo->meal_lock);
    if (get_current_time() - philo->last_meal >= time_to_die
        && philo->eating == 0)
        return(pthread_mutex_unlock(philo->meal_lock), 1);
    pthread_mutex_unlock(philo->meal_lock);
    return(0)
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:20:14 by gpuscedd          #+#    #+#             */
/*   Updated: 2025/04/21 20:42:01 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	if(argc < 5 || argc > 6)
	{
		write(2, "too/few parameters\n", 18);
		return (1);
	}
	int i;
	i = 1;
	while(i < argc)
	{
		i++;
	}
	printf("letsgo! %s\n", argv[0]);
	return (0);
}
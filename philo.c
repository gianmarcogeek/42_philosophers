#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	f
} t_philo;

void	say_hello(int id)
{
	printf("sono il philo n. %i\n", id);
}

int create_philos(int number_of_philosophers)
{
	t_philo *philos = malloc(number_of_philosophers * sizeof(*t_philo));
	int i = 0;
	while(i < number_of_philosophers)
	{
		philos[i]->id = i + 1;
		philos[i]->thread = pthread_create(&philos[i].thread, NULL, &say_hello, philos[i].id);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 5)
	{
		create_philos(atoi(argv[1]));
		return (0);
	}
	printf("Error! Wrong parameters.");
	return (1);
}
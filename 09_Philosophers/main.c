#include "philosophers.h"

void	*die_check(void *param)
{
	t_philo *philo;

	philo = param;
	while (1)
	{
		if (microtomilli() - philo->last_eat_time >= philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->data->print);
			printf("%ldms philo%d가 죽었다.\n", microtomilli() - philo->data->start_time, philo->idx);
			//pthread_mutex_unlock(&philo->data->print);
			philo->data->die_flag = 1;
			break;
		}
	}
	return (NULL);
}

void	*philo_process(void *param)
{
	t_data	*data;
	t_philo	*philo;
	pthread_t	pid;

	philo = param;
	data = philo->data;
	pthread_create(&pid, NULL, die_check, philo);
	//if (philo->idx % 2 == 1)
	//	usleep(300);
	while (1)
	{
		pick_fork(philo);
		if (data->die_flag == 1)
			break;
		meal_time(philo);
		if (data->die_flag == 1)
			break;
		sleep_time(philo);
		if (data->die_flag == 1)
			break;
		think_time(philo);
	}
	return (NULL);
}

int		philoshopers(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_create(
			&data->tid[i], NULL, philo_process, &philo[i]);
		//pthread_detach(data->tid[i]);
	}
	//while (data->die_flag == 0)
	//{
	//	//printf("안죽음\n");
	//	;
	//}
	return (0);
}

int		main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;

	if (init_data(&data, argc, argv) == -1)
	{
		printf("wrong number of arguments.\n");
		exit(0);
	}
	if (init_philo(&data, &philo))
	{
		printf("init philo error\n");
		exit(0);
	}
	if (init_thread(&data))
	{
		printf("init thread error\n");
		exit(0);
	}
	philoshopers(&data, philo);
	for (int i = 0; i < data.num_of_philos; i++)
		pthread_join(data.tid[i], NULL);
	return (0);
}
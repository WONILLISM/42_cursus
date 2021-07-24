#include "philosophers.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mid[philo->left_fork_idx - 1]);
	printf("%ldms philo%d가 포크를 잡았다.\n", microtomilli() - philo->data->start_time, philo->idx);
	pthread_mutex_lock(&philo->data->mid[philo->right_fork_idx - 1]);
	printf("%ldms philo%d가 포크를 잡았다.\n", microtomilli() - philo->data->start_time, philo->idx);
	printf("%ldms philo%d가 먹는 중이다.\n", microtomilli() - philo->data->start_time, philo->idx);
	ft_sleep(philo->data->time_to_eat, microtomilli());
	pthread_mutex_unlock(&philo->data->mid[philo->left_fork_idx - 1]);
	pthread_mutex_unlock(&philo->data->mid[philo->right_fork_idx - 1]);
}
//void	meal_time(t_philo *philo)
//{

//}
//void	sleep_time(t_philo *philo)
//{

//}
//void	think_time(t_philo *philo)
//{

//}

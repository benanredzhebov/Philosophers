/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:15:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/30 09:33:43 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	state_print(t_philo *phi, int id, char *color, char *status)
{
	long long	now;

	now = time_diff(phi->data->time);
	pthread_mutex_lock(&phi->data->print_mutex);
	pthread_mutex_lock(&phi->data->shared);
	if (phi->data->philo_died)
	{
		pthread_mutex_unlock(&phi->data->shared);
		pthread_mutex_unlock(&phi->data->print_mutex);
		return (0);
	}
	else
		printf("%s%-1lld %-1d %-1s%s\n", color, now, id, status, RESET);
	pthread_mutex_unlock(&phi->data->shared);
	pthread_mutex_unlock(&phi->data->print_mutex);
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	time_diff(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

/*convert it from milliseconds to microseconds*/
void	time_sim(long long time)
{
	usleep(time * 1000);
}

void	free_all(t_data *data, t_philo *phi)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
		pthread_mutex_destroy(data->my_mutex + i);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->shared);
	pthread_mutex_destroy(&data->tm);
	free(data->my_mutex);
	free(data);
	free(phi);
}

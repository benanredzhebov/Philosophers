/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:02:29 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/01 12:16:11 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*simulating philosopher picking up forks to eat*/
int	philo_eat(t_philo *phi)
{
	pthread_mutex_lock(&phi->data->my_mutex[phi->left_fork]);
	if (!state_print(phi, phi->id + 1, GREEN, FORK))
		return (drop_forks(phi, 1), 0);
	pthread_mutex_lock(&phi->data->my_mutex[phi->right_fork]);
	if (!state_print(phi, phi->id + 1, GREEN, FORK))
		return (drop_forks(phi, 2), 0);
	if (!state_print(phi, phi->id + 1, PURPLE, EAT))
		return (drop_forks(phi, 2), 0);
	pthread_mutex_lock(&phi->data->tm);
	// if ((phi->data->time_to_sleep < phi->data->time_to_eat) // prevent 4 410 200 200
	// 	|| (phi->time_to_die < \
	// 	(phi->data->time_to_eat + phi->data->time_to_sleep) \
	// 	|| phi->data->time_to_die == (phi->data->time_to_eat \
	// 	+ phi->data->time_to_sleep)))
	// 	phi->time_to_die = get_time();
	// else
		// phi->last_meal_time = get_time() + phi->data->time_to_eat;
	phi->time_to_die = get_time();
	pthread_mutex_unlock(&phi->data->tm);
	time_sim(phi->data->time_to_eat);
	drop_forks(phi, 2);
	pthread_mutex_lock(&phi->data->shared);
	phi->n_eaten++;
	pthread_mutex_unlock(&phi->data->shared);
	return (1);
}

/*simulates a philosopher sleeping*/
int	philo_sleep(t_philo *phi)
{
	if (!state_print(phi, phi->id + 1, BLUE, SLEEP))
		return (0);
	time_sim(phi->data->time_to_sleep);
	return (1);
}

int	philo_think(t_philo *phi)
{
	if (!state_print(phi, phi->id + 1, G_BLUE, THINK))
		return (0);
	return (1);
}

int	is_dead(t_philo *phi, int *i)
{
	long long	time;

	if (*i == phi[*i].data->num_of_philo)
	{
		*i = 0;
		usleep(200);
	}
	pthread_mutex_lock(&phi->data->tm);
	// time = time_diff(phi[*i].last_meal_time); //prevent 4 410 200 200
	time = time_diff(phi[*i].time_to_die);
	if (time > phi[*i].data->time_to_die)
	{
		pthread_mutex_unlock(&phi->data->tm);
		state_print(&phi[*i], phi[*i].id + 1, RED, DIED);
		pthread_mutex_lock(&phi->data->shared);
		phi[*i].data->philo_died = 1;
		pthread_mutex_unlock(&phi->data->shared);
		return (1);
	}
	pthread_mutex_unlock(&phi->data->tm);
	*i += 1;
	return (0);
}

void	drop_forks(t_philo *phi, int flag)
{
	pthread_mutex_unlock(&phi->data->my_mutex[phi->left_fork]);
	if (flag == 2)
		pthread_mutex_unlock(&phi->data->my_mutex[phi->right_fork]);
}

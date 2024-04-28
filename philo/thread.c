/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:46:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/28 11:27:19 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine2(void *args)
{
	t_philo	*phi;

	phi = args;
	if (phi->data->num_of_meals > 0)
		routine2_helper1(phi);
	else
		routine2_helper2(phi);
	return (NULL);
}

/*simulating a cycle of a philosopher's actions: eating, sleeping and
thinking.*/
int	simulation(t_philo *phi)
{
	if (!philo_eat(phi))
		return (0);
	if (phi->n_eaten != phi->data->num_of_meals)
	{
		if (!philo_sleep(phi))
			return (0);
		if (!philo_think(phi))
			return (0);
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*phi;

	phi = arg;
	if (phi->data->num_of_meals > 0)
		routine_helper1(phi);
	else
		routine_helper2(phi);
	return (NULL);
}

int	th_create(t_philo *phi)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&phi[i].data->shared, NULL))
		return (printf("Error: failed to initialize mutex\n"), 0);
	if (pthread_mutex_init(&phi[i].data->tm, NULL))
		return (printf("Error: failed to initialize mutex\n"), 0);
	if (pthread_create(&phi[0].data->monitor, NULL, routine2, phi))
		return (printf("Error: failed to create thread\n"), 0);
	usleep(2000);
	phi->data->time = get_time();
	while (i < phi->data->num_of_philo)
	{
		if (pthread_create(&phi[i].th, NULL, routine, &phi[i]))
			return (printf("Error: failed to create thread\n"), 0);
		i++;
		usleep(2000);
	}
	i = -1;
	while (++i < phi->data->num_of_philo)
		if (pthread_join(phi[i].th, NULL))
			return (printf("Error: failed to join thread\n"), 0);
	if (pthread_join(phi->data->monitor, NULL))
		return (printf("Error: failed to join thread\n"), 0);
	return (1);
}

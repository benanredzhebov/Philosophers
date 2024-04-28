/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:33:25 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/28 11:43:22 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*checking if a philosopher has eaten the required number of meals and if
they're still alive*/
void	routine2_helper1(t_philo *phi)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&phi->data->shared);
		if (phi[i].data->num_of_meals > phi[i].n_eaten \
			&& !phi[i].data->philo_died)
		{
			pthread_mutex_unlock(&phi->data->shared);
			if (is_dead(phi, &i))
				break ;
		}
		else
		{
			pthread_mutex_unlock(&phi->data->shared);
			break ;
		}
	}
}

/*this function is checking if a philosopher is still alive*/
void	routine2_helper2(t_philo *phi)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&phi->data->shared);
		if (!phi[i].data->philo_died)
		{
			pthread_mutex_unlock(&phi->data->shared);
			if (is_dead(phi, &i))
				break ;
		}
		else
		{
			pthread_mutex_unlock(&phi->data->shared);
			break ;
		}
	}
}

/*If the philosopher needs to eat more and is still alive, the function 
simulates the philosophers's actions*/
void	routine_helper1(t_philo *phi)
{
	while (1)
	{
		pthread_mutex_lock(&phi->data->shared);
		if ((phi->data->num_of_meals > phi->n_eaten) && !phi->data->philo_died)
		{
			pthread_mutex_unlock(&phi->data->shared);
			simulation(phi);
		}
		else
		{
			pthread_mutex_unlock(&phi->data->shared);
			break ;
		}
	}
}

/*checking if a philosopher is still alive.
if it's alive, simlulates the philisopher's actions.
if the simulation fails, the function breaks its loop.
if it's dead, the function breaks the loop.
*/
void	routine_helper2(t_philo *phi)
{
	while (1)
	{
		pthread_mutex_lock(&phi->data->shared);
		if (!phi->data->philo_died)
		{
			pthread_mutex_unlock(&phi->data->shared);
			if (!simulation(phi))
				break ;
		}
		else
		{
			pthread_mutex_unlock(&phi->data->shared);
			break ;
		}
	}
}

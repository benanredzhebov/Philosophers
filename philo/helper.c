/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:33:25 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/17 11:04:05 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

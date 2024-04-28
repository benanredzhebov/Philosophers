/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:43:01 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/28 13:58:31 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv, int argc)
{
	int	i;

	data->philo_died = 0;
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_meals = ft_atoi(argv[5]);
	else
		data->num_of_meals = -1;
	if (!data->num_of_philo || !data->time_to_die || !data->time_to_eat || \
		!data->time_to_sleep || (argc == 6 && !data->num_of_meals))
		return (printf("Error: some arguments are zero or out bound\n"), 0);
	data->my_mutex = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->my_mutex)
		return (printf("Error: memory allocation failed\n"), 0);
	i = 0;
	while (i < data->num_of_philo)
		if (pthread_mutex_init(data->my_mutex + i++, NULL))
			return (printf("Error: failed to initialize mutex\n"), 0);
	if (pthread_mutex_init(&data->print_mutex, NULL))
		return (printf("Error: failed to initialize mutex\n"), 0);
	return (1);
}

void	init_philo(t_philo *phi, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		phi[i].id = i;
		phi[i].n_eaten = 0;
		phi[i].time_to_die = data->time_to_die;
		phi[i].last_meal_time = get_time();
		phi[i].left_fork = i;
		phi[i].right_fork = (i + 1) % data->num_of_philo;
		phi[i].data = data;
		i++;
	}
	phi[i].time_to_die = data->time_to_die;
	phi[i].n_eaten = 0;
	phi[i].data = data;
	phi[i].last_meal_time = get_time();
}

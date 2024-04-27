/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:16:52 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/27 09:44:22 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Simulating dinning Philosophers problem */
int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*phi;

	if (!checks(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("Error: memory allocation failed\n"), 2);
	if (!init_data(data, argv, argc))
		return (3);
	phi = malloc(sizeof(t_philo) * (data->num_of_philo + 1));
	if (!phi)
		return (printf("Error: memory allocation failed\n"), 4);
	init_philo(phi, data);
	if (data->num_of_philo == 1)
	{
		one_philo(data, phi);
		return (0);
	}
	if (!th_create(phi))
		return (free_all(data, phi), 6);
	free_all(data, phi);
	return (0);
}

void	one_philo(t_data *data, t_philo *phi)
{
	data->time = get_time();
	state_print(phi, 1, GREEN, FORK);
	time_sim(data->time_to_die);
	state_print(phi, 1, RED, DIED);
	free_all(data, phi);
}

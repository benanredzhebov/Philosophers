/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hiring_workers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:38:58 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/04 12:00:55 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// This function represents the routine (task) our workers (threads) will execute.
void *worker_routine(void *arg)
{
	// All workers (threads) inside the factory (process) will print the same address (PID)
	printf("Worker ID->%lu: My factory's address (PID) is %d\n", (unsigned long)pthread_self(), getpid());
	return (NULL);
}

int	main(void)
{
	pthread_t worker1;
	pthread_t worker2;
	// Let's create two workers (threads) in the same factory (process) .
	// Hiring (creating) the first worker.
	if (pthread_create(&worker1, NULL, worker_routine, NULL) != 0)
		return (1);
	// Hiring (creating) the second worker.
	if (pthread_create(&worker2, NULL, worker_routine, NULL) != 0)
		return (2);
	// Wait for both workers to finish their shift (tasks)
	pthread_join(worker1, NULL);
	pthread_join(worker2, NULL);
	return (0);
}
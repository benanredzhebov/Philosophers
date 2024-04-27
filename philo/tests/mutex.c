/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:17:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/16 17:41:19 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2

int counter = 0;
pthread_mutex_t lock; // Mutex lock

void *increment(void *arg)
{
	int	i = 0;
	while(i < 1000000)
	{
		pthread_mutex_lock(&lock); // Acquire the lock before accessing critical section
		counter++;
		i++;
		pthread_mutex_unlock(&lock); // Release the lock after accessing critical section
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
	int i;

	pthread_mutex_init(&lock, NULL); // Initialize the mutex lock

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, increment, NULL);
	}

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("Counter value: %d\n", counter);

	pthread_mutex_destroy(&lock); // Destroy the mutex lock

	return 0;
}
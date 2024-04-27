/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_coffe_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:02:11 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/01 18:42:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void	*make_coffee(void *data)
{
	//Print which barista is preparing the drink.
printf("Barista preparing coffee\n");

// Simulate the time taken to prepare a drink.
sleep(20);

// Notify when the drink is ready.
printf("coffee ready!\n");
return (NULL);
}



int	main()
{
	pthread_t	baristas[500];

	for (int i = 0; i < 500; ++i)
	{
		if (pthread_create(baristas + i, NULL, make_coffee, NULL))
			exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < 500; ++i)
	{
		printf("Identifier-> %lu\n", (unsigned long) baristas[i]);
	}
	
	for (int i = 0; i < 500; ++i)
		pthread_join(baristas[i], NULL);

}
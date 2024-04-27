/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_coffe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:57:14 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/01 18:20:06 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	make_coffe(char *name)
{
	printf("Barista and %s is making coffee...\n", name); //format:
	sleep(3);
	printf("coffee ready!\n"); //format:
}

int	main()
{
	make_coffe("Luca"); //name:
	make_coffe("Paolo"); //name:
}

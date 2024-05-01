/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:26:48 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/01 12:22:58 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h> // mutex: init destroy lock unlock, threads: create join
# include <sys/time.h> // gettimeofday#endif

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define RED "\033[0;31m"
# define PINK "\e[0;38;5;199m"
# define RESET "\033[0m"

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_data
{
	int				num_of_philo; // The number of philosophers.
	int				time_to_die; // The time a philosopher will die after starting to eat.
	int				time_to_eat; // The time it takes for a philosopher to eat.
	int				time_to_sleep; // The time a philosopher sleeps after eating.
	int				num_of_meals; // The number of meals each philosopher must eat.
	int				philo_died; // A flag indicating if a philosopher has died.
	long long		time; // The start time of the simulation.
	pthread_t		monitor; // A thread used to monitor the philosophers.
	pthread_mutex_t	*my_mutex; // An array of mutexes, one for each fork.
	pthread_mutex_t	print_mutex; // A mutex used to synchronize printing.
	pthread_mutex_t	shared; // A mutex used to synchronize shared data. For example only one philosopher at a time can update the number of meals they have eaten.
	pthread_mutex_t	tm; // A mutex used to synchronize time.
}					t_data;

typedef struct s_philo
{
	int				id; // The philosopher's id.
	long long		time_to_die; // The time at which the philosopher last ate.
	// long long		last_meal_time; // The time at which the philosopher last ate.
	int				n_eaten; // The number of times the philosopher has eaten.
	int				left_fork; // The id of the fork to the philosopher's left.
	int				right_fork; // The id of the fork to the philosopher's right.
	t_data			*data; // a pointer to the shared data structure.
	pthread_t		th; // The philosopher's thread.
}					t_philo;

int			ft_isdigit(int n);
int			philo_eat(t_philo *phi);
int			simulation(t_philo *phi);
int			th_create(t_philo *phi);
int			ft_atoi(const char *str);
int			ft_iscorrect(char **str);
int			checks(int argc, char **argv);
int			init_data(t_data *data, char **argv, int argc);
int			state_print(t_philo *phi, int id, char *color, char *status);
int			philo_sleep(t_philo *phi);
int			philo_think(t_philo *phi);
int			is_dead(t_philo *phi, int *i);
void		*routine(void *arg);
void		init_philo(t_philo *phi, t_data *data);
void		time_sim(long long time);
void		drop_forks(t_philo *phi, int flag);
void		*routine2(void *args);
long long	time_diff(long long time);
long long	get_time(void);
void		one_philo(t_data *data, t_philo *phi);
void		free_all(t_data *data, t_philo *phi);
void		routine2_helper1(t_philo *phi);
void		routine2_helper2(t_philo *phi);
void		routine_helper1(t_philo *phi);
void		routine_helper2(t_philo *phi);

#endif